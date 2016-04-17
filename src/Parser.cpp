#include "Parser.hpp"

Parser::Parser()
{

}

Parser::~Parser()
{

}

std::vector<std::pair<Information, std::stack<std::string>>>    Parser::parse(std::string line)
{
    std::vector<std::pair<Information, std::stack<std::string>>>    orders;
    std::vector<std::string>    sp = Parser::split(line, ';');
    for (std::vector<std::string>::iterator it = sp.begin() ; it != sp.end(); ++it) {
        std::vector<std::string> tmp = Parser::split(*it, ' ');
        std::stack<std::string> tmp_files;
        Information tmp_info = NONE;
        for (std::vector<std::string>::iterator it = tmp.begin() ; it != tmp.end(); ++it) {
            if (*it == "PHONE_NUMBER") {
                tmp_info = PHONE_NUMBER;
                // std::cout << "type => PHONE_NUMBER" << std::endl;
            } else if (*it == "EMAIL_ADDRESS") {
                tmp_info = EMAIL_ADDRESS;
                // std::cout << "type => EMAIL_ADDRESS" << std::endl;
            } else if (*it == "IP_ADDRESS") {
                tmp_info = IP_ADDRESS;
                // std::cout << "type => IP_ADDRESS" << std::endl;
            } else {
                tmp_files.push(*it);
                // std::cout << "file => " << *it << std::endl;
            }
        }
        if (tmp_files.empty() || tmp_info == NONE) {
            continue;
        }
        orders.push_back(std::pair<Information, std::stack<std::string>>(tmp_info, tmp_files));
    }
    return (orders);
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
