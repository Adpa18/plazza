#ifndef MANAGER_HPP
# define MANAGER_HPP

# include "Process.hpp"
# include "ThreadPool.hpp"
# include "Information.hpp"
# include "NamedPipe.hpp"
# include "Parser.hpp"
# include <stack>

class Manager {
private:
    unsigned int    free_places;
    Process         *process;
    NamedPipe       pipe;
public:
    Manager (unsigned int nbThreads, const std::string &pipeName);
    virtual ~Manager ();
    static void     run(unsigned int nbThreads, const std::string &pipeName);
    static void     decode(std::pair<Information, std::stack<std::string>> order);
    unsigned int    getFreePlaces() const;
    void            incFreePlaces();
    void            decFreePlaces();
    const NamedPipe &getNamedPipe() const;
    void            sendOrder(const std::string &order);
};

#endif /* !MANAGER_HPP */