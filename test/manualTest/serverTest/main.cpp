#include "model/include/Server.hpp"


int main() {
    Server server(8080);

    server.run();



    //server.~Server();
    return 0;
}