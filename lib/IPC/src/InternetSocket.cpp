#include "InternetSocket.hpp"

InternetSocket::InternetSocket(const std::string &ip, int port) : ip(ip), port(port)
{
    if ((this->fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
    }
    this->remote.sin_family = AF_INET;
    this->remote.sin_addr.s_addr = inet_addr(ip.c_str());
    this->remote.sin_port = htons(port);
}

InternetSocket::~InternetSocket()
{
    close(this->fd);
}

std::string     InternetSocket::getIP(void) const
{
    return (this->ip);
}

void            InternetSocket::send2(const std::string &str) const
{
    if (connect(this->fd, (struct sockaddr *)&this->remote, sizeof(this->remote)) == -1) {
        perror("connect");
    }
    if (send(this->fd, str.c_str(), str.length(), 0) == -1) {
        perror("send");
        exit(1);
    }
}

std::string     InternetSocket::recv2() const
{
    std::string     str("");
    int             fd_accept;
    int             n;
    char            buffer[BUFFER_SIZE];

    if (bind(this->fd, (struct sockaddr *)&this->remote, sizeof(this->remote)) == -1) {
        perror("bind");
    }

    if (listen(this->fd, 5) == -1) {
        perror("listen");
    }
    // for (;;) {
        if ((fd_accept = accept(this->fd, NULL, NULL)) == -1) {
            perror("accept");
        }
        for (;;) {
            if ((n = recv(fd_accept, buffer, BUFFER_SIZE, 0)) == -1) {
                perror("recv");
            } else if (n == 0) {
                break;
            }
            str += buffer;
        }
        close(fd_accept);
    // }
    return (str);
}

std::ostream    &operator<<(std::ostream &stream, const InternetSocket &obj)
{
    return (stream << obj.recv2());
}
