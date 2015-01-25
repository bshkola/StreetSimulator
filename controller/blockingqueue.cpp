//Author: Bogdan Shkola
//Implementation of BlockingEventQueue class
#include "blockingqueue.h"

BlockingEventQueue::BlockingEventQueue() {
}

BlockingEventQueue::~BlockingEventQueue() {
    d_queue.clear();
}

BlockingEventQueue::BlockingEventQueue(const BlockingEventQueue&) {}

void BlockingEventQueue::push(IEvent* const& value) {
    {
        std::unique_lock<std::mutex> lock(this->d_mutex);
        d_queue.push_front(std::shared_ptr<IEvent>(value));
    }
    this->d_condition.notify_one();
}

const std::shared_ptr<IEvent> BlockingEventQueue::pop() {
    std::unique_lock<std::mutex> lock(this->d_mutex);
    this->d_condition.wait(lock, [=] { return !this->d_queue.empty(); });
    std::shared_ptr<IEvent> rc(std::move(this->d_queue.back()));
    this->d_queue.pop_back();
    return rc;
}
