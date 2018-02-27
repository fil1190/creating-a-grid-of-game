#-------------------------------------------------
#
# Project created by QtCreator 2018-02-19T13:22:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = hexagons
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    HexagonalCell.cpp \
    GridItem.cpp \
    GridGroupItem.cpp

HEADERS  += mainwindow.h \
    IGridCell.h \
    HexagonalCell.h \
    GridItem.h \
    GridGroupItem.h

FORMS    += mainwindow.ui
CONFIG += C++11
