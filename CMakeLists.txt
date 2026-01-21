cmake_minimum_required(VERSION 4.1)
project(wizzmania)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(wizzmania
        controller/src/main.cpp
        controller/include/ControllerMain.hpp
        controller/include/Mode.hpp
        model/include/ModelMain.hpp
        model/include/Client.hpp
        model/include/Server.hpp
        view/include/ViewMain.hpp)

target_link_libraries(wizzmania Qt6::Widgets)

