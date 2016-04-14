//
// Created by babiole on 12/04/16.
//

#include "AThreadable.hpp"

AThreadable::AThreadable() {
    if (pthread_create(&_thread, NULL, routine, this) != 0)
        throw ThreadException(strerror(errno));
}

pthread_t AThreadable::getThread() const {
    return _thread;
}

void *AThreadable::routine(void *This) {
    static_cast<AThreadable *>(This)->run();
    return NULL;
}

void AThreadable::join() {
    setStatus(ThreadStatus::END);
    if (pthread_join(_thread, NULL))
        throw ThreadException(strerror(errno));
}

AThreadable::ThreadStatus AThreadable::getStatus() const {
    return _status;
}

void AThreadable::setStatus(ThreadStatus status) {
    _status = status;
}








