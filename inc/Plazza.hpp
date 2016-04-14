#ifndef PLAZZA_HPP
# define PLAZZA_HPP

# include <vector>
# include <stack>
# include <utility>
# include <string>

enum CMD { PHONE_NUMBER, EMAIL, IP_ADRESS };

class Plazza {
private:
    unsigned int    nbThreads;
    std::vector<std::pair<CMD, std::stack<std::string>>> orders;
public:
    Plazza (unsigned int nbThreads);
    virtual ~Plazza ();
    void    run();
};

#endif /* !PLAZZA_HPP */
