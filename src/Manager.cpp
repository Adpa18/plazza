#include <Manager.hpp>
#include "Process.hpp"
#include "Decrypt.hpp"
#include "Find.hpp"

Manager::Manager(unsigned int nbThreads, const std::string &pipeName) : free_places(2 * nbThreads), pipe(pipeName)
{
    this->process = new Process([nbThreads, pipeName](){Manager::run(nbThreads, pipeName);});
}

Manager::~Manager()
{
    delete this->process;
}

void    Manager::run(unsigned int nbThreads, const std::string &pipeName)
{
    std::vector<std::pair<Information, std::stack<std::string>>> orders;
    NamedPipe   pipe(pipeName);
    ThreadPool  *pool;

    pool = new ThreadPool(nbThreads);
    pool->start();
    for(;;) {
        const std::string str = pipe.recv();
        pool->addTask(new Task([str](){Manager::decode(Parser::parseLine(str));}));
    }
    delete pool;
}

void    Manager::decode(std::pair<Information, std::stack<std::string>> order)
{
    Information             info = order.first;
    std::stack<std::string> files = order.second;
    NamedPipe               pla(FIFO_PLAZZA);
    std::string             answer = "couocu";

    while (!files.empty()) {
        std::ifstream file(files.top());
        files.pop();
        if (!file.is_open()) {
            continue;
        }
        std::vector<std::string>    ret;
        std::string info_str = "";
        std::string str = std::string((std::istreambuf_iterator<char>(file)),
                     std::istreambuf_iterator<char>());
        for (unsigned char c = 0; c < 255; c++) {
            ret = Find::findInfo(Decrypt::Caesar(str, c), Find::map_info[info]);
        }
        for (size_t key = 0; key < 65536; key++) {
            ret = Find::findInfo(Decrypt::Xor(str, key), Find::map_info[info]);
        }
        answer += info_str + " ";
        file.close();
    }
    pla.send(answer);
}

unsigned int    Manager::getFreePlaces() const
{
    return (this->free_places);
}

void            Manager::incFreePlaces()
{
    ++this->free_places;
}

void            Manager::decFreePlaces()
{
    --this->free_places;
}

const NamedPipe &Manager::getNamedPipe() const
{
    return (this->pipe);
}

void            Manager::sendOrder(const std::string &order)
{
    this->pipe.send(order);
}
