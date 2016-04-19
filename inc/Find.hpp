#ifndef FIND_HPP_
# define FIND_HPP_

# include <regex>
# include <vector>
# include "Information.hpp"

namespace Find {
    static std::map<Information, std::regex>   map_info = {
            {PHONE_NUMBER, std::regex(REGEX_PHONE)},
            {EMAIL_ADDRESS, std::regex(REGEX_IP)},
            {IP_ADDRESS, std::regex(REGEX_MAIL)}
    };
    void						suppSpace(std::string &);
    std::vector<std::string>	findInfo(std::string, std::regex);
};

#endif /* !FIND_HPP_ */
