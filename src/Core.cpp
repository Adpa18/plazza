#include "Core.hpp"

Core::Core()
{

}

Core::Core(int threads)
{
    this->nbThreads = threads;
}

Core::~Core()
{

}

void		Core::setNbThreads(int threads)
{
    this->nbThreads = threads;
}

int			Core::getNbThreads() const
{
    return (this->nbThreads);
}
