cmake_minimum_required(VERSION 3.26)
project(projekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(projekt main.cpp
        functions.cpp
        functions.h
        klasy/Produkt.cpp
        klasy/Produkt.h
        klasy/SprzetElektroniczny.cpp
        klasy/SprzetElektroniczny.h
        fileHelper.cpp
        fileHelper.h
        klasy/everywhere_functions.h
        klasy/everywhere_functions.cpp
        klasy/Raport.cpp
        klasy/Raport.h
        klasy/Zamowienia.cpp
        klasy/Zamowienia.h
        klasy/kategorie.cpp
        klasy/klient.cpp
)

