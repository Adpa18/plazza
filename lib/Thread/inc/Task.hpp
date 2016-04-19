//
// Created by consta_n on 15/04/16.
//

#ifndef THREADSAFE_TASK_HPP
#define THREADSAFE_TASK_HPP


#include <functional>

class Task {
private:
    std::function<void()> _func;
public:
    Task(std::function<void()> const &func);
    ~Task();
    void exec(void);
};


#endif //THREADSAFE_TASK_HPP
