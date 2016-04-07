#ifndef PLAZZA_HPP
# define PLAZZA_HPP

# include <vector>
# include "Process.hpp"
# include "Thread.hpp"

typedef struct              s_plazza {
    Process                 *process;
    std::vector<Thread*>    threads;
}                           t_plazza;

class Plazza {
private:
    unsigned int            nbThreads;
    std::vector<t_plazza>   plazzas;
public:
    Plazza (unsigned int nbThreads);
    virtual ~Plazza ();
    bool    run();
    bool    newProcess(Process *ptr);
};

#endif /* !PLAZZA_HPP */
