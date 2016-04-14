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
    ThreadPool *pool = new ThreadPool(4);

    pool->queueTask(print, (void *)"hey");
    pool->queueTask(print, (void *)"coucou1");
    delete pool;
    std::cout << "end" << std::endl;
    return 0;
}
