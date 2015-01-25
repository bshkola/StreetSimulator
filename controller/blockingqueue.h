//Author: Bogdan Shkola
//Representing blocking queue used between controller and view modules.
#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H

#include "../common/events/ievent.h"
#include <mutex>
#include <condition_variable>
#include <deque>
#include <QObject>
#include <memory>

class BlockingEventQueue : public QObject
{
    Q_OBJECT
private:
    BlockingEventQueue();
    ~BlockingEventQueue();
    BlockingEventQueue(const BlockingEventQueue&);

    std::mutex              d_mutex;
    std::condition_variable d_condition;
    std::deque<std::shared_ptr<IEvent>>     d_queue;

public:
    //Adds event to the queue
    void push(IEvent* const& value); // puts an event to the queue
    //Gets event from the queue (blocking method)
    const std::shared_ptr<IEvent> pop(); //waits for the new event appears in the queue and gets it

    //Singleton
    static BlockingEventQueue& getInstance() {
        static BlockingEventQueue pInstance_;
        return pInstance_;
    }
};

#endif // BLOCKINGQUEUE_H
