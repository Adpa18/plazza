#include "Process.hpp"

Process::Process(int threads) : nbThreads(threads)
{

}

Process::Process()
{

}

Process::~Process()
{

}

int		Process::getNbThreads() const
{
    return (this->nbThreads);
}

void	Process::setNbThreads(int threads)
{
    this->nbThreads = threads;
}
