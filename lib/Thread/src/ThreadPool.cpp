//
// Created by consta_n on 19/04/16.
//

#include <iostream>
#include <unistd.h>
#include "ThreadPool.hpp"

ThreadPool::ThreadPool(size_t size) : m_size(size) {

    pthread_mutex_init(&m_mutex, NULL);
    for (size_t i = 0; i < m_size; ++i) {
        m_workers.push_back(new Worker());
    }
    m_status = false;
}

void ThreadPool::start()
{
    pthread_create(&m_thread, NULL, startThread, this);
}

void ThreadPool::run() {

    pthread_mutex_lock(&m_mutex);
    if (m_status)
        return;
    m_status = true;
    pthread_mutex_unlock(&m_mutex);
    while (m_status) {
        for (std::vector<Worker *>::const_iterator worker = m_workers.begin(); worker != m_workers.end(); worker++)
        {
            while (!m_tasks.empty()) {
                if (!(*worker)->addTask(m_tasks.front()))
                    break;
                else {
                    m_tasks.pop();
                }
            }
        }
    }
}

ThreadPool::~ThreadPool() {

    while (!m_tasks.empty()) { usleep(200); };
    pthread_mutex_lock(&m_mutex);
    m_status = false;

    for (size_t j = 0; j < m_size; ++j) {
        delete m_workers[j];
    }
    pthread_mutex_unlock(&m_mutex);
    pthread_join(m_thread, NULL);
}

void ThreadPool::addTask(Task *task) {

    pthread_mutex_lock(&m_mutex);
    m_tasks.push(task);
    pthread_mutex_unlock(&m_mutex);
}

void *ThreadPool::startThread(void *arg) {

    ThreadPool *pool;

    pool = static_cast<ThreadPool *>(arg);
    pool->run();
    return NULL;
}
