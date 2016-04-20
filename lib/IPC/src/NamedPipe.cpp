#include "NamedPipe.hpp"

NamedPipe::NamedPipe(const std::string &fileName) : fileName(fileName + ".fifo")
{
    mkfifo(this->fileName.c_str(), S_IWUSR | S_IRUSR | S_IRGRP);
}

NamedPipe::~NamedPipe()
{

}

std::string     NamedPipe::getFileName(void) const
{
    return (this->fileName);
}

void            NamedPipe::send(const std::string &str) const
{
    std::ofstream       file;

    file.open(this->getFileName());
    file << str;
    file.close();
}

std::string     NamedPipe::recv() const
{
    std::ifstream   file;
    std::string     str;

    file.open(this->getFileName());
    str = std::string((std::istreambuf_iterator<char>(file)),
                 std::istreambuf_iterator<char>());
    file.close();
    return (str);
}

void            NamedPipe::destroy()
{
    unlink(this->fileName.c_str());
}

std::ostream    &operator<<(std::ostream &stream, const NamedPipe &obj)
{
    return (stream << obj.recv());
}
