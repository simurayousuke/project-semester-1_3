#-------------------------------------------------
#
# Project created by QtCreator 2016-06-16T08:23:28
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = chat
TEMPLATE = app


SOURCES += main.cpp\
        loginwindow.cpp \
    CmWidgets/CGroupBox.cpp \
    stdafx.cpp

HEADERS  += loginwindow.h \
    CmWidgets/CGroupBox.h \
    stdafx.h

FORMS    += loginwindow.ui