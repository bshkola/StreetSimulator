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
    controller/icontroller.cpp \
    controller/controllerimpl.cpp \
    model/imodel.cpp \
    model/modelimpl.cpp \
    view/boardscene.cpp \
    view/boardcell.cpp \
    view/mainwindow.cpp \
    controller/blockingqueue.cpp \
    common/events/itemclickedevent.cpp \
    view/iview.cpp \
    controller/strategies/closewindowstrategy.cpp \
    controller/strategies/itemclickedstrategy.cpp \
    common/events/windowclosedevent.cpp \
    common/events/ievent.cpp \
    controller/strategies/istrategy.cpp

HEADERS  += mainwindow.h \
    controller/icontroller.h \
    controller/controllerimpl.h \
    model/imodel.h \
    model/modelimpl.h \
    view/boardscene.h \
    view/boardcell.h \
    view/mainwindow.h \
    controller/blockingqueue.h \
    common/events/itemclickedevent.h \
    common/coordinates.h \
    view/iview.h \
    controller/strategies/closewindowstrategy.h \
    controller/strategies/itemclickedstrategy.h \
    common/events/windowclosedevent.h \
    common/events/ievent.h \
    controller/strategies/istrategy.h

FORMS    += mainwindow.ui
