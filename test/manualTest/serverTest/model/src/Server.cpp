#include "../include/Server.hpp"



Server::Server(int portNum) {


    bzero((char*)&serv_addr, sizeof(serv_addr));
    bzero(buffer, 256);
    portno=portNum;

    serv_addr.sin_family = AF_INET; //address family. it should always br AF_INET
    serv_addr.sin_addr.s_addr = INADDR_ANY; //host IP address
    serv_addr.sin_port = htons(portno); //network byte order conversion for port number


    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error opening socket → "<<strerror(errno)<<std::endl;
    }

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr<<"error binding server socket → "<<strerror(errno)<<std::endl;
        exit(-1);
    }

    clilen = sizeof(cli_addr);



}

Server::~Server() {
    std::cout << "destroying server..." << std::endl;
    close(sockfd);
    close(newsockfd);
}

void Server::listenForConnections() {
    listen(sockfd, 5);
    std::cout << "Listening for connections..." << std::endl;
}

void Server::acceptConnection() {
    newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
    if (newsockfd < 0) {
        std::cerr<<"Error accepting new connection → "<<strerror(errno)<<std::endl;
    }
}

void Server::readFromSocket() {
    n = read(newsockfd, buffer, 256);
    if (n < 0) {
        std::cerr<<"Error reading from socket → "<<strerror(errno)<<std::endl;
    }
}

void Server::run() {
    listenForConnections();
    acceptConnection();
    readFromSocket();
}