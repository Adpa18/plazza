#include "Process.hpp"
#include <cstring>
#include <csignal>

Process::Process()
{

}

Process::~Process()
{

}

void				Process::sendSignal(pid_t pid, int sig)
{
    for (std::vector<pid_t>::iterator it = this->pid.begin(); it < this->pid.end(); it++) {
        if (*it == pid) {
            int	ret;

            ret = kill(pid, sig);
            if (ret == -1) {
                ProcessException(strerror(errno));
            }
        }
    }
}

void				Process::sendSignalAll(int sig)
{
    for (std::vector<pid_t>::iterator it = this->pid.begin(); it < this->pid.end(); it++) {
        int	ret;

        ret = kill(*it, sig);
        if (ret == -1) {
            ProcessException(strerror(errno));
        }
    }
}

pid_t				Process::init(std::function<int()> &func)
{
    pid_t	pid;

    pid = fork();
    if (pid == 0) {
        //child_process
        func();
    } else if (pid < 0) {
        ProcessException(strerror(errno));
    }
    this->pid.push_back(pid);
    return (pid);
}

const std::vector<pid_t>	Process::getPid() const
{
    return (this->pid);
}
