//
// Created by consta_n on 4/12/16.
//

#ifndef THREAD_MUTEX_HPP
#define THREAD_MUTEX_HPP

#include <cstring>
#include <pthread.h>
#include "IMutex.hpp"
#include "MutexException.hpp"

class Mutex : public  IMutex {
private:
    pthread_mutex_t m_mutex;

public:
    Mutex();
    ~Mutex();

    virtual void    lock();
    virtual void    unlock();
    virtual bool    trylock();

public:
    pthread_mutex_t const *getMutex() const;
};


#endif //THREAD_MUTEX_HPP
