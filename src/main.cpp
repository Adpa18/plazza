#include "plazza.hpp"

int		main(int ac, char **av)
{
    int	nb_threads;

    if (ac < 3 || (nb_threads = atoi(av[1])) == 0) {
        ERROR(USAGE, -1);
    }
    return (0);
}
