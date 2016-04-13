#ifndef INTERNETSOCKET_HPP
# define INTERNETSOCKET_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <fstream>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include<arpa/inet.h>

# define BUFFER_SIZE 64

class InternetSocket {
private:
    const std::string   ip;
    int                 port;
    int                 fd;
    struct sockaddr_in  remote;
public:
    InternetSocket (const std::string &ip, int port);
    virtual ~InternetSocket ();
    std::string     getIP(void) const;
    void            send2(const std::string &str) const;
    std::string     recv2() const;
    void            operator>>(std::ostream &out);
};

std::ostream    &operator<<(std::ostream &stream, const InternetSocket &obj);
template <typename X>
void            operator>>(X stream, const InternetSocket &obj)
{
    std::stringstream   ss;

    ss << stream;
    obj.send2(ss.str());
}

#endif /* !INTERNETSOCKET_HPP */
