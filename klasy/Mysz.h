//
// Created by kkosz on 16.12.2023.
//

#ifndef PROJEKT_MYSZ_H
#define PROJEKT_MYSZ_H

#include "Produkt.h"

class Mysz : public Produkt{
    std::string Typ;
public:
    Mysz();
    void wypisz();
    void wprowadzDane();
};


#endif //PROJEKT_MYSZ_H
