#include "Plazza.hpp"

Plazza::Plazza(unsigned int nbThreads) : nbThreads(nbThreads)
{
    this->newProcess(nullptr);
}

Plazza::~Plazza()
{

}

bool    Plazza::run()
{
    this->newProcess(new Process(nullptr));
    return (true);
}

bool    Plazza::newProcess(Process *ptr)
{
    t_plazza    plazza;

    plazza.process = ptr;
    for (unsigned int i = 0; i < this->nbThreads; i++) {
        plazza.threads.push_back(new Thread());
    }
    this->plazzas.push_back(plazza);
}
