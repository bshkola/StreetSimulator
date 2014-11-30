#ifndef BLOCKINGQUEUE_H
#define BLOCKINGQUEUE_H

#include "../common/event.h"
#include <mutex>
#include <condition_variable>
#include <deque>
#include <QObject>

class BlockingEventQueue : public QObject
{
    Q_OBJECT
private:
    BlockingEventQueue();
    BlockingEventQueue(const BlockingEventQueue&);

    std::mutex              d_mutex;
    std::condition_variable d_condition;
    std::deque<Event*>       d_queue;

public:
    void push(Event* const& value);
    Event* pop();

    static BlockingEventQueue& getInstance() {
        static BlockingEventQueue pInstance_;
        return pInstance_;
    }
};

#endif // BLOCKINGQUEUE_H
