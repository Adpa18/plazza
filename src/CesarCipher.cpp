#include "CesarCipher.hpp"

Cesar::Cesar(std::string &str)
{
    this->str = str;
    this->c = 0;
}

Cesar::~Cesar()
{

}

void				Cesar::uncipher()
{
    for (size_t i = 0; i < this->str.length(); i++) {
        this->str[i]--;
    }
    this->c++;
}

const std::string	&Cesar::getStr() const
{
    return (this->str);
}

void				Cesar::setStr(std::string &str)
{
    this->str = str;
    this->c = 0;
}

void				Cesar::resetChar()
{
    this->c = 0;
}

bool				Cesar::isEnd()
{
    if (this->c == 255) {
        return (true);
    } else {
        return (false);
    }
}
