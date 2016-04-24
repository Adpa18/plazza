#ifndef MANAGER_HPP
# define MANAGER_HPP

# include "Process.hpp"
# include "ThreadPool.hpp"
# include "Information.hpp"
# include "NamedPipe.hpp"
# include "Parser.hpp"
# include "Find.hpp"
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
    static void     decode(Information info, std::string file);
    static std::vector<std::string> decrypt(const std::string &str, std::string reg);
    unsigned int    getFreePlaces() const;
    void            incFreePlaces();
    void            decFreePlaces();
    const NamedPipe &getNamedPipe() const;
    void            sendOrder(const std::string &order);
};

#endif /* !MANAGER_HPP */
