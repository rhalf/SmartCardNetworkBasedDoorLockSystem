#include "connector.h"

extern Helper _cHelper;

Connector::Connector() {
    pProcess = new QProcess();
}

Connector::~Connector() {
    delete pProcess;
}

int Connector::checkCardSerialIsAllowed(QString sCardSerial) {
    pProcess->start("lib/mysql/user", QStringList() << "select" << sCardSerial);
    pProcess->waitForFinished();
    QString sResult = pProcess->readAllStandardOutput();


    if (pProcess->exitCode()!=0 || pProcess->exitStatus()!=0) {
        return 1;
    }

    if (sResult==NULL) {
        return 1;
    }

    QStringList slData = sResult.split("\t");
    QString sBuffer(slData[3]);

    if (strcmp(sBuffer.toUtf8().constData(),"Allowed")==0) {
        _cHelper.print(sResult);
        return 0;
    }
    return 1;
}

int Connector::getLogs(QStringList * slLogs) {
    pProcess->start("lib/mysql/logs", QStringList() << "select" << "all");
    pProcess->waitForFinished();
    QString sResult = pProcess->readAllStandardOutput();


    if (pProcess->exitCode()!=0 || pProcess->exitStatus()!=0) {
        return 1;
    }

    if (sResult==NULL) {
        return 1;
    }


    *slLogs = sResult.split("\n");

    return 0;

}

int Connector::setLogs(QStringList slLogs) {
    QStringList slData;
    slData << "insert";
    slData << slLogs[0];
    slData << slLogs[2];
    slData << slLogs[3];

    pProcess->start("lib/mysql/logs", slData);
    pProcess->waitForFinished();
    QString sResult = pProcess->readAllStandardOutput();


    if (pProcess->exitCode()!=0 || pProcess->exitStatus()!=0) {
        return 1;
    }

    if (sResult==NULL) {
        return 1;
    }
    return 0;
}

int Connector::getUsers(QStringList *slUsers) {
    QStringList slData;
    slData << "select";
    slData << "all";

    pProcess->start("lib/mysql/user", slData);
    pProcess->waitForFinished();
    QString sResult = pProcess->readAllStandardOutput();


    if (pProcess->exitCode()!=0 || pProcess->exitStatus()!=0) {
        return 1;
    }

    if (sResult==NULL) {
        return 1;
    }

    *slUsers = sResult.split("\n");

    return 0;

}

int Connector::releaseDoor(int iTime) {
//    pProcess->start("sudo python", QStringList() << "lib/python/releaseDoor.py" << QString::number(iTime));
//    pProcess->waitForFinished();
//    QString sResult = pProcess->readAllStandardOutput();


//    if (pProcess->exitCode()!=0 || pProcess->exitStatus()!=0) {
//        return 1;
//    }

    return system("sudo python lib/python/releaseDoor.py 5 &");
}

int Connector::activateAlarm(int iTime) {
    //pProcess->start("sudo python", QStringList() << "lib/python/releaseAlarm.py"<< QString::number(iTime));
    //pProcess->waitForFinished();
    //QString sResult = pProcess->readAllStandardOutput();


    //if (pProcess->exitCode()!=0 || pProcess->exitStatus()!=0) {
    //    return 1;
    //}



    return system("sudo python lib/python/activateAlarm.py 5 &");
}

int Connector::updateUser(QString sCardSerial,QString sCardUserName, QString sStatus ) {
    QStringList slData;

    slData << "update";
    slData << sCardSerial;
    slData << sCardSerial;
    slData << sCardUserName;
    slData << sStatus;

    pProcess->start("lib/mysql/user", slData);
    pProcess->waitForFinished();
    QString sResult = pProcess->readAllStandardOutput();


    if (pProcess->exitCode()!=0 || pProcess->exitStatus()!=0) {
        return 1;
    }

    if (sResult==NULL) {
        return 1;
    }

    return 0;

}

int Connector::sendSms(QString sMobile, QString sMessage) {

    QString sCmd = "sudo python lib/python/sendSms.py " + sMobile + " " + sMessage + " &";


    if (sMobile.isEmpty() || sMessage.isEmpty()) {
        return 1;
    }

    return system(sCmd.toUtf8().constData());
}

int Connector::sAddUser(QString sCardSerial,QString sCardUserName, QString sStatus ) {
    QStringList slData;

    slData << "sInsert";
    slData << sCardSerial;
    slData << sCardUserName;
    slData << sStatus;

    pProcess->start("lib/mysql/user", slData);
    pProcess->waitForFinished();
    QString sResult = pProcess->readAllStandardOutput();


    if (pProcess->exitCode()!=0 || pProcess->exitStatus()!=0) {
        return 1;
    }

    if (sResult==NULL) {
        return 1;
    }

    return 0;

}

int Connector::truncateUser() {
    QStringList slData;

    slData << "truncate";

    pProcess->start("lib/mysql/user", slData);
    pProcess->waitForFinished();
    QString sResult = pProcess->readAllStandardOutput();


    if (pProcess->exitCode()!=0 || pProcess->exitStatus()!=0) {
        return 1;
    }

    if (sResult==NULL) {
        return 1;
    }

    return 0;
}

int Connector::truncateLogs() {
    QStringList slData;

    slData << "truncate";

    pProcess->start("lib/mysql/logs", slData);
    pProcess->waitForFinished();
    QString sResult = pProcess->readAllStandardOutput();


    if (pProcess->exitCode()!=0 || pProcess->exitStatus()!=0) {
        return 1;
    }

    if (sResult==NULL) {
        return 1;
    }

    return 0;
}
