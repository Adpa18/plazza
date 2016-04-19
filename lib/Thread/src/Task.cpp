//
// Created by consta_n on 15/04/16.
//

#include "Task.hpp"

Task::Task(std::function<void()> const &func) : _func(func) {

}

void Task::exec(void) {
    _func();
}

Task::~Task() {

}





