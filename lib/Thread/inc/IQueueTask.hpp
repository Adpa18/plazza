//
// Created by consta_n on 14/04/16.
//

#ifndef PLAZZA_IQUEUETASK_HPP
#define PLAZZA_IQUEUETASK_HPP

#include <functional>
#include "Task.hpp"

class IQueueTask {
public:
    virtual         ~IQueueTask(void) {};
    virtual void    enqueue(Task *task) = 0;
    virtual bool    dequeue(void) = 0;

};

#endif //PLAZZA_IQUEUETASK_HPP
