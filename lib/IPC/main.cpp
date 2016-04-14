#include "InternetSocket.hpp"
#include "UnixSocket.hpp"
#include "NamedPipe.hpp"

int		main(void)
{
    if (fork() == 0) {
        UnixSocket   toto("toto");
        std::string("bonjour je suis toto") >> toto;
        // UnixSocket   tota("toto");
        std::string("bonjour je suis tota") >> toto;
    } else {
        UnixSocket   tata("toto");
        std::cout << tata << std::endl;
    }
    return (0);
}
