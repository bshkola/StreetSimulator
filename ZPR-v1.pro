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
    view/iview.cpp \
    controller/strategies/istrategy.cpp \
    controller/strategies/closewindowstrategy.cpp \
    controller/strategies/itemclickedstrategy.cpp \
    controller/strategies/boardsizechangedstrategy.cpp \
    common/events/ievent.cpp \
    common/events/windowclosedevent.cpp \
    common/events/itemclickedevent.cpp \
    common/events/boardsizechangedevent.cpp \
    common/events/streetfieldaddedevent.cpp \
    common/events/streetfieldremovedevent.cpp \
    controller/strategies/streetfieldaddedstrategy.cpp \
    controller/strategies/streetfieldremovedstrategy.cpp \
    common/events/caraddedevent.cpp \
    controller/strategies/caraddedstrategy.cpp \
    controller/strategies/applicationstartedstrategy.cpp \
    common/board.cpp \
    common/events/applicationstartedevent.cpp



HEADERS  += mainwindow.h \
    controller/icontroller.h \
    controller/controllerimpl.h \
    model/imodel.h \
    model/modelimpl.h \
    view/boardscene.h \
    view/boardcell.h \
    view/mainwindow.h \
    controller/blockingqueue.h \
    common/coordinates.h \
    view/iview.h \
    controller/strategies/istrategy.h \
    controller/strategies/closewindowstrategy.h \
    controller/strategies/itemclickedstrategy.h \
    controller/strategies/boardsizechangedstrategy.h \
    common/events/ievent.h \
    common/events/windowclosedevent.h \
    common/events/itemclickedevent.h \
    common/events/boardsizechangedevent.h \
    common/events/streetfieldaddedevent.h \
    common/events/streetfieldremovedevent.h \
    controller/strategies/streetfieldaddedstrategy.h \
    controller/strategies/streetfieldremovedstrategy.h \
    common/events/caraddedevent.h \
    controller/strategies/caraddedstrategy.h \
    controller/strategies/applicationstartedstrategy.h \
    common/board.h \
    common/events/applicationstartedevent.h


FORMS    += mainwindow.ui
