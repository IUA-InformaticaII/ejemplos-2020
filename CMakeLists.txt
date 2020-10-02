cmake_minimum_required(VERSION 3.17)
project(Info2-2020)

set(CMAKE_CXX_STANDARD 14)

add_executable(TDA1 Clase1/main1.cpp)
add_executable(TDA2 Clase1/main2.cpp)

add_executable(Archivos1 Clase3/main1.cpp)
add_executable(Archivos2 Clase3/main2.cpp)
add_executable(Archivos3 Clase3/main3.cpp)
add_executable(Archivos4 Clase3/main4.cpp)
add_executable(Archivos5 Clase3/main5.cpp)
add_executable(Archivos6 Clase3/main6.cpp)
add_executable(QuickSort Clase7/quicksort.cpp)
add_executable(EjemploPtr Clase5/ejPuntero.cpp)
add_executable(Repaso2 Clase8/Repaso2.cpp)
add_executable(Repaso2.1 Clase8/Repaso2.1.cpp)
add_executable(Rasdf Clase8/ptr.cpp)


add_executable(MainLista Lista/main.cpp Lista/LinkedList.cpp)


add_executable(potencia Clase6/potencia.cpp)
add_executable(fibonacci Clase6/fibonacci.cpp)

add_executable(Bolitas ejAuto/Bolitas.cpp ejAuto/Auto.cpp ejAuto/Auto.h ejAuto/Ball.cpp ejAuto/Ball.h)
target_link_libraries(Bolitas sfml-system sfml-window sfml-graphics sfml-audio)

add_executable(ejMapa ejAuto/ejMapa.cpp ejAuto/Auto.cpp ejAuto/Auto.h ejAuto/Ball.cpp ejAuto/Ball.h)
target_link_libraries(ejMapa sfml-system sfml-window sfml-graphics sfml-audio)

add_executable(ejPlataformer ejPlataformer/ejPlataformer.cpp ejPlataformer/Player.cpp ejPlataformer/Mapa.cpp ejPlataformer/Proyectil.cpp ejPlataformer/Proyectil.h ejPlataformer/Arreglo.cpp ejPlataformer/Arreglo.h)
target_link_libraries(ejPlataformer sfml-system sfml-window sfml-graphics sfml-audio)


# Laberinto
find_package(Threads)

add_executable(extraLaberinto Extra-Laberinto/main.cpp Extra-Laberinto/LaberintoSolver.cpp Extra-Laberinto/MazeGenerator.cpp)
target_link_libraries(extraLaberinto ${CMAKE_THREAD_LIBS_INIT} sfml-system sfml-window sfml-graphics sfml-audio)

file(COPY Extra-Laberinto/tileLab.png DESTINATION ${CMAKE_BINARY_DIR}/)