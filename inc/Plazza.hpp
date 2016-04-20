#ifndef PLAZZA_HPP
# define PLAZZA_HPP

# include "Parser.hpp"
# include "Manager.hpp"

class Plazza {
private:
    std::vector<std::pair<Information, std::string>> orders;
    unsigned int            nbThreads;
    std::vector<Manager *>  managers;
    NamedPipe               pla;
    bool                    killed;

public:
    Plazza (unsigned int nbThreads);
    virtual ~Plazza ();
    void            run();
    Manager         *&getAvaibleManager();
    std::string     getOrder(std::pair<Information, std::string> order) const;
    void            kill();
};

#endif /* !PLAZZA_HPP */
