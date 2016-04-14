//
// Created by consta_n on 14/04/16.
//

#include "../inc/CondVar.hpp"


CondVar::CondVar() {
    if (pthread_cond_init(&m_cond_var, NULL))
        CondVarException(strerror(errno));
}

void CondVar::wait(Mutex const &mutex) {
    if (pthread_cond_wait(&m_cond_var, const_cast<pthread_mutex_t *>(mutex.getMutex())))
        CondVarException(strerror(errno));
}


void CondVar::signal(void) {
    if (pthread_cond_signal(&m_cond_var))
        CondVarException(strerror(errno));
}

void CondVar::broadcast(void) {
    if (pthread_cond_broadcast(&m_cond_var))
        CondVarException(strerror(errno));
}

pthread_cond_t CondVar::getCondVar() const {
    return m_cond_var;
}

CondVar::~CondVar() {
    if (pthread_cond_destroy(&m_cond_var))
        Exception(strerror(errno));
}












