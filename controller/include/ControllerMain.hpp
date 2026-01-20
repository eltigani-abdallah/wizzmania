#ifndef WIZZMANIA_CONTROLLERMAIN_HPP
#define WIZZMANIA_CONTROLLERMAIN_HPP

#include "../../model/include/ModelMain.hpp"
#include "../../view/include/ViewMain.hpp"
#include "Mode.hpp"

class ControllerMain {
public:

    ControllerMain(Mode mode);
    ~ControllerMain();

    void start();




private:
    Server server;
    Client client;

};
#endif //WIZZMANIA_CONTROLLERMAIN_HPP