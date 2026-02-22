#include "../include/Client.hpp"




Client::Client(int portNum) {
    bzero((char*)&serv_addr, sizeof(serv_addr));
    bzero(buffer, 256);
    portno=portNum;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr<<"Error opening client socket"<<std::endl;
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        std::cerr<<"Error: no host found"<<std::endl;
    }

    serv_addr.sin_family = AF_INET;
    bcopy((char*)server ->h_addr, (char*)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

}

void Client::connectToServer() {
    if (connect(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr<<"Error connecting to server"<<std::endl;
    }
}

void Client::sendMessage() {
    printf("please enter message: ");
    bzero(buffer, 256);
    fgets(buffer, 255,stdin);
    n = write(sockfd, buffer, strlen(buffer));

    if (n<0) {
        std::cerr<<"Error writing to socket"<<std::endl;
    }
}

void Client::receiveMessage() {
    bzero(buffer, 256);
    n = read(sockfd, buffer, 256);
    if (n<0) {
        std::cerr<<"Error reading from socket"<<std::endl;
    }
}

void Client::showMessage() {
    std::cout<<buffer<<std::endl;
}

