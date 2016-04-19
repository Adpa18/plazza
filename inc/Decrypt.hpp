#ifndef DECRYPT_HPP
# define DECRYPT_HPP

# include <string>

namespace Decrypt
{
    std::string Caesar(const std::string &str, char c);
    std::string Xor(const std::string &str, int key);
}

#endif /* !DECRYPT_HPP */
