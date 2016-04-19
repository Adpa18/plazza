//
// Created by consta_n on 15/04/16.
//

#ifndef THREADSAFE_WORKER_HPP
#define THREADSAFE_WORKER_HPP

#include <pthread.h>
#include "Task.hpp"

class Worker {
public:
    pthread_t       _thread;
    pthread_mutex_t _mutex;
    pthread_cond_t  _cond_var;
    bool            _is_running;
    bool            _status;
    Task            *task1;
    Task            *task2;
    size_t const    id;

public:
    Worker();
    Worker(pthread_mutex_t mutex);
    ~Worker();
    void run();
    void execTask();
    bool addTask(Task *task);

    static void *startThread(void *arg);
    static size_t  uniqueID();
};


#endif //THREADSAFE_WORKER_HPP
