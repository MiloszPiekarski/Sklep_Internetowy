//
// Created by kkosz on 13.12.2023.
//
using namespace std;


#include "Produkt.h"
#include <iostream>
#include "fstream"


Produkt::Produkt(int Id_p, int Id_kategorii_p, string Nazwa_p, string Cena_p, int Dostepnosc_p, string CechaSzczegolna_p)
{
    IDs.Id = Id_p;
    IDs.Id_Kategorii = Id_kategorii_p;
    Nazwa = Nazwa_p;
    Cena = Cena_p;
    Dostepnosc = Dostepnosc_p;
    CechaSzczegolna = CechaSzczegolna_p;
}

void Produkt::wypisz()
{
    this->formatuj();
    cout << IDs.Id << " | " << Nazwa << " | " << Cena << " \t\t| " << Dostepnosc  << " \t\t| " << CechaSzczegolna << endl;

}

// wyplenienie bialymi znakami w celu schludniejszego wyswieltenia w konsoli
void Produkt::formatuj()
{
    int len = Nazwa.length();
    int n = 0;
    if(IDs.Id < 10)
    {
        n = 51;
    }
    else
    {
        n = 50;
    }
    for(int j = len; j < n; j++)
    {
        Nazwa += " ";
    }
}