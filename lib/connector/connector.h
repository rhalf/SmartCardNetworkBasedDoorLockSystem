#ifndef CONNECTOR_H
#define CONNECTOR_H

#include "lib/common/includes.h"

class Connector
{
public:

    QProcess * pProcess;

    Connector();
    ~Connector();

    int checkCardSerialIsAllowed(QString sCardSerial);
    int getLogs(QStringList *slLogs);
    int setLogs(QStringList slLogs);
    int getUsers(QStringList *slUsers);
    int releaseDoor(int iTime);
    int activateAlarm(int iTime);
    int updateUser(QString sCardSerial,QString sCardUserName, QString sStatus );
    int sendSms(QString sMobile, QString sMessage);
    int sAddUser(QString sCardSerial,QString sCardUserName, QString sStatus );
    int truncateLogs();
    int truncateUser();
};

#endif // CONNECTOR_H
