//
// Created by consta_n on 14/04/16.
//

#ifndef PLAZZA_MUTEXEXCEPTION_HPP
#define PLAZZA_MUTEXEXCEPTION_HPP


#include "Exception.hpp"

class MutexException : public Exception {
public:
    MutexException(std::string const &msg) throw();
    virtual ~MutexException() throw();
};


#endif //PLAZZA_MUTEXEXCEPTION_HPP
