#ifndef PROCESS_HPP
# define PROCESS_HPP

# include <unistd.h>
# include <iostream>

typedef void (*fptr)();

class Process {
private:
public:
    Process (fptr callback);
    virtual ~Process ();
};

#endif /* !PROCESS_HPP */
