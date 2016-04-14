//
// Created by consta_n on 14/04/16.
//

#include "ThreadException.hpp"

ThreadException::ThreadException(std::string const &msg) throw() : Exception(msg) { }

ThreadException::~ThreadException() { }