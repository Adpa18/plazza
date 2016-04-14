//
// Created by babiole on 12/04/16.
//

#ifndef THREAD_ATHREADABLE_HPP
#define THREAD_ATHREADABLE_HPP

#include <pthread.h>
#include <cstring>
#include "ThreadException.hpp"

class AThreadable {

public:
    //Available State for the thread
    enum ThreadStatus {
        RUN,
        PAUSE,
        END
    };

protected:
    //The thread
    pthread_t                       _thread;

    //The thread's status
    ThreadStatus                    _status;


protected:
    //Virtual method run (this function is call by the static function 'routine')
    virtual void run() = 0;

public:
    //Constructor
    AThreadable();

    //Destructor
    virtual ~AThreadable() {};

    void join();

public:
    //Get the current thread
    pthread_t       getThread() const;
    AThreadable::ThreadStatus    getStatus() const;

public:
    //Set the status
    void setStatus(ThreadStatus status);

private:
    //This function call a non static member function (use by pthread_create)
    static void *routine(void * This);
};


#endif //THREAD_ATHREADABLE_HPP
