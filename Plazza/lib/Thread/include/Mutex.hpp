//
// Created by consta_n on 4/12/16.
//

#ifndef THREAD_MUTEX_HPP
#define THREAD_MUTEX_HPP

#include <cstring>
#include <pthread.h>
#include "IMutex.hpp"
#include "ThreadException.hpp"

class Mutex : public  IMutex {
private:
    pthread_mutex_t _mutex;

public:
    Mutex();
    ~Mutex();

    virtual void    lock();
    virtual void    unlock();
    virtual bool    trylock();
};


#endif //THREAD_MUTEX_HPP
