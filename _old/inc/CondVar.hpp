#ifndef CONDVAR_HPP
# define CONDVAR_HPP

# include <pthread.h>

class CondVar {
private:
    pthread_cond_t	cond;
    pthread_mutex_t	mutex;
public:
    CondVar ();
    virtual ~CondVar ();

};

#endif /* !CONDVAR_HPP */
