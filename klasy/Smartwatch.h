//
// Created by kkosz on 16.12.2023.
//

#ifndef PROJEKT_SMARTWATCH_H
#define PROJEKT_SMARTWATCH_H

#include "Produkt.h"

class Smartwatch : public Produkt{
    std::string Cecha;
public:
    Smartwatch();
    void wypisz();
    void wprowadzDane();
};


#endif //PROJEKT_SMARTWATCH_H
