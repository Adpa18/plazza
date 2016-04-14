//
// Created by consta_n on 14/04/16.
//

#include "../inc/Task.hpp"

Task::Task(std::function<void *(void *)> const &func, void *param) : m_func(func) {
    m_param = param;
}

void const *Task::getResult() const {
    return m_result;
}

void Task::operator()() {
    run();
}

void *Task::run() {
    m_result = m_func(m_param);
    return m_result;
}

std::function<void *(void *)> const &Task::getFunc() const {
    return m_func;
}

void const *Task::getParam() const {
    return m_param;
}

Task::~Task() { }















