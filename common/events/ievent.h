//Author: Bogdan Shkola
//Representing event interface. Every event implementation must inherit this interface.

#ifndef IEVENT_H
#define IEVENT_H

#include <QObject>

class IEvent : public QObject
{
    Q_OBJECT
public:
    explicit IEvent(QObject *parent = 0);
    virtual std::string getName() = 0; // unique identifier of event class
signals:

public slots:

};

#endif // IEVENT_H
