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

class Thread : public AThreadable {

private:
    //Current task
    std::function<void *(void *)>   _task;

    //Task's param
    void                            *_param;

    //Task's result
    void                            *_result;

private:

    //Execute the task
    void *exec() const;

protected:
    virtual void run();

public:
    Thread();

    virtual ~Thread();

    void runTask(std::function<void *(void *)> func, void *param);

    //          GETTER          //
public:
    //Get task's result
    void *getResult() const;


    //          SETTER          //
public:
    //Set the task
    void   setTask(std::function<void *(void *)> func, void *);
};
#endif //THREAD_THREAD_HPP
