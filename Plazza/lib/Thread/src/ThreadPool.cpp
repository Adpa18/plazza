//
// Created by babiole on 11/04/16.
//

#include <iostream>
#include "ThreadPool.hpp"

//Constructor
ThreadPool::ThreadPool(size_t size) : AThreadable() {
    _size = size;
    _status = ThreadStatus::RUN;
    for (size_t i = 0; i < size; ++i) {
        _threads.push_back(new Thread());
    }
}

//Get the threadpool
std::vector<Thread *> ThreadPool::getThreads() const {
    return _threads;
}

//Get the threadpool's tasks
std::queue< std::pair< std::function< void *(void *)>, void *> *> ThreadPool::getQueue() const {
    return _tasks;
}

//Get the threadpool's size
size_t ThreadPool::getSize() const {
    return _size;
}

void ThreadPool::run() {

    while (_status != ThreadStatus::END || !_tasks.empty())
    {
        std::cout << _tasks.size() << std::endl;
        std::cout << _status << std::endl;
        for (std::vector<Thread *>::const_iterator elem = _threads.begin(); elem != _threads.end() ; ++elem) {
            if (!_tasks.empty() && (*elem)->getStatus() == ThreadStatus::PAUSE)
            {
                std::pair< std::function< void *(void *)>, void *> *task;

                task = _tasks.front();
                _tasks.pop();
                (*elem)->runTask(task->first, task->second);
                delete task;
            }
        }
        usleep(200);
    }
}

void ThreadPool::queueTask(std::function<void *(void *)> func, void *param) {

    _tasks.push(new std::pair<std::function<void *(void *)>, void *>(func, param));
}

void ThreadPool::addThread(size_t size) {
    _size += size;
    for (size_t i = 0; i < size; ++i) {
        _threads.push_back(new Thread());
    }
}

//Destructor
ThreadPool::~ThreadPool() {

    if (!_tasks.empty())
    {
        std::cout << _tasks.size() << std::endl;
        for (std::vector<Thread *>::const_iterator elem = _threads.begin(); elem != _threads.end() ; ++elem) {
            (*elem)->join();
            std::cout << "join" << std::endl;
        }
        std::cout << "start j" << std::endl;
        join();
        std::cout << "end j" << std::endl;
    }
}




















