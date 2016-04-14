//
// Created by consta_n on 14/04/16.
//

#include "LockableQueue.hpp"

LockableQueue::LockableQueue(Mutex const &mutex) : Lockable(mutex) {

}

void LockableQueue::enqueue(std::function<void *(void *)> func, void *param) {
    _queue.push(new std::pair<std::function<void *(void *)>, void *>(func, param));
}

bool LockableQueue::dequeue() {
    return false;
}

LockableQueue::~LockableQueue() {

}








