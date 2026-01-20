cmake_minimum_required(VERSION 4.1)
project(wizzmania)

set(CMAKE_CXX_STANDARD 17)

add_executable(wizzmania
        controller/src/main.cpp
        controller/include/ControllerMain.hpp
        controller/include/Mode.hpp
        model/include/ModelMain.hpp
        model/include/Client.hpp
        model/include/Server.hpp
        view/include/ViewMain.hpp)
