cmake_minimum_required(VERSION 4.1)
project(wizzmania)

set(CMAKE_CXX_STANDARD 17)

add_executable(wizzmania
        controller/src/main.cpp
        controller/include/ControllerMain.hpp
        controller/include/Mode.hpp
        # ↑ controller files
        model/src/
        model/include/Client.hpp
        model/include/Server.hpp
        model/include/ModelMain.hpp
        model/include/NetworkEntity.hpp
        model/include/Security.hpp
        model/include/Status.hpp
        model/include/Socket.hpp
        # ↑ model files
        view/src/
        view/include/ViewMain.hpp
        view/include/ClientView.hpp
        view/include/ServerView.hpp
        view/include/LoginView.hpp
        view/include/CreateAccount.hpp
        view/include/WelcomeScreen.hpp
        # ↑ view files
)
