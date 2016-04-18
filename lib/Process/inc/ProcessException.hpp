#ifndef PROCESSEXCEPTION_HPP_
# define PROCESSEXCEPTION_HPP_

# include "Exception.hpp"
# include <cstring>

class ProcessException : public Exception {
public:
    ProcessException (std::string const &msg) throw();
    virtual ~ProcessException () throw();
};

#endif /* !PROCESSEXCEPTION_HPP_ */
