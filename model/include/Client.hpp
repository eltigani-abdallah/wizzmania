#ifndef WIZZMANIA_CLIENT_HPP
#define WIZZMANIA_CLIENT_HPP

#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>
#include <strings.h>



class Client {
    public:
    Client (int portNum);
    ~Client ();

    void connectToHost();

    void connectToServer();

private:
    int sockfd = {0};
    int portno = {0};
    int n = {0};

    sockaddr_in serv_addr = {0};
    hostent *server = NULL;

    char buffer[256];


};

#endif //WIZZMANIA_CLIENT_HPP