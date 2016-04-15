#ifndef PLAZZA_HPP
# define PLAZZA_HPP

# include <vector>
# include <stack>
# include <utility>
# include <string>

enum Information { PHONE_NUMBER, EMAIL_ADDRESS, IP_ADDRESS };

class Plazza {
private:
    unsigned int    nbThreads;
    std::vector<std::pair<Information, std::stack<std::string> > > orders;
public:
    Plazza (unsigned int nbThreads);
    virtual ~Plazza ();
    void    run();
};

#endif /* !PLAZZA_HPP */
