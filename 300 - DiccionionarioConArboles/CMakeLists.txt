cmake_minimum_required(VERSION 3.26)
project(200_DiccionarioConTablasDeDispersion)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(200_DiccionarioConTablasDeDispersion
        include/DicPalabra.h
        include/TablaHash.h
        include/Utilidades.h
        src/DicPalabra.cpp
        src/main.cpp
        src/TablaHash.cpp
        src/Utilidades.cpp
        src/NodoTrie.cpp
        include/NodoTrie.h
        src/ArbolTrie.cpp
        include/ArbolTrie.h
)
