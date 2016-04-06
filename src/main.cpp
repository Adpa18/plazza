#include "plazza.hpp"

int		main(int ac, char **av)
{
    int		nb_threads;
    Core	core;

    if (ac < 2 || (nb_threads = atoi(av[1])) == 0) {
        ERROR(USAGE, -1);
    }
    core.setNbThreads(nb_threads);
    std::cout << "You want us to use " << core.getNbThreads() << " threads per process." << std::endl << "Cordially." << std::endl;
    return (0);
}
