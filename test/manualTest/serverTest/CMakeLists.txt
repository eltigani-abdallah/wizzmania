cmake_minimum_required(VERSION 3.16)
project(serverTest)

add_executable(serverTest
                model/src/Server.cpp
                main.cpp
)

target_include_directories(serverTest
        PRIVATE ${CMAKE_SOURCE_DIR}/model/include
)