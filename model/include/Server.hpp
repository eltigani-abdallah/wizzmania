#ifndef WIZZMANIA_SERVER_HPP
#define WIZZMANIA_SERVER_HPP
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

class Server {
public:
    Server(int portNum);
    ~Server();

    void listenForConnections();

    void acceptConnection();

    void readFromSocket();

    void run();






private:

    int sockfd={0}; //socket file descriptor
    int newsockfd = {0}; //new socket file descriptor
    int portno={0}; // port number
    int n={0}; // return value for read() and write()

    socklen_t clilen; // client address size. needed for accept()

    char buffer[256]; //buffer to receive socket connection characters (text)

    struct sockaddr_in serv_addr; // server internet address
    struct sockaddr_in cli_addr; // client internet address






};
#endif //WIZZMANIA_SERVER_HPP