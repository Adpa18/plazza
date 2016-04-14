#include <string>
#include <iostream>

#include "Plazza.hpp"
#include "ThreadPool.hpp"
#include "Mutex.hpp"

int		main(int ac, char **av)
{
    unsigned int	nb_threads;
    Plazza	       *plazza;

    if (ac < 2 || (nb_threads = std::stoi(av[1])) == 0) {
        std::cerr << "USAGE : ./plazza [NB_THREADS]" << std::endl;
        return (1);
    }
    plazza = new Plazza(nb_threads);
    plazza->run();
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
//int main()
//{
//    Mutex mutex;
//    ThreadPool *pool = new ThreadPool(mutex, 4);
//
//    pool->enqueue(new Task(print, (void *)"hey"));
//    pool->enqueue(new Task(print, (void *)"coucou1"));
//    pool->enqueue(new Task(print, (void *)"he1"));
//    pool->enqueue(new Task(print, (void *)"he2"));
//    pool->enqueue(new Task(print, (void *)"hey3"));
//    delete pool;
//    std::cout << "end" << std::endl;
//    return 0;
//}
