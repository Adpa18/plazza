//
// Created by babiole on 11/04/16.
//

#ifndef THREAD_THREAD_HPP
#define THREAD_THREAD_HPP

#include <cstdlib>
#include <functional>
#include <pthread.h>
#include <unistd.h>
#include "AThreadable.hpp"
#include "Task.hpp"
#include "Mutex.hpp"

class Worker : public AThreadable {

private:
    //Current task
    Task    *m_task[2];

    Mutex   m_mutex;

    //Task's result
    void    *m_result;

private:

    //Execute the task
    void *exec();

protected:
    virtual void run();

public:
    Worker();

    virtual ~Worker();

    bool addTask(Task *task);

    //          GETTER          //
public:
    //Get task's result
    void *getResult() const;


    //          SETTER          //
public:
    //Set the task
};
#endif //THREAD_THREAD_HPP
