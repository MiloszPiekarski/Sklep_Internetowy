//
// Created by kkosz on 16.12.2023.
//

#ifndef PROJEKT_SLUCHAWKI_H
#define PROJEKT_SLUCHAWKI_H

#include "Produkt.h"

class Sluchawki : public Produkt{
    std::string Lacznosc;
public:
    Sluchawki();
    void wypisz();
    void wprowadzDane();
};


#endif //PROJEKT_SLUCHAWKI_H
