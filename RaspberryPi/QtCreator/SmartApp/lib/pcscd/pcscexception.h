#ifndef PCSCEXCEMPTION_H
#define PCSCEXCEMPTION_H

#include <lib/common/includes.h>

#ifdef __cplusplus
extern "C" {
#include "lib/pcscd/winscard.h"
#include "lib/pcscd/pcsclite.h"
#include "lib/pcscd/reader.h"
}
#endif //__cplusplus

class PcscException
{
public:
    PcscException(int32 iErrorNumber);
    PcscException(QString sErrorMessage);

    int32 getErrorNumber();
    QString getErrorMessage();

private:
    int32 _iErrorNumber;
    QString _sErrorMessage;
};



#endif // PCSCEXCEMPTION_H
