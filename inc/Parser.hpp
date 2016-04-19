#ifndef PARSER_HPP
# define PARSER_HPP

# include <string>
# include <vector>
# include <stack>
# include <utility>
# include <iostream>
# include <sstream>
# include "Information.hpp"

class Parser {
private:
    std::string str;
public:
    Parser ();
    virtual ~Parser ();
    static std::vector<std::pair<Information, std::stack<std::string>>> parse(const std::string &line);
    static std::pair<Information, std::stack<std::string>>              parseLine(const std::string &line);
    static std::vector<std::string>                                     split(std::string str, char c);
};

#endif /* !PARSER_HPP */
