#ifndef HELPER_H
#define HELPER_H

#include "lib/common/includes.h"

class Helper
{
public:
    Helper();

    void print(QString sData);
    void print(int iData);
    void print(long iData);
    void print(int8 *aData, int uDataLen);
    void print(uint8 * aData, int uDataLen);
};

#endif // HELPER_H
