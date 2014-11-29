#-------------------------------------------------
#
# Project created by QtCreator 2014-10-25T13:49:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZPR-v1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    controller/icontroller.cpp \
    controller/controllerimpl.cpp \
    model/imodel.cpp \
    model/modelimpl.cpp \
    view/boardscene.cpp

HEADERS  += mainwindow.h \
    controller/icontroller.h \
    controller/controllerimpl.h \
    model/imodel.h \
    model/modelimpl.h \
    view/boardscene.h

FORMS    += mainwindow.ui
