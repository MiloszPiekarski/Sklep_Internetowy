//
// Created by kkosz on 16.12.2023.
//

#ifndef PROJEKT_TELEWIZOR_H
#define PROJEKT_TELEWIZOR_H

#include "Produkt.h"

class Telewizor : public Produkt{
    std::string Rozdzielczosc;
public:
    Telewizor();
    void wypisz();
    void wprowadzDane();
};


#endif //PROJEKT_TELEWIZOR_H
