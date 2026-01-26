#ifndef WIZZMANIA_CLIENT_HPP
#define WIZZMANIA_CLIENT_HPP

#include <string>

#include "NetworkEntity.hpp"

class Client : public NetworkEntity {
    public:

private:
    std::string username;
    std::string passwordHash;
    Status status;
    Socket socket;

};

#endif //WIZZMANIA_CLIENT_HPP