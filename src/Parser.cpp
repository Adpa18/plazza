#include "Parser.hpp"

Parser::Parser()
{

}

Parser::~Parser()
{

}

std::vector<std::pair<Information, std::stack<std::string>>>    Parser::parse(const std::string &line)
{
    std::vector<std::pair<Information, std::stack<std::string>>>    orders;
    std::pair<Information, std::stack<std::string>>                 pair;
    std::vector<std::string>                                        sp;
    sp = Parser::split(line, ';');
    for (const std::string &str : sp) {
        pair = Parser::parseLine(str);
        if (pair.second.empty() || pair.first == NONE) {
            continue;
        }
        orders.push_back(pair);
    }
    return (orders);
}

std::pair<Information, std::stack<std::string>> Parser::parseLine(const std::string &line)
{
    std::vector<std::string> sp = Parser::split(line, ' ');
    std::stack<std::string> tmp_files;
    Information tmp_info = NONE;
    for (const std::string &str : sp) {
        if (str == "PHONE_NUMBER") {
            tmp_info = PHONE_NUMBER;
        } else if (str == "EMAIL_ADDRESS") {
            tmp_info = EMAIL_ADDRESS;
        } else if (str == "IP_ADDRESS") {
            tmp_info = IP_ADDRESS;
        } else {
            tmp_files.push(str);
        }
    }
    return (std::pair<Information, std::stack<std::string>>(tmp_info, tmp_files));
}

std::vector<std::string>    Parser::split(std::string str, char c)
{
    std::vector<std::string>    result;
    std::string                 buffer;
    std::istringstream          iss(str);

    while (std::getline(iss, buffer, c)) {
        if (buffer.length() != 0) {
            result.push_back(buffer);
        }
    }
    return (result);
}
