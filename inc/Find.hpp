#ifndef FIND_HPP_
# define FIND_HPP_

# include <regex>
# include <vector>

# define REGEX_IP		"\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\b"
# define REGEX_PHONE	"[0|+33|0033)[ ]*[1-9][ ]*([0-9][ ]*){7}[0-9]"
# define REGEX_MAIL		"[a-zA-Z0-9_.-]+@[a-zA-Z0-9_.-]+"

namespace Find {
    void						suppSpace(std::string &);
    std::vector<std::string>	findInfo(std::string, std::regex);
};

#endif /* !FIND_HPP_ */
