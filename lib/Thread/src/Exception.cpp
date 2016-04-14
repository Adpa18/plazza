//
// Created by babiole on 11/04/16.
//

#include "Exception.hpp"

Exception::Exception(std::string const &msg) throw() : m_msg(msg)
{ }

Exception::~Exception(void) throw() { }

const char* Exception::what(void) const throw() {
    return m_msg.c_str();
}

