//
// Created by babiole on 11/04/16.
//

#include "ThreadException.hpp"

ThreadException::ThreadException(const std::string &msg) : _msg(msg)
{ }

ThreadException::~ThreadException() throw() { }

const char* ThreadException::what() const throw() {
    return _msg.c_str();
}

