#include "UnixSocket.hpp"

UnixSocket::UnixSocket(const std::string &fileName) : fileName(fileName + ".socket")
{
    if ((this->fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) {
        perror("socket");
    }
    memset(&this->local, 0, sizeof(struct sockaddr_un));
    this->local.sun_family = AF_UNIX;
    strcpy(this->local.sun_path, this->fileName.c_str());
}

UnixSocket::~UnixSocket()
{
    close(this->fd);
    unlink(this->fileName.c_str());
}

std::string     UnixSocket::getFileName(void) const
{
    return (this->fileName);
}

void            UnixSocket::send2(const std::string &str) const
{
    if (connect(this->fd, (struct sockaddr *)&this->local, sizeof(this->local)) == -1) {
        perror("connect");
    }
    if (send(this->fd, str.c_str(), str.length(), 0) == -1) {
        perror("send");
        exit(1);
    }
}

std::string     UnixSocket::recv2() const
{
    std::string     str("");
    int             fd_accept;
    int             n;
    char            buffer[BUFFER_SIZE];

    unlink(local.sun_path);
    if (bind(this->fd, (struct sockaddr *)&this->local, sizeof(this->local)) == -1) {
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

std::ostream    &operator<<(std::ostream &stream, const UnixSocket &obj)
{
    return (stream << obj.recv2());
}
