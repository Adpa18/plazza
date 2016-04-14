//
// Created by consta_n on 14/04/16.
//

#ifndef PLAZZA_ILOCKABLEQUEUE_HPP_HPP
#define PLAZZA_ILOCKABLEQUEUE_HPP_HPP

#include <functional>

class IGenericQueue {
public:
    virtual         ~IGenericQueue(void) {};
    virtual void    enqueue(std::function<void *(void *)> func, void *param) = 0;
    virtual bool    dequeue() = 0;

};

#endif //PLAZZA_ILOCKABLEQUEUE_HPP_HPP
