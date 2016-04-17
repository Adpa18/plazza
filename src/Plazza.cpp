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

    (void)this->nbThreads;
    for (;;) {
        std::getline(std::cin, line);
        std::vector<std::pair<Information, std::stack<std::string>>> orders = Parser::parse(line);
        for (size_t i = 0; i < orders.size(); i++) {

        }
        for (size_t i = 0; i < orders.size(); i++) {
            std::cout << pla << std::endl;
        }
        orders.clear();
    }
}
