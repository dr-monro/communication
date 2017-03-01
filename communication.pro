#-------------------------------------------------
#
# Project created by QtCreator 2017-02-28T18:48:21
#
#-------------------------------------------------

QT       += core gui
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = communication
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    robotcommunicator.cpp \
    commandparser.cpp

HEADERS  += mainwindow.h \
    robotcommunicator.h \
    commandparser.h \
    concretecommands.h

FORMS    += mainwindow.ui
