//
// Created by kkosz on 16.12.2023.
//

#ifndef PROJEKT_GLOSNIKI_H
#define PROJEKT_GLOSNIKI_H

#include "Produkt.h"

class Glosniki : public Produkt{
    std::string Lacznosc;
public:
    Glosniki();
    void wypisz();
    void wprowadzDane();
};


#endif //PROJEKT_GLOSNIKI_H
