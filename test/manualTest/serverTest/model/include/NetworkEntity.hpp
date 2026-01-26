#ifndef WIZZMANIA_NETWORKENTITY_HPP
#define WIZZMANIA_NETWORKENTITY_HPP

#include "Status.hpp"
#include "Socket.hpp"
class NetworkEntity : Socket {
public:
    Status getStatus();
    void setStatus(Status newStatus);



private:
    Status status;
    Socket socket;

};

#endif //WIZZMANIA_NETWORKENTITY_HPP