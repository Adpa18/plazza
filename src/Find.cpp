#include "Find.hpp"
#include <regex.h>
#include <cstring>
#include <iostream>

std::vector<std::string>		Find::findInfo(std::string str, std::string rgx)
{
    std::vector<std::string>    ret;
    const char                  *cur;
    regex_t                     r;
    regmatch_t                  m[N_MATCH];

    cur = str.c_str();
    if (regcomp(&r, rgx.c_str(), REG_EXTENDED | REG_NEWLINE) != 0) {
        throw std::runtime_error("regex");
    }
    while (regexec(&r, cur, N_MATCH, m, 0) != REG_NOMATCH) {
        if (m[0].rm_so == -1) {
            break;
        }
        char *res = NULL;
        if ((res = (char*)malloc(m[0].rm_eo - m[0].rm_so + 1)) == NULL) {
            throw std::bad_alloc();
        }
        memcpy(res, cur + m[0].rm_so, m[0].rm_eo - m[0].rm_so);
        res[m[0].rm_eo - m[0].rm_so] = 0;
        ret.push_back(std::string(res));
        free(res);
        cur += m[0].rm_eo;
    }
    regfree(&r);
    return (ret);
}
