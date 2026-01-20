#ifndef WIZZMANIA_MODELMAIN_HPP
#define WIZZMANIA_MODELMAIN_HPP

#include "Client.hpp"
class ModelMain {
public:
    ModelMain();
    ~ModelMain();

    Client createClient();
    Server createServer();

private:
    Client client {nullptr};
    Server server {nullptr};
};
#endif //WIZZMANIA_MODELMAIN_HPP