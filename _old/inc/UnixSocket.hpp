#ifndef UNIXSOCKET_HPP
# define UNIXSOCKET_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <fstream>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <sys/un.h>

# define BUFFER_SIZE 64

class UnixSocket {
private:
    const std::string   fileName;
    int                 fd;
    struct sockaddr_un  local;
public:
    UnixSocket (const std::string &fileName);
    virtual ~UnixSocket ();
    std::string     getFileName(void) const;
    void            send2(const std::string &str) const;
    std::string     recv2() const;
    void            operator>>(std::ostream &out);
};

std::ostream    &operator<<(std::ostream &stream, const UnixSocket &obj);
template <typename X>
void            operator>>(X stream, const UnixSocket &obj)
{
    std::stringstream   ss;

    ss << stream;
    obj.send2(ss.str());
}
#endif /* !UNIXSOCKET_HPP */
