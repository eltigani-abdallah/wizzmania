cmake_minimum_required(VERSION 3.16)
project(wizzmania LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt auto tools (MOC indispensable si Q_OBJECT est utilisé)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Network)

# qt6_wrap_cpp(WIZZ_MOC_SOURCES
#     view/include/mainwindow.hpp
# )

add_executable(wizzmania
        controller/src/main.cpp
        view/src/mainwindow.cpp

        
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
        
        view/include/mainwindow.hpp
        # ↑ view files
)

# qt_add_executable(wizzmania
#     controller/src/main.cpp
#     view/src/mainwindow.cpp
#     view/include/mainwindow.hpp
#     ${WIZZ_MOC_SOURCES}
# )

target_include_directories(wizzmania PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/controller/include
    ${CMAKE_CURRENT_SOURCE_DIR}/model/include
    ${CMAKE_CURRENT_SOURCE_DIR}/view/include
)

target_link_libraries(wizzmania PRIVATE
    Qt6::Widgets
    Qt6::Core
    Qt6::Network
)

