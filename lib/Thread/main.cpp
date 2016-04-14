#include <iostream>
#include "include/ThreadPool.hpp"

using namespace std;

void *print(void *param)
{
    std::cout << (char *)param << std::endl;
}

void *printinf(void *param)
{
    while (42){
        std::cout << (char *)param << std::endl;
        sleep(3);
    }
}

int main() {
    ThreadPool *pool = new ThreadPool(4);

    pool->queueTask(print, (void *)"hey");
    pool->queueTask(print, (void *)"coucou1");
    delete pool;
    std::cout << "end" << std::endl;
    return 0;
}