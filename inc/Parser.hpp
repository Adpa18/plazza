#ifndef PARSER_HPP
# define PARSER_HPP

# include <string>
# include <vector>
# include <stack>
# include <utility>
# include <iostream>
# include <sstream>
# include "Information.hpp"

namespace Parser
{
    std::vector<std::pair<Information, std::string>> parse(const std::string &line);
    std::pair<Information, std::stack<std::string>>  parseLine(const std::string &line);
    std::vector<std::string>                         split(std::string str, char c);
}

#endif /* !PARSER_HPP */
