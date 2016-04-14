//
// Created by babiole on 11/04/16.
//

#ifndef THREAD_THREADEXCEPTION_HPP
#define THREAD_THREADEXCEPTION_HPP


#include <stdexcept>

class Exception : public std::exception {
protected:
    const std::string m_msg;
public:
    Exception(std::string const &msg) throw();
    virtual ~Exception(void) throw();
    virtual const char* what(void) const throw();
};


#endif //THREAD_THREADEXCEPTION_HPP
