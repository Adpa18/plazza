#include "Find.hpp"
#include <iostream>

void							Find::suppSpace(std::string &str)
{
    while (*str.begin() == ' ') {
        str.erase(str.begin());
    }
    while (str[str.size() - 1] == ' ') {
        str.pop_back();
    }
}

std::vector<std::string>		Find::findInfo(std::string str, std::regex rgx)
{
    std::vector<std::string>	ret;
    std::smatch					s;
    std::string					tmp;

    while (std::regex_search(str, s, rgx)) {
        tmp = s.begin()->str();
        Find::suppSpace(tmp);
        ret.push_back(tmp);
        str = str.erase(s.position(), s.length());
    }
    return (ret);
}
