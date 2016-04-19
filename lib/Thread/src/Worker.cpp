//
// Created by consta_n on 15/04/16.
//

#include <unistd.h>
#include <iostream>
#include "Worker.hpp"

Worker::Worker() : id(Worker::uniqueID()) {
    pthread_mutex_init(&_mutex, NULL);
    pthread_cond_init(&_cond_var, NULL);
    _is_running = false;
    _status = true;
    task1 = NULL;
    task2 = NULL;
    pthread_create(&_thread, NULL, startThread, this);
}

void Worker::run() {

    if (_is_running)
        return;
    pthread_mutex_lock(&_mutex);
    _is_running = true;
    pthread_mutex_unlock(&_mutex);

    Work:
        //Lock mutex
        pthread_mutex_lock(&_mutex);
        //Check if we have task and status run
        while (_status && !task1)
            pthread_cond_wait(&_cond_var, &_mutex);
        //if status end return to end Run routine
        if (!_status && !task1)
        {
            //Don't forget this unlock for avoid deadlock
            pthread_mutex_unlock(&_mutex);
            return;
        }
        //Unlock mutex
        pthread_mutex_unlock(&_mutex);
        execTask();
        goto Work;
}

void Worker::execTask() {

    if (task1)
    {
        Task *tmp;
        //Execute task, delete and move task2 in task1
        task1->exec();
        tmp = task1;
        task1 = task2;
        task2 = NULL;
        delete tmp;
        //std::cout << task1 << std::endl;
        //std::cout << task2 << std::endl;
    }
}

Worker::~Worker() {

    //std::cout << "Start delete" << std::endl;
    if (_is_running)
    {
        //std::cout << id << "Wait task1 null" << std::endl;
        while (task1) { usleep(200); }

        //Avoid race condition on status
        pthread_mutex_lock(&_mutex);
        _status = false;
        pthread_mutex_unlock(&_mutex);
        //Wake Up the thread
        pthread_cond_signal(&_cond_var);
        //Join and release memory use by thread
        pthread_join(_thread, NULL);
    }
    if (task1)
        delete task1;
    if (task2)
        delete task2;
}

void *Worker::startThread(void *worker) {

    Worker *w;

    w = static_cast<Worker *>(worker);
    w->run();
    return NULL;
}

Worker::Worker(pthread_mutex_t mutex) : id(uniqueID()) {
    _mutex = mutex;
}

bool Worker::addTask(Task *task) {

    if (task1 && task2)
        return false;
    //Lock mutex for avoid race condition on task
    pthread_mutex_lock(&_mutex);

    if (task1 == NULL)
        task1 = task;
    else
        task2 = task;
    //After add new task send signal for wake up thread and excute task
    pthread_cond_signal(&_cond_var);
    //Unlock mutex
    pthread_mutex_unlock(&_mutex);
    return true;
}

size_t Worker::uniqueID() {
    static size_t i = 0;
    return (++i);
}















