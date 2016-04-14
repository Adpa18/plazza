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


// #include <iostream>
// #include "ThreadPool.hpp"
//
// using namespace std;
//
// void *print(void *param)
// {
//     std::cout << (char *)param << std::endl;
//     return (NULL);
// }
//
// void *printinf(void *param)
// {
//     while (42){
//         std::cout << (char *)param << std::endl;
//         sleep(3);
//     }
//     return (NULL);
// }
//
// int main() {
//     Mutex   mutex;
//     ThreadPool *pool = new ThreadPool(mutex, 4);
//
//     pool->enqueue(print, (void *)"hey");
//     pool->enqueue(print, (void *)"coucou1");
//     delete pool;
//     std::cout << "end" << std::endl;
//     return 0;
// }
