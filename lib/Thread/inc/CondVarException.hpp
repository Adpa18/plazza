//
// Created by consta_n on 14/04/16.
//

#ifndef PLAZZA_CONDVAREXCEPTION_HPP
#define PLAZZA_CONDVAREXCEPTION_HPP


#include "Exception.hpp"

class CondVarException : public Exception {
public:
    CondVarException(std::string const &msg) throw();
    virtual ~CondVarException() throw();
};


#endif //PLAZZA_CONDVAREXCEPTION_HPP
