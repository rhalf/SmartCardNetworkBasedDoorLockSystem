#include "mainwindow.h"
#include "ui_mainwindow.h"

Pcsc _cPcsc;
Helper _cHelper;

int32 iReturnValue = 0;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->menuBar->setNativeMenuBar(false);

    timerPolling.setInterval(10);
    QObject::connect(&timerPolling,SIGNAL(timeout()),this,SLOT(cardPolling()));
}

MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::connectCard(QString sReader, int iType) {

    try {

        hCard = _cPcsc.connect(sReader);
        _cHelper.print("Connect,Ok");
        uint8 aCmd[256];
        uint32 uCmdLen = 11;
        uint8 aResp[256];
        uint32 uRespLen = 256;
        QStringList slData;

        //Load Key
        memcpy(aCmd,"\xFF\x82\x00\x00\x06\xFF\xFF\xFF\xFF\xFF\xFF",11);
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
        _cHelper.print(aResp,uRespLen);

        //Authenticate
        memcpy(aCmd,"\xFF\x86\x00\x00\x05\x01\x00\x00\x60\x00",10);
        uCmdLen = 10;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
         _cHelper.print(aResp,uRespLen);

        //Read Card Serial
        memcpy(aCmd,"\xFF\xB0\x00\x00\x10",5);
        uCmdLen = 5;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
        _cHelper.print(aResp,uRespLen);

        QString sCardSerialNumber = QByteArray((const char*)aResp,(int)uRespLen).toHex();

        //Authenticate
        memcpy(aCmd,"\xFF\x86\x00\x00\x05\x01\x00\x04\x60\x00",10);
        uCmdLen = 10;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
        _cHelper.print(aResp,uRespLen);

        QString sName;
        //Read Card Fname
        memcpy(aCmd,"\xFF\xB0\x00\x04\x10",5);
        uCmdLen = 5;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
        _cHelper.print(aResp,uRespLen);

        sName = QString::fromLocal8Bit(QByteArray((char*)aResp,uRespLen));

        //Read Card Lname
        memcpy(aCmd,"\xFF\xB0\x00\x05\x10",5);
        uCmdLen = 5;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
        _cHelper.print(aResp,uRespLen);

        sName.append(" " + QString::fromLocal8Bit(QByteArray((char*)aResp,uRespLen)));

        //Door and Alarm
        Connector cConnector;
        int iAccountStatus = cConnector.checkCardSerialIsAllowed(sCardSerialNumber);

        if(iAccountStatus) {
            cConnector.activateAlarm(5);
        } else {
            cConnector.releaseDoor(5);
        }

        //Logs
        slData << sCardSerialNumber;
        slData << sName;
        slData << QDateTime::currentDateTime().toString();
        slData << (iType ? "OUT": "IN");
        slData << (iAccountStatus ? "Restricted" : "Allowed");

        addItemsToLogs(slData);
        cConnector.setLogs(slData);

        QCoreApplication::processEvents();

        //Sms Notification
        QString sTextMessage;
        sTextMessage = "==Mobile\\ Notification==\\ ";
        sTextMessage += "CardSerial:\\ ";
        sTextMessage += sCardSerialNumber + ",\\ ";
        sTextMessage += "Name:\\ ";
        sName = sName.replace(" ","\\ ");
        sTextMessage += sName + ",\\ ";
        sTextMessage += "Type:\\ ";
        sTextMessage += slData[3] + ",\\ ";
        sTextMessage += "Entry\\ Status:\\ ";
        sTextMessage += slData[4];

        if (!ui->lineEditMobileNumber->text().isEmpty()) {
            cConnector.sendSms(ui->lineEditMobileNumber->text(),sTextMessage);
        } else {
            ui->textEditDebug->append("Admin Mobile Number is empty.");
        }

    } catch (PcscException cException) {
        _cHelper.print(cException.getErrorMessage());
        ui->textEditDebug->append(cException.getErrorMessage());
    } catch (std::exception cStdException) {
        _cHelper.print("Error!");
    }
}

void MainWindow::addItemsToLogs(QStringList slData) {

    ui->tableWidgetLogs->insertRow(0);

    QTableWidgetItem *item0 = new QTableWidgetItem;
    item0->setText(slData[0]);

    QTableWidgetItem *item1 = new QTableWidgetItem;
    item1->setText(slData[1]);

    QTableWidgetItem *item2 = new QTableWidgetItem;
    item2->setText(slData[2]);

    QTableWidgetItem *item3 = new QTableWidgetItem;
    item3->setText(slData[3]);

    QTableWidgetItem *item4 = new QTableWidgetItem;
    item4->setText(slData[4]);

    ui->tableWidgetLogs->setItem(0, 0, item0);
    ui->tableWidgetLogs->setItem(0, 1, item1);
    ui->tableWidgetLogs->setItem(0, 2, item2);
    ui->tableWidgetLogs->setItem(0, 3, item3);
    ui->tableWidgetLogs->setItem(0, 4, item4);
}

void MainWindow::addItemsToUser(QStringList slData) {

    ui->tableWidgetUser->insertRow(0);


    QTableWidgetItem *item0 = new QTableWidgetItem;
    item0->setText(slData[0]);
    item0->setFlags(item0->flags() & ~Qt::ItemIsEditable);


    QTableWidgetItem *item1 = new QTableWidgetItem;
    item1->setText(slData[1]);
    item1->setFlags(item1->flags() & ~Qt::ItemIsEditable);

    QTableWidgetItem *item2 = new QTableWidgetItem;

    Qt::CheckState eCheckState = (slData[2]=="Allowed"?Qt::Checked:Qt::Unchecked);
    item2->setCheckState(eCheckState);
    item2->setText(slData[2]);

    ui->tableWidgetUser->setItem(0, 0, item0);
    ui->tableWidgetUser->setItem(0, 1, item1);
    ui->tableWidgetUser->setItem(0, 2, item2);

}

void MainWindow::clearItemsToLogs() {
    ui->tableWidgetLogs->clearContents();
    ui->tableWidgetLogs->setRowCount(1);
}

void MainWindow::clearItemsToUser() {
    ui->tableWidgetUser->clearContents();
    ui->tableWidgetUser->setRowCount(1);

}

void MainWindow::disconnectCard(PcscCard hCard) {

    try{
        _cPcsc.disconnect(hCard);
        _cHelper.print("Disconnect,Ok");
    } catch (PcscException cException) {
        _cHelper.print(cException.getErrorMessage());
    }
}

void MainWindow::cardPolling() {

    boolean bCheckCard = false;
    QString sReader;
    static boolean bRunOnce = false;
    int iIndex;
    for (iIndex = 0; iIndex < slPollReaders.size(); iIndex++) {
        sReader = slPollReaders[iIndex];
        if (_cPcsc.checkCard(sReader)) {
            bCheckCard = _cPcsc.checkCard(sReader);
            if (bCheckCard) {
                //_cHelper.print("Card is present on " + sReader);
                break;
            }
        }
    }

    if (bCheckCard == true && bRunOnce == false) {
        _cHelper.print("connectCard()");
        connectCard(sReader, iIndex);
        bRunOnce = true;
    } else if (bCheckCard == true && bRunOnce == true) {
        //do nothing
    } else if (bCheckCard == false && bRunOnce == true) {
        _cHelper.print("disconnectCard()");
        disconnectCard(hCard);
        bRunOnce = false;
    } else if (bCheckCard == false && bRunOnce == false) {
        //do nothing
    }

}

void MainWindow::on_actionExit_triggered() {
    this->close();
}

void MainWindow::on_actionInitialize_triggered()
{
    try {
        _cPcsc.establishContent();
        _cHelper.print("EstablishContext,Ok");
        slReaders = _cPcsc.listReaders();
        _cHelper.print("ListReaders,Ok");
        for (uint8 uIndex = 0; uIndex < slReaders.size(); uIndex++) {
            _cHelper.print(slReaders[uIndex]);
        }

        //add to combo box
        ui->comboBoxReaderIn->clear();
        ui->comboBoxReaderOut->clear();

        ui->comboBoxReaderIn->addItems(slReaders);
        ui->comboBoxReaderOut->addItems(slReaders);


        timerPolling.start();
        _cHelper.print("Timer Start,Ok");

    } catch (PcscException cException) {
        _cHelper.print(cException.getErrorMessage());
    }
}

void MainWindow::on_actionReset_triggered()
{
    timerPolling.stop();
    _cHelper.print("Timer Stop,Ok");

    try {
        _cPcsc.releaseContext();
        _cHelper.print("ReleaseContext,Ok");
    } catch (PcscException cException) {
        _cHelper.print(cException.getErrorMessage());
    }
}

void MainWindow::on_comboBoxReaderIn_currentIndexChanged(const QString &arg1)
{
    QString arg2 = arg1;
    slPollReaders.clear();
    slPollReaders.append(ui->comboBoxReaderIn->currentText());
    slPollReaders.append(ui->comboBoxReaderOut->currentText());
}

void MainWindow::on_comboBoxReaderOut_currentIndexChanged(const QString &arg1)
{
    QString arg2 = arg1;
    slPollReaders.clear();
    slPollReaders.append(ui->comboBoxReaderIn->currentText());
    slPollReaders.append(ui->comboBoxReaderOut->currentText());
}


void MainWindow::on_pushButtonApply_clicked()
{
    int iRowCount = ui->tableWidgetUser->rowCount();

    Connector cConnector;

    for (int iIndex = 0; iIndex <  iRowCount -1; iIndex++) {

        cConnector.updateUser(
                    ui->tableWidgetUser->item(iIndex,0)->text(),
                    ui->tableWidgetUser->item(iIndex,1)->text(),
                    QString(ui->tableWidgetUser->item(iIndex,2)->checkState() ? "Allowed":"Restricted")
                            );
    }
}

void MainWindow::on_pushButtonSendSms_clicked()
{
   Connector cConnect;

   if (ui->lineEditMobileNumber->text().isEmpty()) {
       QMessageBox msg;
       msg.setText("Admin Mobile Number is empty.");
       msg.exec();
       return;
   }
   cConnect.sendSms(ui->lineEditMobileNumber->text(),"Testing...");
}

void MainWindow::on_pushButtonCheckCard_clicked()
{
    try {
        uint8 aCmd[256];
        uint32 uCmdLen = 11;
        uint8 aResp[256];
        uint32 uRespLen = 256;
        QStringList slData;

        //Load Key
        memcpy(aCmd,"\xFF\x82\x00\x00\x06\xFF\xFF\xFF\xFF\xFF\xFF",11);
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
        _cHelper.print(aResp,uRespLen);

        //Authenticate
        memcpy(aCmd,"\xFF\x86\x00\x00\x05\x01\x00\x00\x60\x00",10);
        uCmdLen = 10;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
         _cHelper.print(aResp,uRespLen);

        //Read Card Serial
        memcpy(aCmd,"\xFF\xB0\x00\x00\x10",5);
        uCmdLen = 5;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
        _cHelper.print(aResp,uRespLen);

        QString sCardSerialNumber = QByteArray((const char*)aResp,(int)uRespLen).toHex();
        ui->lineEditCardSerial->setText(sCardSerialNumber);

        //Authenticate
        memcpy(aCmd,"\xFF\x86\x00\x00\x05\x01\x00\x04\x60\x00",10);
        uCmdLen = 10;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
        _cHelper.print(aResp,uRespLen);

        QString sName;
        //Read Card Fname
        memcpy(aCmd,"\xFF\xB0\x00\x04\x10",5);
        uCmdLen = 5;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
        _cHelper.print(aResp,uRespLen);

        sName = QString::fromLocal8Bit(QByteArray((char*)aResp,uRespLen));
        ui->lineEditFirstName->setText(sName);

        //Read Card Lname
        memcpy(aCmd,"\xFF\xB0\x00\x05\x10",5);
        uCmdLen = 5;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
        _cHelper.print(aResp,uRespLen);

        sName = QString::fromLocal8Bit(QByteArray((char*)aResp,uRespLen));
        ui->lineEditLastName->setText(sName);

    } catch (PcscException cException) {
        _cHelper.print(cException.getErrorMessage());
        QMessageBox cMsg;
        cMsg.setText(cException.getErrorMessage());
        cMsg.exec();
    } catch (std::exception cStdException) {
        _cHelper.print("Error!");
    }
}

void MainWindow::on_pushButtonSave_clicked()
{
    try {
        uint8 aCmd[256];
        uint32 uCmdLen = 11;
        uint8 aResp[256];
        uint32 uRespLen = 256;
        QStringList slData;

        //Load Key
        memcpy(aCmd,"\xFF\x82\x00\x00\x06\xFF\xFF\xFF\xFF\xFF\xFF",11);
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
        _cHelper.print(aResp,uRespLen);

        //Authenticate
        memcpy(aCmd,"\xFF\x86\x00\x00\x05\x01\x00\x04\x60\x00",10);
        uCmdLen = 10;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
            throw PcscException("Error: Please tap the card again..");
        }
         _cHelper.print(aResp,uRespLen);

         //Write Block 4
         memcpy(aCmd,"\xFF\xD6\x00\x04\x10",5);
         char aData[16];
         memset(aData,0,16);
         memcpy(aData,ui->lineEditFirstName->text().toUtf8().constData(),ui->lineEditFirstName->text().length());
         memcpy(aCmd+5,aData,sizeof(aData));
         uCmdLen = 21;
         _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
         if (memcmp(aResp,"\x63\x00",2)==0) {
             throw PcscException("Error: Please tap the card again..");
         }
          _cHelper.print(aResp,uRespLen);

        //Write Block 5
        memcpy(aCmd,"\xFF\xD6\x00\x05\x10",5);
        memset(aData,0,16);
        memcpy(aData,ui->lineEditLastName->text().toUtf8().constData(),ui->lineEditLastName->text().length());
        memcpy(aCmd+5,aData,sizeof(aData));
        uCmdLen = 21;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        if (memcmp(aResp,"\x63\x00",2)==0) {
          throw PcscException("Error: Please tap the card again..");
        }
        _cHelper.print(aResp,uRespLen);


        Connector cConnect;
        cConnect.sAddUser(ui->lineEditCardSerial->text(),
                          ui->lineEditFirstName->text() + " " +ui->lineEditLastName->text(),
                          "Restricted");

    } catch (PcscException cException) {
        _cHelper.print(cException.getErrorMessage());
        QMessageBox cMsg;
        cMsg.setText(cException.getErrorMessage());
        cMsg.exec();
    } catch (std::exception cStdException) {
        _cHelper.print("Error!");
    }
}

void MainWindow::on_actionSyncLogsDb_triggered()
{
    clearItemsToLogs();
    Connector cConnector;
    QStringList slData;
    cConnector.getLogs(&slData);


    for (int iIndex = 0; iIndex < slData.size() - 1; iIndex++) {
        QStringList slBuffer, slDataLine;
        slDataLine = QString(slData[iIndex]).split("\t");
        //        qDebug() << slDataLine;
        slBuffer << slDataLine[4];
        slBuffer << slDataLine[5];
        slBuffer << slDataLine[2];
        slBuffer << slDataLine[3];
        slBuffer << slDataLine[6];
        addItemsToLogs(slBuffer);
    }


}

void MainWindow::on_actionClearLogs_triggered()
{
    clearItemsToLogs();
}

void MainWindow::on_actionSyncUserDb_triggered()
{
    clearItemsToUser();
    Connector cConnector;
    QStringList slData;
    cConnector.getUsers(&slData);


    for (int iIndex = 0; iIndex < slData.size() - 1; iIndex++) {
        QStringList slBuffer, slDataLine;
        slDataLine = QString(slData[iIndex]).split("\t");
        //        qDebug() << slDataLine;
        //slBuffer << slDataLine[0];
        slBuffer << slDataLine[1];
        slBuffer << slDataLine[2];
        slBuffer << slDataLine[3];
        addItemsToUser(slBuffer);
    }
}

void MainWindow::on_actionClearUser_triggered()
{
    clearItemsToUser();
}


void MainWindow::on_actionClearLogsDb_triggered()
{
    Connector cConnector;
    cConnector.truncateLogs();
}

void MainWindow::on_actionClearAllUserDb_triggered()
{
    Connector cConnector;
    cConnector.truncateUser();
}
