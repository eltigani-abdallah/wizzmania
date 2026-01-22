#ifndef WIZZMANIA_SERVER_HPP
#define WIZZMANIA_SERVER_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Server {
    public:
    Server();
    ~Server();






    private:

    int sockfd; //socket file descriptor
    int newsockfd; //new socket file descriptor
    int portno; // port number


};
#endif //WIZZMANIA_SERVER_HPP