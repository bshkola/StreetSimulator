#include <QString>
#include <QtTest>
#include <iostream>
#include "../controller/blockingqueue.h"
#include "../common/events/streetfieldaddedevent.h"

class TestsClass : public QObject
{
    Q_OBJECT

public:
    TestsClass();

private Q_SLOTS:
    void testCase0();
    void testCase1();
};

TestsClass::TestsClass()
{
}

void TestsClass::testCase0()
{
    QVERIFY2(true, "Ok");
}

void TestsClass::testCase1()
{
    Coordinates coord;
    coord.x = 4;
    coord.y = 14;
    BlockingEventQueue::getInstance().push(new StreetFieldAddedEvent(coord));
    StreetFieldAddedEvent* event= (StreetFieldAddedEvent*)(BlockingEventQueue::getInstance().pop());
    QVERIFY2(event->getName() == "StreetFieldAdded", "Wrong event name");
    Coordinates coord2 = event->getCoordinates();
    QCOMPARE(coord.x, coord2.x);
    QCOMPARE(coord.y, coord2.y);

}

QTEST_APPLESS_MAIN(TestsClass)

#include "tst_testsclass.moc"
