#include "../include/Client.hpp"




Client::Client(int portNum) {

    std::memset(&serv_addr, 0, sizeof(serv_addr));
    std::memset(buffer, 0, sizeof(buffer));
    portno=portNum;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        std::cerr<<"Error opening client socket"<<std::endl;
        exit(EXIT_FAILURE);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        std::cerr<<"Error: no host found"<<std::endl;
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    std::memcpy(&serv_addr.sin_addr.s_addr , server ->h_addr ,  server->h_length);
    serv_addr.sin_port = htons(portno);

}

Client::~Client() {
    std::cout<<"destroying client..."<<std::endl;
    close(sockfd);
}

void Client::connectToServer() {
    if (connect(sockfd, (sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        std::cerr<<"Error connecting to server"<<std::endl;
        exit(EXIT_FAILURE);
    }
}

void Client::sendMessage() {
    printf("please enter message: ");
    std::memset(buffer, 0,sizeof(buffer));
    fgets(buffer, 255,stdin);
    n = write(sockfd, buffer, strlen(buffer));

    if (n<0) {
        std::cerr<<"Error writing to socket"<<std::endl;
        exit(EXIT_FAILURE);
    }
}

void Client::receiveMessage() {
    std::memset(buffer, 0,sizeof(buffer));
    n = read(sockfd, buffer, 256);
    if (n<0) {
        std::cerr<<"Error reading from socket"<<std::endl;
        exit(EXIT_FAILURE);
    }
}

void Client::showMessage() {
    std::cout<<buffer<<std::endl;
}

void Client::run() {
    connectToServer();
    sendMessage();
    receiveMessage();
    showMessage();
}
