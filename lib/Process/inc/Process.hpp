#ifndef PROCESS_HPP_
# define PROCESS_HPP_

# include "ProcessException.hpp"
# include <functional>
# include <unistd.h>
# include <vector>

class Process {
private:
    std::vector<pid_t>	pid;
public:
    Process ();
    virtual ~Process ();
    pid_t						init(std::function<int()> &);
    const std::vector<pid_t>	getPid() const;
    void						sendSignal(pid_t, int);
    void						sendSignalAll(int);
};

#endif /* !PROCESS_HPP_ */
