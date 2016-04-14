//
// Created by consta_n on 14/04/16.
//

#ifndef PLAZZA_THREADEXCEPTION_HPP
#define PLAZZA_THREADEXCEPTION_HPP

#include "Exception.hpp"

class ThreadException : public Exception {
public:
    ThreadException(std::string const &msg) throw();
    virtual ~ThreadException() throw();
};


#endif //PLAZZA_THREADEXCEPTION_HPP
