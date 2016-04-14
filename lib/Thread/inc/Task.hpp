//
// Created by consta_n on 14/04/16.
//

#ifndef PLAZZA_TASK_HPP
#define PLAZZA_TASK_HPP

#include <functional>

class Task {

private:
    void                            *m_param;
    std::function<void *(void *)>   m_func;
    void                            *m_result;

public:
    Task(std::function<void *(void *)> const &func, void *param);
    ~Task();
    void operator()();
    void *run();

public:
    void const                       *getResult() const;
    std::function<void *(void *)>  const  &getFunc() const;
    void const                       *getParam() const;
};


#endif //PLAZZA_TASK_HPP
