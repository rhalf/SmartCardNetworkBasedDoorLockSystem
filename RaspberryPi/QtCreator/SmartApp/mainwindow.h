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
    QTimer timerPolling;
    void connectCard(QString sReader);
    void disconnectCard(PcscCard hCard);

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void cardPolling();
    void on_actionExit_triggered();

    void on_actionInitialize_triggered();

    void on_actionReset_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
