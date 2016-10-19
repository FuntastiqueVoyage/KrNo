#-------------------------------------------------
#
# Project created by QtCreator 2016-10-03T16:27:15
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TTT
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    game.cpp \
    windialog.cpp \
    losedialog.cpp \
    offconnector.cpp \
    newgame.cpp \
    onconnector.cpp \
    econtroller.cpp \
    search.cpp

HEADERS  += mainwindow.h \
    game.h \
    windialog.h \
    losedialog.h \
    offconnector.h \
    newgame.h \
    onconnector.h \
    econtroller.h \
    search.h

FORMS    += mainwindow.ui \
    windialog.ui \
    losedialog.ui \
    newgame.ui \
    search.ui

RESOURCES += \
    src.qrc
