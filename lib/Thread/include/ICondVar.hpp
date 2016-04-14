//
// Created by consta_n on 14/04/16.
//

#ifndef PLAZZA_ICONDVAR_HPP
#define PLAZZA_ICONDVAR_HPP


class ICondVar {
public:
    virtual void wait(void) = 0;
    virtual void signal(void) = 0;
    virtual void broadcast(void) = 0;
};


#endif //PLAZZA_ICONDVAR_HPP