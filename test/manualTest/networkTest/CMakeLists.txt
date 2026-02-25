CMAKE_MINIMUM_REQUIRED(VERSION 3.16)
project(networkTest)


add_executable(networkTest

                model/src/Server.cpp
                model/src/Client.cpp
                main.cpp
)

target_include_directories( networkTest PRIVATE
                            ${CMAKE_SOURCE_DIR}/model/include
)