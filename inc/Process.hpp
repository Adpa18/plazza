#ifndef PROCESS_HPP
# define PROCESS_HPP

class Process {
private:
    int			nbThreads;
public:
    Process ();
    Process (int);
    virtual ~Process ();
    int			getNbThreads() const;
    void		setNbThreads(int);
};

#endif /* !PROCESS_HPP */
