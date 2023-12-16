cmake_minimum_required(VERSION 3.26)
project(projekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(projekt main.cpp
        functions.cpp
        functions.h
        klasy/Produkt.cpp
        klasy/Produkt.h
        klasy/Laptop.cpp
        klasy/Laptop.h
        klasy/Smartfon.cpp
        klasy/Smartfon.h
        klasy/Mysz.cpp
        klasy/Mysz.h
        klasy/Sluchawki.cpp
        klasy/Sluchawki.h
        klasy/Kamera.cpp
        klasy/Kamera.h
        klasy/Telewizor.cpp
        klasy/Telewizor.h
        klasy/Monitor.cpp
        klasy/Monitor.h
        klasy/Smartwatch.cpp
        klasy/Smartwatch.h
        klasy/Glosniki.cpp
        klasy/Glosniki.h
        klasy/Klawiatura.cpp
        klasy/Klawiatura.h
)

