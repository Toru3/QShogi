#-------------------------------------------------
#
# Project created by QtCreator 2018-05-21T00:48:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CXXFLAGS += -std=c++11

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
