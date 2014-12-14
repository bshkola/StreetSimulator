#ifndef IEVENT_H
#define IEVENT_H

#include <QObject>

class IEvent : public QObject
{
    Q_OBJECT
public:
    explicit IEvent(QObject *parent = 0);
    virtual std::string getName() = 0;
signals:

public slots:

};

#endif // IEVENT_H
