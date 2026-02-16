#ifndef WIZZMANIA_CLIENT_HPP
#define WIZZMANIA_CLIENT_HPP

#include <string>
#include <netinet/in.h>
#include <iostream>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>

#include "NetworkEntity.hpp"

class Client {
    public:

private:
    int sockfd = {0};
    int portno = {0};
    int n = {0};

    sockaddr_in serv_addr = {0};
    hostent *server = NULL;

    Client(int portNum);
};

#endif //WIZZMANIA_CLIENT_HPP