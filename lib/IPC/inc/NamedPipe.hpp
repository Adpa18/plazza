#ifndef NAMEDPIPE_HPP
# define NAMEDPIPE_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <fstream>
# include <sys/stat.h>
# include <unistd.h>

class NamedPipe {
private:
    const std::string   fileName;
public:
    NamedPipe (const std::string &fileName);
    virtual ~NamedPipe ();
    std::string     getFileName(void) const;
    void            send(const std::string &str) const;
    std::string     recv() const;
    void            operator>>(std::ostream &out);
    void            destroy();
};

std::ostream    &operator<<(std::ostream &stream, const NamedPipe &obj);
template <typename X>
void            operator>>(X stream, const NamedPipe &obj)
{
    std::stringstream   ss;

    ss << stream;
    obj.send(ss.str());
}

#endif /* !NAMEDPIPE_HPP */
