#ifndef PLAZZA_HPP
# define PLAZZA_HPP

class Plazza {
private:
    unsigned int    nbThreads;
public:
    Plazza (unsigned int nbThreads);
    virtual ~Plazza ();
    void    run();
};

#endif /* !PLAZZA_HPP */
