#include "blockingqueue.h"

BlockingEventQueue::BlockingEventQueue() {}
BlockingEventQueue::BlockingEventQueue(const BlockingEventQueue&) {}

void BlockingEventQueue::push(Event* const& value) {
    {
        std::unique_lock<std::mutex> lock(this->d_mutex);
        d_queue.push_front(value);
    }
    this->d_condition.notify_one();
}

Event* BlockingEventQueue::pop() {
    std::unique_lock<std::mutex> lock(this->d_mutex);
    this->d_condition.wait(lock, [=]{ return !this->d_queue.empty(); });
    Event* rc(std::move(this->d_queue.back()));
    this->d_queue.pop_back();
    return rc;
}
