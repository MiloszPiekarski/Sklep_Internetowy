//
// Created by kkosz on 15.12.2023.
//

#ifndef PROJEKT_LAPTOP_H
#define PROJEKT_LAPTOP_H

#include "Produkt.h"


class Laptop : public Produkt{
    std::string Stan;
public:
    Laptop();
    void wypisz();
    void wprowadzDane();
};


#endif //PROJEKT_LAPTOP_H
