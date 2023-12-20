//
// Created by kkosz on 13.12.2023.
//

#ifndef PROJEKT_PRODUKT_H
#define PROJEKT_PRODUKT_H


#include <iostream>
#include "SprzetElektroniczny.h"

using namespace std;

class Produkt : public SprzetElektroniczny{
private:
    string Cena;
    int Dostepnosc;
    string CechaSzczegolna;
    void formatuj();
public:
    void wypisz();
    Produkt(int Id_p, int Id_kategorii_p, string Nazwa_p, string Cena_p, int Dostepnosc_p, string CechaSzczegolna_p);
};


#endif //PROJEKT_PRODUKT_H
