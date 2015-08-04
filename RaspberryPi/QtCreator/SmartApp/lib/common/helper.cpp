#include "helper.h"

Helper::Helper()
{
}


void Helper::print(QString sData) {
    qDebug() << sData;
}

void Helper::print(int iData) {
    qDebug() << QString::number(iData);
}

void Helper::print(long iData) {
    qDebug() << QString::number(iData);
}

void Helper::print(int8 * aData, int uDataLen) {
    QByteArray qaData = QByteArray(aData,uDataLen);
    qDebug() << qaData.toHex();
}

void Helper::print(uint8 * aData, int uDataLen) {
    //int8 aBuff[uDataLen];
    //memcpy(aBuff,aData,aDataLen);
    QByteArray qaData = QByteArray((int8*)aData,uDataLen);
    qDebug() << qaData.toHex();
}
