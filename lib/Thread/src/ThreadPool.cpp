//
// Created by babiole on 11/04/16.
//

#include <iostream>
#include "ThreadPool.hpp"

//Constructor
ThreadPool::ThreadPool(Mutex const &mutex, size_t size) : LockableQueueTask(mutex), AThreadable() {
    m_size = size;
    for (size_t i = 0; i < m_size; ++i) {
        m_threads.push_back(new Worker());
    }
}

//Get the threadpool
std::vector<Worker *> ThreadPool::getThreads() const {
    return m_threads;
}

//Get the threadpool's size
size_t ThreadPool::getSize() const {
    return m_size;
}

void ThreadPool::run() {

    _status = ThreadStatus::RUN;
    while (_status != ThreadStatus::END || !m_queue.empty())
    {
        std::cout << m_queue.size() << std::endl;
        std::cout << _status << std::endl;
        for (std::vector<Worker *>::const_iterator elem = m_threads.begin(); elem != m_threads.end() ; ++elem) {
            if (!m_queue.empty() && (*elem)->getStatus() == ThreadStatus::PAUSE)
            {
                Task *task;

                task = m_queue.front();
                m_queue.pop();
                (*elem)->addTask(task);
                delete task;
            }
        }
        usleep(200);
    }
}

void ThreadPool::addThread(size_t size) {
    m_size += size;
    for (size_t i = 0; i < size; ++i) {
        m_threads.push_back(new Worker());
    }
}

//Destructor
ThreadPool::~ThreadPool() {

    if (!m_queue.empty())
    {
        std::cout << m_queue.size() << std::endl;
        for (std::vector<Worker *>::const_iterator elem = m_threads.begin(); elem != m_threads.end() ; ++elem) {
            (*elem)->join();
            std::cout << "join" << std::endl;
        }
        std::cout << "start j" << std::endl;
        join();
        std::cout << "end j" << std::endl;
    }
}
