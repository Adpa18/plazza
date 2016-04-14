//
// Created by consta_n on 14/04/16.
//

#ifndef PLAZZA_CONDVAR_HPP
#define PLAZZA_CONDVAR_HPP

#include <sys/types.h>
#include "ICondVar.hpp"
#include "Mutex.hpp"
#include "CondVarException.hpp"

class CondVar : public ICondVar {
private:
    pthread_cond_t  m_cond_var;
public:
    CondVar();
    ~CondVar();
    virtual void wait(Mutex const &mutex);
    virtual void signal(void);
    virtual void broadcast(void);

public:
    pthread_cond_t getCondVar() const;
};


#endif //PLAZZA_CONDVAR_HPP
