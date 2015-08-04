/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionInitialize;
    QAction *actionReset;
    QAction *actionExit;
    QWidget *centralWidget;
    QSplitter *splitter;
    QLabel *labelReaderIn;
    QComboBox *comboBoxReaderIn;
    QLabel *labelReaderOut;
    QComboBox *comboBoxReaderOut;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1280, 720);
        actionInitialize = new QAction(MainWindow);
        actionInitialize->setObjectName(QStringLiteral("actionInitialize"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QStringLiteral("actionReset"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(30, 10, 1221, 27));
        splitter->setOrientation(Qt::Horizontal);
        labelReaderIn = new QLabel(splitter);
        labelReaderIn->setObjectName(QStringLiteral("labelReaderIn"));
        labelReaderIn->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter->addWidget(labelReaderIn);
        comboBoxReaderIn = new QComboBox(splitter);
        comboBoxReaderIn->setObjectName(QStringLiteral("comboBoxReaderIn"));
        splitter->addWidget(comboBoxReaderIn);
        labelReaderOut = new QLabel(splitter);
        labelReaderOut->setObjectName(QStringLiteral("labelReaderOut"));
        labelReaderOut->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        splitter->addWidget(labelReaderOut);
        comboBoxReaderOut = new QComboBox(splitter);
        comboBoxReaderOut->setObjectName(QStringLiteral("comboBoxReaderOut"));
        splitter->addWidget(comboBoxReaderOut);
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionInitialize);
        menuFile->addAction(actionReset);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Smart Application", 0));
        actionInitialize->setText(QApplication::translate("MainWindow", "Initialize", 0));
        actionReset->setText(QApplication::translate("MainWindow", "Reset", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        labelReaderIn->setText(QApplication::translate("MainWindow", "Reader In:", 0));
        labelReaderOut->setText(QApplication::translate("MainWindow", "Reader Out:", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
