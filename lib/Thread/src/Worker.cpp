//
// Created by babiole on 11/04/16.
//

#include <iostream>
#include "Worker.hpp"

Worker::Worker() : AThreadable() {

    _status = ThreadStatus::PAUSE;
    m_task[0] = NULL;
    m_task[1] = NULL;
    m_result = NULL;
    std::cout << "Coucou je suis le petit thread des familles!" << std::endl;
}

void        Worker::run() {

    while (_status != ThreadStatus::END)
    {
        if (_status == ThreadStatus::PAUSE) {
            usleep(200); /////////////////////////   MOUAI BOF(Cond variable ?)  ////////////////////////////
            continue;
        }
        m_result = exec();
    }
}

void *Worker::exec() {

    if (m_task[0])
    {
        m_result = m_task[0]->run();
        delete m_task[0];
        m_task[0] = m_task[1];
        m_task[1] = NULL;
    }
    if (m_task[0] == NULL)
        setStatus(ThreadStatus::PAUSE);
    return m_result;
}

bool Worker::addTask(Task *task) {

    if (m_task[0] && m_task[1])
        return false;
    m_mutex.lock();
    if (m_task[0] == NULL)
        m_task[0] = task;
    else if (m_task[1] == NULL)
        m_task[0] = task;
    setStatus(ThreadStatus::RUN);
    m_mutex.unlock();
    return true;
}

void *Worker::getResult() const {
    return m_result;
}

Worker::~Worker() {
    if (pthread_join(_thread, NULL))
        throw  Exception(strerror(errno));
    std::cout << "Damn it, i die!" << std::endl;
}




