#-------------------------------------------------
#
# Project created by QtCreator 2014-10-25T13:49:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZPR-v1
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
    controller/icontroller.cpp \
    controller/controllerimpl.cpp \
    model/imodel.cpp \
    model/modelimpl.cpp \
    view/boardscene.cpp \
    view/boardcell.cpp \
    view/mainwindow.cpp \
    controller/blockingqueue.cpp \
    common/itemclickedevent.cpp \
    common/event.cpp \
    view/iview.cpp \
    controller/strategy/closewindowstrategy.cpp \
    controller/strategy/strategy.cpp \
    controller/strategy/itemclickedstrategy.cpp \
    common/windowclosedevent.cpp \
    model/convert.cpp \
    model/dijkstra.cpp \
    model/graph.cpp \
    model/simulationpreparator.cpp

HEADERS  += mainwindow.h \
    controller/icontroller.h \
    controller/controllerimpl.h \
    model/imodel.h \
    model/modelimpl.h \
    view/boardscene.h \
    view/boardcell.h \
    view/mainwindow.h \
    controller/blockingqueue.h \
    common/itemclickedevent.h \
    common/coordinates.h \
    common/event.h \
    view/iview.h \
    controller/strategy/closewindowstrategy.h \
    controller/strategy/strategy.h \
    controller/strategy/itemclickedstrategy.h \
    common/windowclosedevent.h \
    model/convert.h \
    model/dijkstra.h \
    model/graph.h \
    model/simulationpreparator.h

FORMS    += mainwindow.ui
