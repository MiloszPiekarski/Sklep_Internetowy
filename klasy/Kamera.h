//
// Created by kkosz on 16.12.2023.
//

#ifndef PROJEKT_KAMERA_H
#define PROJEKT_KAMERA_H

#include "Produkt.h"

class Kamera : public Produkt{
    std::string Rozdzielczosc;
public:
    Kamera();
    void wypisz();
    void wprowadzDane();
};


#endif //PROJEKT_KAMERA_H
