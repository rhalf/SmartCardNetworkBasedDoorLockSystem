#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "lib/common/includes.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    PcscCard hCard;
    QStringList slReaders;
    QStringList slPollReaders;

    bool bValidUser;
    //QNetworkAccessManager * mgr;

    QTimer timerPolling;
    void connectCard(QString sReader, int iType);
    void disconnectCard(PcscCard hCard);

    void addItemsToLogs(QStringList slData);
    void clearItemsToLogs();

    void addItemsToUser(QStringList slData);
    void clearItemsToUser();

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:

    void cardPolling();

    void on_actionExit_triggered();

    void on_actionInitialize_triggered();

    void on_actionReset_triggered();

    void on_comboBoxReaderIn_currentIndexChanged(const QString &arg1);

    void on_comboBoxReaderOut_currentIndexChanged(const QString &arg1);

    void on_pushButtonApply_clicked();

    void on_pushButtonSendSms_clicked();

    void on_pushButtonCheckCard_clicked();

    void on_pushButtonSave_clicked();

    void on_actionClearLogs_triggered();

    void on_actionSyncUserDb_triggered();

    void on_actionClearUser_triggered();

    void on_actionSyncLogsDb_triggered();

    void on_actionClearLogsDb_triggered();

    void on_actionClearAllUserDb_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
