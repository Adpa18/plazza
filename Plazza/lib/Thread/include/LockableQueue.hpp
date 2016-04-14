//
// Created by consta_n on 14/04/16.
//

#ifndef PLAZZA_LOCKABLEQUEUE_HPP
#define PLAZZA_LOCKABLEQUEUE_HPP

#include <queue>
#include "IGenericQueue.hpp"
#include "Lockable.hpp"

class LockableQueue : public IGenericQueue, public Lockable {
private:
    std::queue< std::pair< std::function< void *(void *)>, void *> *>   _queue;

public:
    LockableQueue(Mutex const &mutex);
    ~LockableQueue();

    virtual void enqueue(std::function<void *(void *)> func, void *param);
    virtual bool dequeue();
};


#endif //PLAZZA_LOCKABLEQUEUE_HPP
