#ifndef PLAZZA_HPP
# define PLAZZA_HPP

# include <vector>
# include "Process.hpp"
# include "Thread.hpp"

class Plazza {
private:
    unsigned int            nbThreads;
    Process                 *process;
    std::vector<Thread *>   threads;
public:
    Plazza (unsigned int nbThreads);
    virtual ~Plazza ();
    void    init();
public:
    static void    run(unsigned int nbThreads);
};

#endif /* !PLAZZA_HPP */
