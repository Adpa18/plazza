#include <Manager.hpp>
#include "Process.hpp"
#include "Decrypt.hpp"

Manager::Manager(unsigned int nbThreads, const std::string &pipeName) : free_places(2 * nbThreads), pipe(pipeName)
{
    this->process = new Process([nbThreads, pipeName](){Manager::run(nbThreads, pipeName);});
}

Manager::~Manager()
{
    delete this->process;
    this->pipe.destroy();
}

void    Manager::run(unsigned int nbThreads, const std::string &pipeName)
{
    NamedPipe   pipe(pipeName);
    ThreadPool  *pool;

    pool = new ThreadPool(nbThreads);
    pool->start();
    for(;;) {
        std::vector<std::string> orders = Parser::split(pipe.recv(), ';');
        for (const std::string str : orders) {
            std::pair<Information, std::stack<std::string>> order = Parser::parseLine(str);
            pool->addTask(new Task([order](){Manager::decode(order.first, order.second.top());}));
        }
    }
    delete pool;
}

void    Manager::decode(Information info, std::string fileName)
{
    NamedPipe               pla(FIFO_PLAZZA);
    std::string             answer = "";

    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string str = std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        std::vector<std::string> ret = Manager::decrypt(str, Find::map_info_regex[info]);
        for (std::string aws : ret) {
            answer += aws + "|";
        }
    }
    file.close();
    if (answer.empty()) {
        answer = "NOTHING";
    }
    pla.send(answer + ";");
}

std::vector<std::string>    Manager::decrypt(const std::string &str, std::regex reg)
{
    std::vector<std::string>    ret;

    ret = Find::findInfo(str, reg);
    if (!ret.empty()) {
        return (ret);
    }
    for (unsigned char c = 0; c < 255; c++) {
        ret = Find::findInfo(Decrypt::Caesar(str, c), reg);
        if (!ret.empty()) {
            return (ret);
        }
    }
    for (size_t key = 0; key < 65536; key++) {
        Decrypt::Xor(str, key);
        ret = Find::findInfo(Decrypt::Xor(str, key), reg);
        if (!ret.empty()) {
            return (ret);
        }
    }
    return (ret);
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
