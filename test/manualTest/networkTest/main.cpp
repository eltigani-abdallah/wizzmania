#include "model/include/Server.hpp"
#include "model/include/Client.hpp"



int main() {

    int choice = {0};

    std::cout<<"Select mode: "<<std::endl;
    std::cout<<"0. Server"<<std::endl;
    std::cout<<"1. Client"<<std::endl;

    std::cin>>choice;

    if (choice == 0) {
        Server server(8080);
        server.run();
    }

    if (choice == 1) {
        Client client(8080);


        client.run();
    }

    else {
        std::cerr<<"ZERO OR ONE BITCH"<<std::endl;
    }
    return 0;
}