#ifndef FIND_HPP_
# define FIND_HPP_

# include <regex>
# include <vector>
# include <map>
# include "Information.hpp"

namespace Find {
    static std::map<Information, std::regex>   map_info_regex = {
            {PHONE_NUMBER, std::regex(REGEX_PHONE)},
            {EMAIL_ADDRESS, std::regex(REGEX_MAIL)},
            {IP_ADDRESS, std::regex(REGEX_IP)}
    };
    static std::map<Information, std::string>   map_info_str = {
            {PHONE_NUMBER, "PHONE_NUMBER"},
            {EMAIL_ADDRESS, "EMAIL_ADDRESS"},
            {IP_ADDRESS, "IP_ADDRESS"}
    };
    void						suppSpace(std::string &);
    std::vector<std::string>	findInfo(std::string, std::regex);
};

#endif /* !FIND_HPP_ */
