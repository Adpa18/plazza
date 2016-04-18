#include "ProcessException.hpp"

ProcessException::ProcessException(std::string const &msg) throw() : Exception(msg)
{

}

ProcessException::~ProcessException() throw()
{

}
