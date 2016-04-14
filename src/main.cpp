//
// Created by consta_n on 12/04/16.
//

#include <iostream>
#include "ThreadPool.hpp"

void *print(void *param)
{
    std::cout << (char *)param << std::endl;
    return  NULL;
}

void *printinf(void *param)
{
    while (42){
        std::cout << (char *)param << std::endl;
        sleep(3);
    }
    return NULL;
}

int main()
{
    Mutex mutex;
    ThreadPool *pool = new ThreadPool(mutex, 4);

    pool->enqueue(print, (void *)"hey");
    pool->enqueue(print, (void *)"coucou1");
    delete pool;
    std::cout << "end" << std::endl;
    return 0;
}
