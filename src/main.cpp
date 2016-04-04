#include "plazza.hpp"

int		main(int ac, char **av)
{
    int	nb_threads;

    if (ac < 2 || (nb_threads = atoi(av[1])) == 0) {
        ERROR(USAGE, -1);
    }
    std::cout << "You want us to use " << nb_threads << " threads per process." << std::endl << "Cordially." << std::endl;
    return (0);
}
