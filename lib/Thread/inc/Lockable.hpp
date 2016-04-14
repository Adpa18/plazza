//
// Created by consta_n on 14/04/16.
//

#ifndef PLAZZA_LOCKABLE_HPP
#define PLAZZA_LOCKABLE_HPP

#include "Mutex.hpp"

class Lockable {
private:
    Mutex   _mutex;

public:
    Lockable(Mutex const &mutex);
    virtual  ~Lockable();

public:
    Mutex const &getMutex() const;

};


#endif //PLAZZA_LOCKABLE_HPP
