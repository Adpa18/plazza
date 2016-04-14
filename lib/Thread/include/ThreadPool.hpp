//
// Created by babiole on 11/04/16.
//

#ifndef THREAD_THREADPOOL_HPP
#define THREAD_THREADPOOL_HPP


#include <vector>
#include <queue>
#include <functional>
#include <unistd.h>
#include "Thread.hpp"
#include "LockableQueue.hpp"

class ThreadPool : public LockableQueue, public AThreadable {

private:
    std::vector<Thread *>               _threads;

    //Size of pool
    size_t                              _size;

protected:
    virtual void run();

public:
    //Constructor
    ThreadPool(Mutex const &mutex, size_t size);

    //Destructor
    ~ThreadPool();

    //Add 'num' thread(s) to the pool
    void    addThread(size_t num);

    //          GETTER          //
public:
    std::vector<Thread *>                                               getThreads() const;
    std::queue< std::pair< std::function< void *(void *)>, void *> *>   getQueue() const;
    size_t                                                              getSize() const;


};


#endif //THREAD_THREADPOOL_HPP
