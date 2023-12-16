//
// Created by kkosz on 16.12.2023.
//

#ifndef PROJEKT_SMARTFON_H
#define PROJEKT_SMARTFON_H

#include "Produkt.h"

class Smartfon : public Produkt {
    std::string Stan;
public:
    Smartfon();
    void wypisz();
    void wprowadzDane();
};


#endif //PROJEKT_SMARTFON_H
