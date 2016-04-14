//
// Created by consta_n on 14/04/16.
//

#include "../inc/CondVarException.hpp"

CondVarException::CondVarException(std::string const &msg) throw() : Exception(msg) { }

CondVarException::~CondVarException() { }