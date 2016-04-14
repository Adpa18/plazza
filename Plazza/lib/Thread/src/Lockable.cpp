//
// Created by consta_n on 14/04/16.
//

#include "Lockable.hpp"


Lockable::Lockable(Mutex const &mutex) : _mutex(mutex) {

    _mutex.lock();
}

Mutex const &Lockable::getMutex() const {
    return _mutex;
}

Lockable::~Lockable() {
    _mutex.unlock();
}





