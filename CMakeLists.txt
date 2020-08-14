cmake_minimum_required(VERSION 3.17)
project(Info2-2020)

set(CMAKE_CXX_STANDARD 14)

add_executable(TDA1 Clase1/main1.cpp)
add_executable(TDA2 Clase1/main2.cpp)

add_executable(DemoSFML ejAuto/main3.cpp ejAuto/Auto.cpp ejAuto/Auto.h ejAuto/Ball.cpp ejAuto/Ball.h)
target_link_libraries(DemoSFML  sfml-system sfml-window sfml-graphics sfml-audio )
