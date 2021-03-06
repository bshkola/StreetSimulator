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
    controller/controllerimpl.cpp \
    model/modelimpl.cpp \
    view/boardscene.cpp \
    view/boardcell.cpp \
    view/mainwindow.cpp \
    controller/blockingqueue.cpp \
    model/convert.cpp \
    model/dijkstra.cpp \
    model/graph.cpp \
    model/simulationpreparator.cpp \
    common/events/applicationstartedevent.cpp \
    common/events/boardsizechangedevent.cpp \
    common/events/ievent.cpp \
    common/events/streetfieldaddedevent.cpp \
    common/events/streetfieldremovedevent.cpp \
    common/events/windowclosedevent.cpp \
    common/board.cpp \
    controller/strategies/applicationstartedstrategy.cpp \
    controller/strategies/boardsizechangedstrategy.cpp \
    controller/strategies/closewindowstrategy.cpp \
    controller/strategies/streetfieldaddedstrategy.cpp \
    controller/strategies/streetfieldremovedstrategy.cpp \
    model/database/database.cpp \
    model/objectsonmap.cpp \
    common/events/startsimulationevent.cpp \
    controller/strategies/startsimulationstrategy.cpp \
    detection/cameradetectionimpl.cpp \
    detection/cameranoiseimpl.cpp \
    model/engine/engine.cpp \
    model/engine/objectspositionupdater.cpp \
    view/items/truckcaritem.cpp \
    view/items/imovableitem.cpp \
    view/items/passengercaritem.cpp \
    view/items/destinationitem.cpp \
    view/items/cameraitem.cpp \
    view/mouseeventhandler/cameramouseeventhandler.cpp \
    view/mouseeventhandler/trafficparticipansmouseeventhandler.cpp \
    view/mouseeventhandler/destinationmouseeventhandler.cpp \
    view/items/itrafficparticipantitem.cpp \
    common/events/cameraaddedevent.cpp \
    common/events/camerareplacedevent.cpp \
    common/events/cameraremovedevent.cpp \
    controller/strategies/cameraaddedstrategy.cpp \
    controller/strategies/cameraremovedstrategy.cpp \
    controller/strategies/camerareplacedstrategy.cpp \
    controller/strategies/trafficobjectaddedstrategy.cpp \
    controller/strategies/trafficobjectreplacedstrategy.cpp \
    controller/strategies/trafficobjectremovedstrategy.cpp \
    common/events/trafficobjectaddedevent.cpp \
    common/events/trafficobjectremovedevent.cpp \
    common/events/trafficobjectreplacedevent.cpp \
    controller/strategies/destinationreplacedstrategy.cpp \
    common/events/destinationreplaceevent.cpp \
    database/databaseconnector.cpp \
    view/isimulatorview.cpp \
    view/simulatorwindow.cpp \
    common/exceptions/notwaybetweensourceanddestinationtargetpointexceptions.cpp \
    common/cameraoptions.cpp \
    common/events/cameraoptionschangedevent.cpp \
    controller/strategies/cameraoptionschangedstrategy.cpp \
    common/exceptions/wrongidobjectexception.cpp \
    view/items/pedestrianitem.cpp

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
    common/events/ievent.h \
    common/events/streetfieldaddedevent.h \
    common/events/streetfieldremovedevent.h \
    common/events/windowclosedevent.h \
    common/board.h \
    controller/strategies/applicationstartedstrategy.h \
    controller/strategies/boardsizechangedstrategy.h \
    controller/strategies/closewindowstrategy.h \
    controller/strategies/istrategy.h \
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
    model/engine/engine.h \
    model/engine/objectspositionupdater.h \
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
    controller/strategies/camerareplacedstrategy.h \
    controller/strategies/destinationreplacedstrategy.h \
    common/events/destinationreplaceevent.h \
    common/events/trafficobjectremovedevent.h \
    common/events/trafficobjectreplacedevent.h \
    common/events/trafficobjectaddedevent.h \
    controller/strategies/trafficobjectaddedstrategy.h \
    controller/strategies/trafficobjectreplacedstrategy.h \
    controller/strategies/trafficobjectremovedstrategy.h \
    database/databaseconnector.h \
    view/isimulatorview.h \
    view/simulatorwindow.h \
    common/exceptions/notwaybetweensourceanddestinationtargetpointexceptions.h \
    common/cameraoptions.h \
    common/events/cameraoptionschangedevent.h \
    controller/strategies/cameraoptionschangedstrategy.h \
    common/exceptions/wrongidobjectexception.h \
    view/items/pedestrianitem.h

FORMS    += mainwindow.ui \
    simulationwindow.ui

unix|win32: LIBS += -lmysqlcppconn
