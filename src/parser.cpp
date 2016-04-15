#include "Plazza.hpp"
#include <iostream>

std::vector<std::pair<Information, std::stack<std::string> > > parse(std::string &cmd)
{
    std::vector<std::pair<Information, std::stack<std::string> > >	ret;
    std::string														tmp;
    std::string														cur_cmd;
    size_t															size;
    size_t															size_tmp;
    std::stack<std::string>											sta;

    while (cmd.find(" ") == 0) {
        cmd = cmd.substr(1);
    }
    while ((size = cmd.find(";")) != std::string::npos && cmd.size() != 1) {
        std::cout << "cmd.size() = " << cmd.size() << std::endl;
        tmp = cmd.substr(0, size);
        cur_cmd = tmp.substr(0, tmp.find(" ") == std::string::npos ? tmp.size() : tmp.find(" "));
        tmp = tmp.substr(tmp.find(" ") == std::string::npos ? tmp.size() : tmp.find(" "));
        while ((size_tmp = tmp.find(" ")) != std::string::npos) {
            sta.push(tmp.substr(size_tmp));
            tmp = tmp.substr(size_tmp + 1);
        }
        sta.push(tmp);
        if (cur_cmd == "EMAIL_ADDRESS") {
            ret.push_back(std::pair<Information, std::stack<std::string> >(EMAIL_ADDRESS, sta));
        } else if (cur_cmd == "IP_ADDRESS") {
            ret.push_back(std::pair<Information, std::stack<std::string> >(IP_ADDRESS, sta));
        } else if (cur_cmd == "PHONE_NUMBER") {
            ret.push_back(std::pair<Information, std::stack<std::string> >(PHONE_NUMBER, sta));
        }
        std::cout << "in : tmp = \"" << tmp << "\"" << std::endl << "cur_cmd = \"" << cur_cmd << "\"" << std::endl;
        cmd = cmd.substr(size + 1);
        while (cmd.find(" ") == 0) {
            cmd = cmd.substr(1);
        }
        while (!sta.empty())
            sta.pop();
    }
    tmp = cmd;
    cur_cmd = tmp.substr(0, tmp.find(" ") == std::string::npos ? tmp.size() : tmp.find(" "));
    sta.push(tmp.substr(tmp.find(" ") == std::string::npos ? tmp.size() : tmp.find(" ")));
    if (cur_cmd == "EMAIL_ADRESS") {
        ret.push_back(std::pair<Information, std::stack<std::string> >(EMAIL_ADDRESS, sta));
    } else if (cur_cmd == "IP_ADRESS") {
        ret.push_back(std::pair<Information, std::stack<std::string> >(IP_ADDRESS, sta));
    } else if (cur_cmd == "PHONE_NUMBER") {
        ret.push_back(std::pair<Information, std::stack<std::string> >(PHONE_NUMBER, sta));
    }
    std::cout << "out : tmp = \"" << tmp << "\"" << std::endl << "cur_cmd = \"" << cur_cmd << "\"" << std::endl;
    return (ret);
}

int	main()
{
    std::string	tmp;

    while (getline(std::cin, tmp)) {
        parse(tmp);
    }
}
