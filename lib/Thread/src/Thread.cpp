//
// Created by babiole on 11/04/16.
//

#include <iostream>
#include "Thread.hpp"

Thread::Thread() : AThreadable() {

    _status = ThreadStatus::PAUSE;
    _task = NULL;
    _param = NULL;
    _result = NULL;
    std::cout << "Coucou je suis le petit thread des familles!" << std::endl;
}

void        Thread::run() {

    while (_status != ThreadStatus::END)
    {
        if (_status == ThreadStatus::PAUSE) {
            usleep(200); /////////////////////////   MOUAI BOF(Cond variable ?)  ////////////////////////////
            continue;
        }
        _result = exec();
        _status = ThreadStatus::PAUSE;
    }
}

void Thread::setTask(std::function<void *(void *)> func, void *param) {
    _task = func;
    _param = param;
}

void Thread::runTask(std::function<void *(void *)> func, void *param) {
    setTask(func, param);
    setStatus(ThreadStatus::RUN);
}

void *Thread::exec() const {
    return _task(_param);
}

void *Thread::getResult() const {
    return _result;
}

Thread::~Thread() {
    if (pthread_join(_thread, NULL))
        throw  ThreadException(strerror(errno));
    std::cout << "Damn it, i die!" << std::endl;
}


