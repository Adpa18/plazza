//
// Created by consta_n on 14/04/16.
//

#ifndef PLAZZA_LOCKABLEQUEUETASK_HPP
#define PLAZZA_LOCKABLEQUEUETASK_HPP

#include <queue>
#include "IQueueTask.hpp"
#include "Lockable.hpp"
#include "Task.hpp"

class LockableQueueTask : public IQueueTask, public Lockable {
protected:
    std::queue<Task *>   m_queue;

public:
    LockableQueueTask(Mutex const &mutex);
    ~LockableQueueTask();

    virtual void enqueue(Task *task);
    virtual bool dequeue(void);
};


#endif //PLAZZA_LOCKABLEQUEUETASK_HPP
