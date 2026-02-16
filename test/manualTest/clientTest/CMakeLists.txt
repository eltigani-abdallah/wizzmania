cmake_minimum_required(VERSION 3.16)
project(clientTest)

add_executable(clientTest
        src/Client.cpp
        main.cpp
)

target_include_directories( clientTest
PRIVATE ${CMAKE_SOURCES_DIR}/include)