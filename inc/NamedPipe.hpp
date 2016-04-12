#ifndef NAMEDPIPE_HPP
# define NAMEDPIPE_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <fstream>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>

class NamedPipe {
private:
    const std::string   fileName;
public:
    NamedPipe (const std::string &fileName);
    virtual ~NamedPipe ();
    std::string     getFileName(void) const;
    void            write(const std::string &str) const;
    std::string     read() const;
    void            operator>>(std::ostream &out);
};

std::ostream    &operator<<(std::ostream &stream, const NamedPipe &obj);
template <typename X>
void            operator>>(X stream, const NamedPipe &obj)
{
    std::stringstream   ss;

    ss << stream;
    obj.write(ss.str());
}

#endif /* !NAMEDPIPE_HPP */
