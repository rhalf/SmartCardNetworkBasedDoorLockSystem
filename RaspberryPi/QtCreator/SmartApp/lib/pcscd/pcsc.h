#ifndef PCSC_H
#define PCSC_H

#include "lib/common/includes.h"

#ifdef __cplusplus
extern "C" {
#include "lib/pcscd/winscard.h"
#include "lib/pcscd/pcsclite.h"
#include "lib/pcscd/reader.h"
}
#endif //__cplusplus

typedef SCARDCONTEXT PcscContext;
typedef SCARDHANDLE PcscCard;

class Pcsc
{

public:

    Pcsc();

    void establishContent();
    QStringList listReaders();
    PcscCard connect(QString sReader);
    void transmit(PcscCard hCard, uint8 * aCmd, uint32 uCmdLen, uint8 * aResp, uint32 *uRespLen);
    void disconnect(PcscCard hCard);
    void releaseContext();

    boolean checkCard (QString sReader);


private:

    uint32 iReturnValue;
    QStringList slReaders;
    PcscContext hContext;

    SCARD_IO_REQUEST pioSendPci;
    SCARD_IO_REQUEST pioRecvPci;



};

#endif // PCSC_H
