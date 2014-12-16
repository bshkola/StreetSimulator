#-------------------------------------------------
#
# Project created by QtCreator 2014-12-17T00:12:47
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_testsclass
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_testsclass.cpp \
    ../controller/blockingqueue.cpp \
    ../common/events/streetfieldaddedevent.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

HEADERS += \
    ../controller/blockingqueue.h \
    ../common/events/streetfieldaddedevent.h
