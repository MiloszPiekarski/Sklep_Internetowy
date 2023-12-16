//
// Created by kkosz on 16.12.2023.
//

#ifndef PROJEKT_KLAWIATURA_H
#define PROJEKT_KLAWIATURA_H

#include "Produkt.h"

class Klawiatura : public Produkt{
    std::string Przelacznik;
public:
    Klawiatura();
    void wypisz();
    void wprowadzDane();
};



#endif //PROJEKT_KLAWIATURA_H
