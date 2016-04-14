//
// Created by babiole on 11/04/16.
//

#ifndef THREAD_THREADPOOL_HPP
#define THREAD_THREADPOOL_HPP


#include <vector>
#include <queue>
#include <functional>
#include <unistd.h>
#include "Worker.hpp"
#include "LockableQueueTask.hpp"

class ThreadPool : public LockableQueueTask, public AThreadable {

private:
    std::vector<Worker *>               m_threads;

    //Size of pool
    size_t                              m_size;

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
    std::vector<Worker *>                                               getThreads() const;
    size_t                                                              getSize() const;
};


#endif //THREAD_THREADPOOL_HPP
