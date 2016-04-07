#include "Process.hpp"

    Process::Process(fptr callback)
{
    pid_t   pid;

    if ((pid = fork()) == 0) {
        if (callback) {
            callback();
        }
    } else if (pid == -1) {
        throw std::bad_alloc();
    }
}

Process::~Process()
{

}

bool    Process::exec(fptr func)
{
    func();
    return (true);
}
