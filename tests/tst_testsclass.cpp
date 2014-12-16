#include <QString>
#include <QtTest>
#include "../controller/blockingqueue.h"
#include "../common/events/streetfieldaddedevent.h"

class TestsClass : public QObject
{
    Q_OBJECT

public:
    TestsClass();

private Q_SLOTS:
    void testCase1();
};

TestsClass::TestsClass()
{
}

void TestsClass::testCase1()
{
    Coordinates coord;
    coord.x = 4;
    coord.y = 14;
    BlockingEventQueue::getInstance().push(new StreetFieldAddedEvent(coord));
    QVERIFY2(((StreetFieldAddedEvent*)BlockingEventQueue::getInstance().pop())->getName() == "StreetFieldAdded", "Wrong event name");
    Coordinates coord2 = ((StreetFieldAddedEvent*)BlockingEventQueue::getInstance().pop())->getCoordinates();
    QCOMPARE(coord.x, coord2.x);
    QCOMPARE(coord.y, coord2.y);

}

QTEST_APPLESS_MAIN(TestsClass)

#include "tst_testsclass.moc"
