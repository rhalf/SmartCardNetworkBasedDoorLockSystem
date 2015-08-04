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

    timerPolling.setInterval(100);
    QObject::connect(&timerPolling,SIGNAL(timeout()),this,SLOT(cardPolling()));
}

MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::connectCard(QString sReader) {

    try {

        hCard = _cPcsc.connect(sReader);
        _cHelper.print("Connect,Ok");
        uint8 aCmd[256];
        uint32 uCmdLen = 11;
        uint8 aResp[256];
        uint32 uRespLen = 256;

        memcpy(aCmd,"\xFF\x82\x00\x00\x06\xFF\xFF\xFF\xFF\xFF\xFF",11);
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        _cHelper.print(aResp,uRespLen);

        memcpy(aCmd,"\xFF\x86\x00\x00\x05\x01\x00\x00\x60\x00",10);
        uCmdLen = 10;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        _cHelper.print(aResp,uRespLen);

        memcpy(aCmd,"\xFF\xB0\x00\x00\x10",5);
        uCmdLen = 5;
        _cPcsc.transmit(hCard,aCmd,uCmdLen,aResp,&uRespLen);
        _cHelper.print(aResp,uRespLen);

    } catch (PcscException cException) {
        _cHelper.print(cException.getErrorMessage());
    }
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

    for (int iIndex = 0; iIndex < slReaders.size() - 1; iIndex++) {
       sReader = slReaders[iIndex];
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
        connectCard(sReader);
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
