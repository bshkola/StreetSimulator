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
    view/iview.cpp \
    model/convert.cpp \
    model/dijkstra.cpp \
    model/graph.cpp \
    model/simulationpreparator.cpp \
    common/events/applicationstartedevent.cpp \
    common/events/boardsizechangedevent.cpp \
    common/events/caraddedevent.cpp \
    common/events/ievent.cpp \
    common/events/itemclickedevent.cpp \
    common/events/streetfieldaddedevent.cpp \
    common/events/streetfieldremovedevent.cpp \
    common/events/windowclosedevent.cpp \
    common/board.cpp \
    controller/strategies/applicationstartedstrategy.cpp \
    controller/strategies/boardsizechangedstrategy.cpp \
    controller/strategies/caraddedstrategy.cpp \
    controller/strategies/closewindowstrategy.cpp \
    controller/strategies/istrategy.cpp \
    controller/strategies/itemclickedstrategy.cpp \
    controller/strategies/streetfieldaddedstrategy.cpp \
    controller/strategies/streetfieldremovedstrategy.cpp \
    model/database/database.cpp \
    model/objectsonmap.cpp \
    common/events/startsimulationevent.cpp \
    controller/strategies/startsimulationstrategy.cpp \
    detection/cameradetectionimpl.cpp \
    detection/cameranoiseimpl.cpp \
    view/items/truckcaritem.cpp \
    view/items/imovableitem.cpp \
    view/items/passengercaritem.cpp \
    view/items/destinationitem.cpp \
    view/items/cameraitem.cpp \
    view/mouseeventhandler/mouseeventhandler.cpp \
    view/mouseeventhandler/cameramouseeventhandler.cpp \
    view/mouseeventhandler/trafficparticipansmouseeventhandler.cpp \
    view/mouseeventhandler/destinationmouseeventhandler.cpp \
    view/items/itrafficparticipantitem.cpp \
    common/events/cameraaddedevent.cpp \
    common/events/camerareplacedevent.cpp \
    common/events/cameraremovedevent.cpp \
    controller/strategies/cameraaddedstrategy.cpp \
    controller/strategies/cameraremovedstrategy.cpp \
    controller/strategies/camerareplacedstrategy.cpp




HEADERS  += controller/icontroller.h \
    controller/controllerimpl.h \
    model/imodel.h \
    model/modelimpl.h \
    view/boardscene.h \
    view/boardcell.h \
    view/mainwindow.h \
    controller/blockingqueue.h \
    view/iview.h \
    model/convert.h \
    model/dijkstra.h \
    model/graph.h \
    model/simulationpreparator.h \
    common/events/applicationstartedevent.h \
    common/events/boardsizechangedevent.h \
    common/events/caraddedevent.h \
    common/events/ievent.h \
    common/events/itemclickedevent.h \
    common/events/streetfieldaddedevent.h \
    common/events/streetfieldremovedevent.h \
    common/events/windowclosedevent.h \
    common/board.h \
    controller/strategies/applicationstartedstrategy.h \
    controller/strategies/boardsizechangedstrategy.h \
    controller/strategies/caraddedstrategy.h \
    controller/strategies/closewindowstrategy.h \
    controller/strategies/istrategy.h \
    controller/strategies/itemclickedstrategy.h \
    controller/strategies/streetfieldaddedstrategy.h \
    controller/strategies/streetfieldremovedstrategy.h \
    common/field/field.h \
    common/field/grassfield.h \
    common/field/roadfield.h \
    common/street/crossingt.h \
    common/street/crossingx.h \
    common/street/deadend.h \
    common/street/straight.h \
    common/street/street.h \
    common/street/turn.h \
    common/traffic/car.h \
    common/traffic/pedestrian.h \
    common/traffic/trafficparticipant.h \
    common/traffic/truck.h \
    common/traffic/vehicle.h \
    common/camera.h \
    common/direction.h \
    model/database/database.h \
    model/objectsonmap.h \
    common/events/startsimulationevent.h \
    controller/strategies/startsimulationstrategy.h \
    detection/cameradetectionimpl.h \
    detection/cameranoiseimpl.h \
    detection/cameraobservation.h \
    detection/icameradetection.h \
    detection/icameranoise.h \
    view/items/truckcaritem.h \
    view/items/imovableitem.h \
    view/items/passengercaritem.h \
    view/items/destinationitem.h \
    view/items/cameraitem.h \
    view/mouseeventhandler/mouseeventhandler.h \
    view/mouseeventhandler/cameramouseeventhandler.h \
    view/mouseeventhandler/trafficparticipansmouseeventhandler.h \
    view/mouseeventhandler/destinationmouseeventhandler.h \
    view/items/itrafficparticipantitem.h \
    common/events/cameraaddedevent.h \
    common/events/camerareplacedevent.h \
    common/events/cameraremovedevent.h \
    common/types.h \
    controller/strategies/cameraaddedstrategy.h \
    controller/strategies/cameraremovedstrategy.h \
    controller/strategies/camerareplacedstrategy.h



FORMS    += mainwindow.ui \
    mainwindow.ui
