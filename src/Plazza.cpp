#include "Plazza.hpp"
#include "NamedPipe.hpp"
#include <iostream>
#include <atomic>

Plazza::Plazza(unsigned int nbThreads) : nbThreads(nbThreads), pla(FIFO_PLAZZA), killed(false)
{

}

Plazza::~Plazza()
{
    for (Manager *&manager : this->managers) {
        delete manager;
    }
    this->pla.destroy();
}

void    Plazza::run()
{
    for (;;) {
        if (killed) {
            break;
        }
        Manager *manager;
        std::string line;
        unsigned int count = 0;
        // std::cout << "Enter command : ";
        std::getline(std::cin, line);
        if (std::cin.eof() == true) {
            break;
        }
        this->orders = Parser::parse(line);
        if (this->orders.empty()) {
            // std::cerr << "Unknow command" << std::endl;
            continue;
        }
        for (std::pair<Information, std::string> order : this->orders) {
            manager = this->getAvaibleManager();
            manager->sendOrder(this->getOrder(order));
            manager->decFreePlaces();
            ++count;
        }
        while (count) {
            std::string str = pla.recv();
            std::vector<std::string> recvs = Parser::split(str, ';');
            for (std::string recv : recvs) {
                std::vector<std::string> strs = Parser::split(recv, '|');
                for (std::string answer : strs) {
                    if (answer != "NOTHING") {
                        std::cout << answer << std::endl;
                    }
                }
                --count;
            }
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

std::string     Plazza::getOrder(std::pair<Information, std::string> order) const
{
    return (order.second + " " + Find::map_info_str[order.first] + ";");
}

void            Plazza::kill()
{
    this->killed = true;
}
