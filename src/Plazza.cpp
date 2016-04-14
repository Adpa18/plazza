#include "Plazza.hpp"
#include <iostream>
#include "NamedPipe.hpp"

Plazza::Plazza(unsigned int nbThreads) : nbThreads(nbThreads)
{

}

Plazza::~Plazza()
{

}

void    Plazza::run()
{
    std::string     line;
    NamedPipe       pla("plazza");
    unsigned int    nbOrders;

    for (;;) {
        std::getline(std::cin, line);
        // get by parsing
        nbOrders = 2;
        while (--nbOrders > 0) {
            std::cout << pla << std::endl;
        }
    }
}
