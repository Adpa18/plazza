//
// Created by consta_n on 19/04/16.
//

#ifndef THREADSAFE_THREADPOOL_HPP
#define THREADSAFE_THREADPOOL_HPP


#include <glob.h>
#include <queue>
#include "Worker.hpp"

class ThreadPool {
private:
    const size_t            m_size;
    std::vector<Worker *>   m_workers;
    std::queue<Task *>      m_tasks;
    bool                    m_status;
    pthread_mutex_t         m_mutex;
    pthread_t               m_thread;

public:
    ThreadPool(size_t size);
    ~ThreadPool();
    void start();
    void addTask(Task *task);
    void run ();

    static void *startThread(void *pool);
};


#endif //THREADSAFE_THREADPOOL_HPP
