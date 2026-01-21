#ifndef WIZZMANIA_CONTROLLERMAIN_HPP
#define WIZZMANIA_CONTROLLERMAIN_HPP

#include "../../model/include/ModelMain.hpp"
#include "../../view/include/ViewMain.hpp"
#include "Mode.hpp"

class ControllerMain {
public:

    ControllerMain(Mode mode);
    ~ControllerMain();

    void startServer();
    void startClient();
    void loginPage();
    void createAccPage();
    void chatPage();




private:


};
#endif //WIZZMANIA_CONTROLLERMAIN_HPP