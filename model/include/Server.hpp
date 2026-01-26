#ifndef WIZZMANIA_SERVER_HPP
#define WIZZMANIA_SERVER_HPP


#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <iostream>

class Server {
public:
    /**
     * a server that can listen for and accept connections from clients
     * @param portNum->int port number for the socket to bind the address to
     */
    Server(int portNum);

    /**
     * closes sockets
     */
    ~Server();

    /**
     * listen for connections from the client
     */
    void listenForConnections();

    /**
     * accept connections from the client
     */
    void acceptConnection();

    /**
     * read information received from the client, in this case it should be messages
     */
    void readFromSocket();

    /**
     * listen for connections ↓\n accept connections ↓\n read from socket\n the server circle of life
     */
    void run();






private:

    int sockfd={0}; //socket file descriptor
    int newsockfd = {0}; //new socket file descriptor
    int portno={0}; // port number
    int n={0}; // return value for read() and write()

    socklen_t clilen; // client address size. needed for accept()

    char buffer[256]; //buffer to receive socket connection characters (text)

    sockaddr_in serv_addr; // server internet address
    sockaddr_in cli_addr; // client internet address






};
#endif //WIZZMANIA_SERVER_HPP