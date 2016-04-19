#include "Decrypt.hpp"

std::string Decrypt::Caesar(const std::string &str, char c)
{
    std::string     u_str(str);
    for (size_t i = 0; i < str.length(); i++) {
        u_str[i] -= c;
    }
    return (u_str);
}

std::string Decrypt::Xor(const std::string &str, int key)
{
    std::string     u_str(str);

    for (size_t i = 0; i < str.length(); i++) {
        u_str[i] = str[i] ^ key;
    }
    return (u_str);
}
