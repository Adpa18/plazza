#include <string>
#include <iostream>
#include "Plazza.hpp"

int		main(int ac, char **av)
{
    unsigned int	nb_threads;
    Plazza	       *plazza;

    if (ac < 2 || (nb_threads = std::stoi(av[1])) == 0) {
        std::cerr << "USAGE : ./plazza [NB_THREADS]" << std::endl;
        return (1);
    }
    plazza = new Plazza(nb_threads);
    (void)plazza;
    return (0);
}
