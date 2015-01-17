#include "pcsc.h"

Helper cHelper;

Pcsc::Pcsc()
{

}

void Pcsc::establishContent() {

    iReturnValue = SCardEstablishContext(SCARD_SCOPE_SYSTEM,
                                         NULL,
                                         NULL,
                                         &hContext);
    if (iReturnValue) {
        throw PcscException(iReturnValue);
    }
}

QStringList Pcsc::listReaders() {

    QString sReader;
    DWORD dwReadersLen;
    int8 * aReaderList;
    slReaders.clear();

    iReturnValue = SCardListReaders(hContext,
                                    NULL,
                                    NULL,
                                    &dwReadersLen);
    if (iReturnValue) {
        throw PcscException(iReturnValue);
    }

    aReaderList = new int8[dwReadersLen];

    if (aReaderList == NULL)
    {
        throw PcscException("Insufficient Memory");
    }

    iReturnValue = SCardListReaders(hContext,
                                    NULL,
                                    (LPSTR)aReaderList,
                                    &dwReadersLen);
    if (iReturnValue) {
        throw PcscException(iReturnValue);
    }


    for(int iIndex = 0; iIndex < (int) dwReadersLen; iIndex++) {

        if (aReaderList[iIndex]== (int8) 0x00) {
            slReaders.append(sReader);
            sReader = "";
        } else {
            sReader += aReaderList[iIndex];
        }

    }

     slReaders.removeLast();

    delete [] aReaderList;

    return slReaders;
}

PcscCard Pcsc::connect(QString sReader) {
    PcscCard hCard;
    if (sReader == NULL || sReader == "") {
        throw PcscException("No reader selected");
    }

    uint32 dwActiveProtocol;

    iReturnValue = SCardConnect(hContext,
                                sReader.toUtf8().constData(),
                                SCARD_SHARE_SHARED,
                                SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1,
                                &hCard,
                                &dwActiveProtocol);
    if (iReturnValue) {
        throw PcscException(iReturnValue);
    }

    pioSendPci.dwProtocol = dwActiveProtocol;
    pioSendPci.cbPciLength = 256;
    pioRecvPci.dwProtocol = dwActiveProtocol;
    pioRecvPci.cbPciLength = 256;

    return hCard;
}

void Pcsc::transmit(PcscCard hCard, uint8 * aCmd, uint32 uCmdLen, uint8 * aResp, uint32 * uRespLen) {
    *uRespLen = 256;
    iReturnValue = SCardTransmit(hCard,
                                 &pioSendPci,
                                 aCmd,
                                 uCmdLen,
                                 NULL,
                                 aResp,
                                 uRespLen);
    if (iReturnValue) {
        throw PcscException(iReturnValue);
    }
}

void Pcsc::disconnect(PcscCard hCard) {
    uint32 dwDisposition = 0;
    iReturnValue = SCardDisconnect(hCard, dwDisposition);
    if (iReturnValue) {
        throw PcscException(iReturnValue);
    }
}

void Pcsc::releaseContext() {
    iReturnValue = SCardReleaseContext(hContext);
    if (iReturnValue) {
        throw PcscException(iReturnValue);
    }
}

boolean Pcsc::checkCard(QString sReader) {

    SCARD_READERSTATE readerState[1];
    int32 iReaders = 1;

    readerState[0].szReader = sReader.toUtf8().constData();
    readerState[0].dwCurrentState = SCARD_STATE_UNAWARE;
    iReturnValue = SCardGetStatusChange(hContext,0,readerState,iReaders);

    if (iReturnValue) {
        throw PcscException(iReturnValue);
    }

    if ((readerState[0].dwEventState & SCARD_STATE_PRESENT ) == SCARD_STATE_PRESENT) {
        return true;
    }

    if ((readerState[0].dwEventState & SCARD_STATE_EMPTY) == SCARD_STATE_EMPTY) {
        return false;
    }

    return false;
}

