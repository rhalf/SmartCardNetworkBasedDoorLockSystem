#include "pcscexception.h"

PcscException::PcscException(int32 iErrorNumber)
{
    char * aResult = pcsc_stringify_error(iErrorNumber);
    _sErrorMessage = QString(aResult);
}

PcscException::PcscException(QString sErrorMessage)
{
    _sErrorMessage = sErrorMessage;
}

int32 PcscException::getErrorNumber() {
    return _iErrorNumber;
}

QString PcscException::getErrorMessage(){
    return _sErrorMessage;
}
