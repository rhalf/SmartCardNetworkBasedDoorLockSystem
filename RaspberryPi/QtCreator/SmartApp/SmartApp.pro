#-------------------------------------------------
#
# Project created by QtCreator 2014-12-15T14:30:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SmartApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    lib/pcscd/pcsc.cpp \
    lib/common/helper.cpp \
    lib/pcscd/pcscexception.cpp

HEADERS  += mainwindow.h \
    lib/pcscd/pcsc.h \
    lib/common/includes.h \
    lib/common/helper.h \
    lib/common/typedef.h \
    lib/pcscd/pcscexception.h

FORMS    += mainwindow.ui

unix:!macx:!symbian: LIBS += -L$$PWD/lib/pcscd/ -lpcsclite

INCLUDEPATH += $$PWD/lib/pcscd
DEPENDPATH += $$PWD/lib/pcscd
