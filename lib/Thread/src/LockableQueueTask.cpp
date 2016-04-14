//
// Created by consta_n on 14/04/16.
//

#include "../inc/LockableQueueTask.hpp"

LockableQueueTask::LockableQueueTask(Mutex const &mutex) : Lockable(mutex) {

}

void LockableQueueTask::enqueue(Task *task) {
    m_queue.push(task);
}

bool LockableQueueTask::dequeue() {
    return false;
}

LockableQueueTask::~LockableQueueTask() {

}








