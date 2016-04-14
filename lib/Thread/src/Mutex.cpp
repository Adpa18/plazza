//
// Created by consta_n on 4/12/16.
//

#include "Mutex.hpp"

Mutex::Mutex() {
    _mutex = PTHREAD_MUTEX_INITIALIZER;
    //Not check because pthread_mutex_init ALWAYS return 0
    pthread_mutex_init(&_mutex, NULL);
}

inline void Mutex::lock() {
    if (pthread_mutex_lock(&_mutex))
        throw ThreadException(strerror(errno));
}

inline bool Mutex::trylock() {
    if (pthread_mutex_trylock(&_mutex) == 0)
        return true;
    perror("");
    return false;
}

Mutex::~Mutex() {

}
