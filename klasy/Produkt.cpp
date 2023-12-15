//
// Created by kkosz on 13.12.2023.
//
using namespace std;
#include "Produkt.h"
#include <iostream>

Produkt::Produkt()
{
    cout << "Utworzono obiekt Produkt!" << endl;
}

void Produkt::wypisz()
{
    cout << Id_Produktu << "\t" << Nazwa << "\t" << Cena << "\t" << Dostepnosc << endl;
}