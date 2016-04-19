#include <string>
#include <iostream>
#include <csignal>
#include <exception>
#include "Plazza.hpp"

void    kill(int)
{
    throw std::exception();
}

int		main(int ac, char **av)
{
    Plazza	       *plazza;
    unsigned int	nb_threads;

    if (ac < 2 || (nb_threads = std::stoi(av[1])) == 0) {
        std::cerr << "USAGE : ./plazza [NB_THREADS]" << std::endl;
        return (1);
    }
    std::signal(SIGINT, &kill);
    plazza = new Plazza(nb_threads);
    try {
        plazza->run();
    } catch(std::exception &e) {
        std::cerr << "Killed by SIGINT" << std::endl;
    }
    delete plazza;
    return (0);
}
