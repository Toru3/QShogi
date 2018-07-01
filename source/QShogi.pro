#-------------------------------------------------
#
# Project created by QtCreator 2018-05-21T00:48:58
#
#-------------------------------------------------

QT       += core gui widgets
CONFIG += c++11
CONFIG += debug

TARGET = QShogi
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    boardview.cpp \
    koma.cpp \
    masu.cpp \
    board.cpp

HEADERS  += mainwindow.h \
    boardview.h \
    koma.h \
    masu.h \
    board.h

FORMS    += mainwindow.ui
