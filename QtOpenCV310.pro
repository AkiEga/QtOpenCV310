#-------------------------------------------------
#
# Project created by QtCreator 2016-12-10T15:53:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QtOpenCV310
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

win32:DEPENDPATH  += "C:\tools\opencv\build\include"
win32:INCLUDEPATH += "C:\tools\opencv\build\include"
win32:LIBS +=      -L"C:\tools\opencv\build\x64\vc14\lib"
win32:LIBS += -lopencv_world310d
