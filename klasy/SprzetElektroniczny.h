//
// Created by kkosz on 20.12.2023.
//

#ifndef PROJEKT_SPRZETELEKTRONICZNY_H
#define PROJEKT_SPRZETELEKTRONICZNY_H

#include "iostream"
using namespace std;

class SprzetElektroniczny {
protected:
    class Id {
    public:
        int Id;
        int Id_Kategorii;
    };
    Id IDs;
    string Nazwa;
public:
    virtual void wypisz() = 0; // Metoda czysto wirtualna
};


#endif //PROJEKT_SPRZETELEKTRONICZNY_H
