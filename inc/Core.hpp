#ifndef CORE_HPP
# define CORE_HPP

class Core {
private:
    int			nbThreads;
public:
    Core ();
    Core (int);
    virtual ~Core ();
    int			getNbThreads() const;
    void		setNbThreads(int);
};

#endif /* !CORE_HPP */
