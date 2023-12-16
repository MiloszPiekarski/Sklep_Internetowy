//
// Created by kkosz on 16.12.2023.
//

#ifndef PROJEKT_MONITOR_H
#define PROJEKT_MONITOR_H

#include "Produkt.h"

class Monitor : public Produkt{
    std::string Odswiezanie;
public:
    Monitor();
    void wypisz();
    void wprowadzDane();
};


#endif //PROJEKT_MONITOR_H
