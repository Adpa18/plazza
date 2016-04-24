#ifndef FIND_HPP_
# define FIND_HPP_

# include <vector>
# include <map>
# include "Information.hpp"

# define N_MATCH    1

namespace Find {
    static std::map<Information, std::string>   map_info_string = {
            {PHONE_NUMBER, std::string(REGEX_PHONE)},
            {EMAIL_ADDRESS, std::string(REGEX_MAIL)},
            {IP_ADDRESS, std::string(REGEX_IP)}
    };
    static std::map<Information, std::string>   map_info_str = {
            {PHONE_NUMBER, "PHONE_NUMBER"},
            {EMAIL_ADDRESS, "EMAIL_ADDRESS"},
            {IP_ADDRESS, "IP_ADDRESS"}
    };
    std::vector<std::string>	findInfo(std::string, std::string);
};

#endif /* !FIND_HPP_ */
