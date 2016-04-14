//
// Created by consta_n on 4/12/16.
//

#include "Mutex.hpp"

Mutex::Mutex() {
    m_mutex = PTHREAD_MUTEX_INITIALIZER;
    //Not check because pthread_mutex_init ALWAYS return 0
    pthread_mutex_init(&m_mutex, NULL);
}

inline void Mutex::lock() {
    if (pthread_mutex_lock(&m_mutex))
        throw MutexException(strerror(errno));
}

inline void Mutex::unlock() {
    if (pthread_mutex_lock(&m_mutex))
        throw MutexException(strerror(errno));
}

inline bool Mutex::trylock() {
    if (pthread_mutex_trylock(&m_mutex) == 0)
        return true;
    perror("");
    return false;
}

pthread_mutex_t const *Mutex::getMutex() const {
    return &m_mutex;
}

Mutex::~Mutex() {

}


