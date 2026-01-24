#include "../include/Server.hpp"

#include <iostream>

Server::Server() {


    bzero((char*)&serv_addr, sizeof(serv_addr));

    portno=8080;

    serv_addr.sin_family = AF_INET; //address family. it should always br AF_INET
    serv_addr.sin_addr.s_addr = INADDR_ANY; //host IP address
    serv_addr.sin_port = htons(portno); //network byte order conversion for port number


    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr << "Error opening socket"<<std::endl;
    }

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr<<"error binding server socket"<<std::endl;
    }

    clilen = sizeof(cli_addr);



}

void Server::listenForConnections() {
    listen(sockfd, 5);
}

void Server::acceptConnection() {
    newsockfd = accept(sockfd, (struct sockaddr*) &cli_addr, &clilen);
    if (newsockfd < 0) {
        std::cerr<<"Error accepting new connection"<<std::endl;
    }
}
