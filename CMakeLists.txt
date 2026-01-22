cmake_minimum_required(VERSION 3.16)
project(wizzmania LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Qt auto tools (MOC indispensable si Q_OBJECT est utilisé)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Network)

qt6_wrap_cpp(WIZZ_MOC_SOURCES
    controller/include/mainwindow.hpp
)


qt_add_executable(wizzmania
    controller/src/main.cpp
    controller/src/mainwindow.cpp
    controller/include/mainwindow.hpp
    ${WIZZ_MOC_SOURCES}
)

target_include_directories(wizzmania PRIVATE
    controller/include
    model/include
    view/include
)

target_link_libraries(wizzmania PRIVATE
    Qt6::Widgets
    Qt6::Core
    Qt6::Network
)

