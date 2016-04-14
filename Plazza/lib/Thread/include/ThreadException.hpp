//
// Created by babiole on 11/04/16.
//

#ifndef THREAD_THREADEXCEPTION_HPP
#define THREAD_THREADEXCEPTION_HPP


#include <stdexcept>

class ThreadException : public std::exception {
private:
    const std::string _msg;
public:
    ThreadException(const std::string &msg);
    ~ThreadException() throw();
    const char* what() const throw();
};


#endif //THREAD_THREADEXCEPTION_HPP
