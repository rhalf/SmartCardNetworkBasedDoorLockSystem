/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jan 16 21:28:17 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionInitialize;
    QAction *actionReset;
    QAction *actionExit;
    QAction *actionSyncLogsDb;
    QAction *actionClearLogs;
    QAction *actionClearLogsDb;
    QAction *actionSyncUserDb;
    QAction *actionClearUser;
    QAction *actionLogs;
    QAction *actionClearAllUserDb;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labelReaderIn;
    QComboBox *comboBoxReaderIn;
    QLabel *labelReaderOut;
    QComboBox *comboBoxReaderOut;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTabWidget *tabWidgetFunctions;
    QWidget *tab0;
    QVBoxLayout *verticalLayout_3;
    QTableWidget *tableWidgetLogs;
    QTextEdit *textEditDebug;
    QWidget *tab1;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *tableWidgetUser;
    QGroupBox *groupBoxUseAction;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label;
    QLineEdit *lineEditMobileNumber;
    QPushButton *pushButtonSendSms;
    QPushButton *pushButtonApply;
    QWidget *tab;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelCardSerialNumber;
    QLineEdit *lineEditCardSerial;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelCardSerialNumber_2;
    QLineEdit *lineEditFirstName;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelCardSerialNumber_3;
    QLineEdit *lineEditLastName;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButtonCheckCard;
    QPushButton *pushButtonSave;
    QSpacerItem *verticalSpacer;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOption;
    QMenu *menuLogs;
    QMenu *menuUser;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionInitialize = new QAction(MainWindow);
        actionInitialize->setObjectName(QString::fromUtf8("actionInitialize"));
        actionReset = new QAction(MainWindow);
        actionReset->setObjectName(QString::fromUtf8("actionReset"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSyncLogsDb = new QAction(MainWindow);
        actionSyncLogsDb->setObjectName(QString::fromUtf8("actionSyncLogsDb"));
        actionClearLogs = new QAction(MainWindow);
        actionClearLogs->setObjectName(QString::fromUtf8("actionClearLogs"));
        actionClearLogsDb = new QAction(MainWindow);
        actionClearLogsDb->setObjectName(QString::fromUtf8("actionClearLogsDb"));
        actionSyncUserDb = new QAction(MainWindow);
        actionSyncUserDb->setObjectName(QString::fromUtf8("actionSyncUserDb"));
        actionClearUser = new QAction(MainWindow);
        actionClearUser->setObjectName(QString::fromUtf8("actionClearUser"));
        actionLogs = new QAction(MainWindow);
        actionLogs->setObjectName(QString::fromUtf8("actionLogs"));
        actionClearAllUserDb = new QAction(MainWindow);
        actionClearAllUserDb->setObjectName(QString::fromUtf8("actionClearAllUserDb"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelReaderIn = new QLabel(groupBox_2);
        labelReaderIn->setObjectName(QString::fromUtf8("labelReaderIn"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(2);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelReaderIn->sizePolicy().hasHeightForWidth());
        labelReaderIn->setSizePolicy(sizePolicy2);
        labelReaderIn->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelReaderIn);

        comboBoxReaderIn = new QComboBox(groupBox_2);
        comboBoxReaderIn->setObjectName(QString::fromUtf8("comboBoxReaderIn"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(8);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(comboBoxReaderIn->sizePolicy().hasHeightForWidth());
        comboBoxReaderIn->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(comboBoxReaderIn);

        labelReaderOut = new QLabel(groupBox_2);
        labelReaderOut->setObjectName(QString::fromUtf8("labelReaderOut"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(2);
        sizePolicy4.setHeightForWidth(labelReaderOut->sizePolicy().hasHeightForWidth());
        labelReaderOut->setSizePolicy(sizePolicy4);
        labelReaderOut->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelReaderOut);

        comboBoxReaderOut = new QComboBox(groupBox_2);
        comboBoxReaderOut->setObjectName(QString::fromUtf8("comboBoxReaderOut"));
        sizePolicy3.setHeightForWidth(comboBoxReaderOut->sizePolicy().hasHeightForWidth());
        comboBoxReaderOut->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(comboBoxReaderOut);


        verticalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(9);
        sizePolicy5.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy5);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tabWidgetFunctions = new QTabWidget(groupBox);
        tabWidgetFunctions->setObjectName(QString::fromUtf8("tabWidgetFunctions"));
        tab0 = new QWidget();
        tab0->setObjectName(QString::fromUtf8("tab0"));
        verticalLayout_3 = new QVBoxLayout(tab0);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        tableWidgetLogs = new QTableWidget(tab0);
        if (tableWidgetLogs->columnCount() < 5)
            tableWidgetLogs->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetLogs->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetLogs->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetLogs->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetLogs->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetLogs->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidgetLogs->setObjectName(QString::fromUtf8("tableWidgetLogs"));
        tableWidgetLogs->horizontalHeader()->setDefaultSectionSize(135);

        verticalLayout_3->addWidget(tableWidgetLogs);

        textEditDebug = new QTextEdit(tab0);
        textEditDebug->setObjectName(QString::fromUtf8("textEditDebug"));
        textEditDebug->setMaximumSize(QSize(16777215, 80));

        verticalLayout_3->addWidget(textEditDebug);

        tabWidgetFunctions->addTab(tab0, QString());
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        horizontalLayout_2 = new QHBoxLayout(tab1);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tableWidgetUser = new QTableWidget(tab1);
        if (tableWidgetUser->columnCount() < 3)
            tableWidgetUser->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetUser->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetUser->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetUser->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        tableWidgetUser->setObjectName(QString::fromUtf8("tableWidgetUser"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(8);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(tableWidgetUser->sizePolicy().hasHeightForWidth());
        tableWidgetUser->setSizePolicy(sizePolicy6);
        tableWidgetUser->setColumnCount(3);
        tableWidgetUser->horizontalHeader()->setDefaultSectionSize(165);

        horizontalLayout_2->addWidget(tableWidgetUser);

        groupBoxUseAction = new QGroupBox(tab1);
        groupBoxUseAction->setObjectName(QString::fromUtf8("groupBoxUseAction"));
        sizePolicy2.setHeightForWidth(groupBoxUseAction->sizePolicy().hasHeightForWidth());
        groupBoxUseAction->setSizePolicy(sizePolicy2);
        groupBoxUseAction->setMinimumSize(QSize(200, 0));
        verticalLayout_4 = new QVBoxLayout(groupBoxUseAction);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox_3 = new QGroupBox(groupBoxUseAction);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        sizePolicy.setHeightForWidth(groupBox_3->sizePolicy().hasHeightForWidth());
        groupBox_3->setSizePolicy(sizePolicy);
        groupBox_3->setMaximumSize(QSize(16777215, 250));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(0, 50));
        label->setMaximumSize(QSize(16777215, 50));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label);

        lineEditMobileNumber = new QLineEdit(groupBox_3);
        lineEditMobileNumber->setObjectName(QString::fromUtf8("lineEditMobileNumber"));
        lineEditMobileNumber->setMinimumSize(QSize(0, 0));

        verticalLayout_5->addWidget(lineEditMobileNumber);

        pushButtonSendSms = new QPushButton(groupBox_3);
        pushButtonSendSms->setObjectName(QString::fromUtf8("pushButtonSendSms"));
        pushButtonSendSms->setMinimumSize(QSize(0, 100));

        verticalLayout_5->addWidget(pushButtonSendSms);


        verticalLayout_4->addWidget(groupBox_3);

        pushButtonApply = new QPushButton(groupBoxUseAction);
        pushButtonApply->setObjectName(QString::fromUtf8("pushButtonApply"));
        pushButtonApply->setMinimumSize(QSize(0, 100));

        verticalLayout_4->addWidget(pushButtonApply);


        horizontalLayout_2->addWidget(groupBoxUseAction);

        tabWidgetFunctions->addTab(tab1, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_6 = new QVBoxLayout(tab);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_8 = new QVBoxLayout(groupBox_4);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelCardSerialNumber = new QLabel(groupBox_4);
        labelCardSerialNumber->setObjectName(QString::fromUtf8("labelCardSerialNumber"));
        labelCardSerialNumber->setMinimumSize(QSize(150, 0));

        horizontalLayout_3->addWidget(labelCardSerialNumber);

        lineEditCardSerial = new QLineEdit(groupBox_4);
        lineEditCardSerial->setObjectName(QString::fromUtf8("lineEditCardSerial"));
        lineEditCardSerial->setEnabled(false);
        lineEditCardSerial->setMinimumSize(QSize(300, 0));

        horizontalLayout_3->addWidget(lineEditCardSerial);


        verticalLayout_7->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelCardSerialNumber_2 = new QLabel(groupBox_4);
        labelCardSerialNumber_2->setObjectName(QString::fromUtf8("labelCardSerialNumber_2"));
        labelCardSerialNumber_2->setMinimumSize(QSize(150, 0));

        horizontalLayout_4->addWidget(labelCardSerialNumber_2);

        lineEditFirstName = new QLineEdit(groupBox_4);
        lineEditFirstName->setObjectName(QString::fromUtf8("lineEditFirstName"));
        lineEditFirstName->setMinimumSize(QSize(300, 0));
        lineEditFirstName->setMaxLength(16);

        horizontalLayout_4->addWidget(lineEditFirstName);


        verticalLayout_7->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelCardSerialNumber_3 = new QLabel(groupBox_4);
        labelCardSerialNumber_3->setObjectName(QString::fromUtf8("labelCardSerialNumber_3"));
        labelCardSerialNumber_3->setMinimumSize(QSize(150, 0));

        horizontalLayout_5->addWidget(labelCardSerialNumber_3);

        lineEditLastName = new QLineEdit(groupBox_4);
        lineEditLastName->setObjectName(QString::fromUtf8("lineEditLastName"));
        lineEditLastName->setMinimumSize(QSize(300, 0));
        lineEditLastName->setMaxLength(16);

        horizontalLayout_5->addWidget(lineEditLastName);


        verticalLayout_7->addLayout(horizontalLayout_5);


        verticalLayout_8->addLayout(verticalLayout_7);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        pushButtonCheckCard = new QPushButton(groupBox_4);
        pushButtonCheckCard->setObjectName(QString::fromUtf8("pushButtonCheckCard"));
        pushButtonCheckCard->setMinimumSize(QSize(0, 50));

        horizontalLayout_6->addWidget(pushButtonCheckCard);

        pushButtonSave = new QPushButton(groupBox_4);
        pushButtonSave->setObjectName(QString::fromUtf8("pushButtonSave"));
        pushButtonSave->setMinimumSize(QSize(0, 50));

        horizontalLayout_6->addWidget(pushButtonSave);


        verticalLayout_8->addLayout(horizontalLayout_6);


        verticalLayout_6->addWidget(groupBox_4);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        tabWidgetFunctions->addTab(tab, QString());

        verticalLayout_2->addWidget(tabWidgetFunctions);


        verticalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOption = new QMenu(menuBar);
        menuOption->setObjectName(QString::fromUtf8("menuOption"));
        menuLogs = new QMenu(menuOption);
        menuLogs->setObjectName(QString::fromUtf8("menuLogs"));
        menuUser = new QMenu(menuOption);
        menuUser->setObjectName(QString::fromUtf8("menuUser"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOption->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionInitialize);
        menuFile->addAction(actionReset);
        menuFile->addAction(actionExit);
        menuOption->addAction(menuLogs->menuAction());
        menuOption->addAction(menuUser->menuAction());
        menuLogs->addAction(actionSyncLogsDb);
        menuLogs->addAction(actionClearLogs);
        menuLogs->addAction(actionClearLogsDb);
        menuUser->addAction(actionSyncUserDb);
        menuUser->addAction(actionClearUser);
        menuUser->addAction(actionClearAllUserDb);

        retranslateUi(MainWindow);

        tabWidgetFunctions->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Smart Application", 0, QApplication::UnicodeUTF8));
        actionInitialize->setText(QApplication::translate("MainWindow", "Initialize", 0, QApplication::UnicodeUTF8));
        actionReset->setText(QApplication::translate("MainWindow", "Reset", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionSyncLogsDb->setText(QApplication::translate("MainWindow", "Syncronize (Database)", 0, QApplication::UnicodeUTF8));
        actionClearLogs->setText(QApplication::translate("MainWindow", "Clear all", 0, QApplication::UnicodeUTF8));
        actionClearLogsDb->setText(QApplication::translate("MainWindow", "Clear all Logs (Database)", 0, QApplication::UnicodeUTF8));
        actionSyncUserDb->setText(QApplication::translate("MainWindow", "Syncronize (Database)", 0, QApplication::UnicodeUTF8));
        actionClearUser->setText(QApplication::translate("MainWindow", "Clear All User", 0, QApplication::UnicodeUTF8));
        actionLogs->setText(QApplication::translate("MainWindow", "Logs", 0, QApplication::UnicodeUTF8));
        actionClearAllUserDb->setText(QApplication::translate("MainWindow", "Clear All User (Database)", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Configure Smart Card Reader for In and Out", 0, QApplication::UnicodeUTF8));
        labelReaderIn->setText(QApplication::translate("MainWindow", "Reader In:", 0, QApplication::UnicodeUTF8));
        labelReaderOut->setText(QApplication::translate("MainWindow", "Reader Out:", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetLogs->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Card Serial Number", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetLogs->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Card User Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetLogs->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Date and Time", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetLogs->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetLogs->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        tabWidgetFunctions->setTabText(tabWidgetFunctions->indexOf(tab0), QApplication::translate("MainWindow", "Logs ", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetUser->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Card Serial Number", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetUser->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Card User Name", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetUser->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Card Status", 0, QApplication::UnicodeUTF8));
        groupBoxUseAction->setTitle(QApplication::translate("MainWindow", "User Action", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Admin Mobile", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Mobile Number", 0, QApplication::UnicodeUTF8));
        pushButtonSendSms->setText(QApplication::translate("MainWindow", "Send Sms  (Testing)", 0, QApplication::UnicodeUTF8));
        pushButtonApply->setText(QApplication::translate("MainWindow", "Apply", 0, QApplication::UnicodeUTF8));
        tabWidgetFunctions->setTabText(tabWidgetFunctions->indexOf(tab1), QApplication::translate("MainWindow", "Administrate", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Card Information", 0, QApplication::UnicodeUTF8));
        labelCardSerialNumber->setText(QApplication::translate("MainWindow", "Card Serial Number:", 0, QApplication::UnicodeUTF8));
        labelCardSerialNumber_2->setText(QApplication::translate("MainWindow", "First Name", 0, QApplication::UnicodeUTF8));
        labelCardSerialNumber_3->setText(QApplication::translate("MainWindow", "Last Name", 0, QApplication::UnicodeUTF8));
        pushButtonCheckCard->setText(QApplication::translate("MainWindow", "Check Card ", 0, QApplication::UnicodeUTF8));
        pushButtonSave->setText(QApplication::translate("MainWindow", "Save", 0, QApplication::UnicodeUTF8));
        tabWidgetFunctions->setTabText(tabWidgetFunctions->indexOf(tab), QApplication::translate("MainWindow", "Registration", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuOption->setTitle(QApplication::translate("MainWindow", "Option", 0, QApplication::UnicodeUTF8));
        menuLogs->setTitle(QApplication::translate("MainWindow", "Logs", 0, QApplication::UnicodeUTF8));
        menuUser->setTitle(QApplication::translate("MainWindow", "User", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
