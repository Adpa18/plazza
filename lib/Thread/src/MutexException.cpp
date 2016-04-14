//
// Created by consta_n on 14/04/16.
//

#include "../inc/MutexException.hpp"

MutexException::MutexException(std::string const &msg) throw() : Exception(msg) { }

MutexException::~MutexException() { }