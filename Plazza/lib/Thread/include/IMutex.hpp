//
// Created by consta_n on 14/04/16.
//

#ifndef PLAZZA_IMUTEX_HPP
#define PLAZZA_IMUTEX_HPP

class IMutex {
public:
    virtual ~IMutex(void) {};
    virtual void lock(void) = 0;
    virtual void unlock(void) = 0;
    virtual bool trylock(void) = 0;
};

#endif //PLAZZA_IMUTEX_HPP
