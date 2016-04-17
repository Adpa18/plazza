#ifndef PLAZZA_HPP
# define PLAZZA_HPP

# include "Parser.hpp"

class Plazza {
private:
    unsigned int    nbThreads;
    // std::vector<std::pair<Information, std::stack<std::string>>> orders;
public:
    Plazza (unsigned int nbThreads);
    virtual ~Plazza ();
    void    run();
};

#endif /* !PLAZZA_HPP */
