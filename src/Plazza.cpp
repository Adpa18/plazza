#include "Plazza.hpp"
#include "NamedPipe.hpp"
#include <iostream>
#include <atomic>

Plazza::Plazza(unsigned int nbThreads) : nbThreads(nbThreads)
{

}

Plazza::~Plazza()
{
    for (Manager *&manager : this->managers) {
        delete manager;
    }
}

void    Plazza::run()
{
    NamedPipe       pla(FIFO_PLAZZA);

    for (;;) {
        Manager *manager;
        std::string line;
        unsigned int count = 0;
        while (line.empty()) {
            std::getline(std::cin, line);
        }
        this->orders = Parser::parse(line);
        for (std::pair<Information, std::stack<std::string>> order : this->orders) {
            manager = this->getAvaibleManager();
            manager->sendOrder(this->getOrder(order));
            manager->decFreePlaces();
            ++count;
        }
        for (size_t i = 0; i < count; i++) {
            std::cout << pla.recv() << std::endl;
        }
        this->orders.clear();
    }
}

Manager     *&Plazza::getAvaibleManager()
{
    for (Manager *&manager : this->managers) {
        if (manager->getFreePlaces() > 0) {
            return (manager);
        }
    }
    this->managers.push_back(new Manager(this->nbThreads * 2, "Process" + std::to_string(this->managers.size())));
    return (this->managers[this->managers.size() - 1]);
}

std::string     Plazza::getOrder(std::pair<Information, std::stack<std::string>> order) const
{
    std::string full_order = "";
    while (!order.second.empty()) {
        full_order += order.second.top() + " ";
        order.second.pop();
    }
    full_order += order.first;
    return (full_order);
}
