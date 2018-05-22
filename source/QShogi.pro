#-------------------------------------------------
#
# Project created by QtCreator 2018-05-21T00:48:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QShogi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    boardview.cpp

HEADERS  += mainwindow.h \
    boardview.h

FORMS    += mainwindow.ui
