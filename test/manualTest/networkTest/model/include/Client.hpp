#ifndef WIZZMANIA_CLIENT_HPP
#define WIZZMANIA_CLIENT_HPP

#include <strings.h>
#include <netinet/in.h>
#include <iostream>
#include <netdb.h>
#include <unistd.h>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>

class Client {
    public:
    Client(int portNum);
    ~Client();

    void connectToServer();

    void sendMessage();

    void receiveMessage();

    void showMessage();

    void run();

    private:
        int sockfd = {0};
        int portno = {0};
        int n = {0};

        char buffer[256] = {0};

        sockaddr_in serv_addr = {0};
        hostent *server = NULL;


};

#endif //WIZZMANIA_CLIENT_HPP