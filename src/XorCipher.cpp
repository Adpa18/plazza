#include "XorCipher.hpp"

XorCipher::XorCipher(std::string &str)
{
    this->firstStr = str;
    this->str = std::string(str);
    this->key = 0;
}

XorCipher::~XorCipher()
{

}

void				XorCipher::uncipher()
{
    for (size_t i = 0; i < this->firstStr.length(); i++) {
        this->str[i] = this->firstStr[i] ^ this->key;
    }
}

const std::string	&XorCipher::getString() const
{
    return (this->str);
}

void				XorCipher::setString(std::string str)
{
    this->str = str;
}

const std::string	&XorCipher::getOriginalString() const
{
    return (this->firstStr);
}

void				XorCipher::setOriginalString(std::string &str)
{
    this->firstStr = str;
}


void				XorCipher::resetKey()
{
    this->key = 0;
}
