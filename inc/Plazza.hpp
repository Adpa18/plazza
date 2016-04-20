#ifndef PLAZZA_HPP
# define PLAZZA_HPP

# include "Parser.hpp"
# include "Manager.hpp"

class Plazza {
private:
    unsigned int            nbThreads;
    std::vector<Manager *>  managers;
    std::vector<std::pair<Information, std::stack<std::string>>>    orders;
    NamedPipe               pla;
    bool                    killed;

public:
    Plazza (unsigned int nbThreads);
    virtual ~Plazza ();
    void            run();
    Manager         *&getAvaibleManager();
    std::string     getOrder(std::pair<Information, std::stack<std::string>>) const;
    void            kill();
};

#endif /* !PLAZZA_HPP */
