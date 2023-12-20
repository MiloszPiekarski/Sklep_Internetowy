//
// Created by kkosz on 13.12.2023.
//
using namespace std;


#include "Produkt.h"
#include <iostream>
#include "fstream"
#include "iomanip"
#include <locale>
#include <codecvt>

int ilePolskich(const string str) {
    // Convert narrow string to wide string
    wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    wstring wideStr = converter.from_bytes(str);

    // Define a set of Polish characters
    wstring polishCharacters = L"ąćęłńóśźżĄĆĘŁŃÓŚŹŻ";

    // Count occurrences of Polish characters
    int count = 0;
    for (wchar_t ch : wideStr) {
        if (polishCharacters.find(ch) != wstring::npos) {
            count++;
        }
    }

    return count;
}

// wyplenienie bialymi znakami w celu schludniejszego wyswieltenia w konsoli
void Produkt::formatuj()
{
    int len = 0;
    len = Nazwa.length();
    len = len - ilePolskich(Nazwa);
    int n = 0;
    if(IDs.Id < 10)
    {
        n = 81;
    }
    else
    {
        n = 80;
    }
    for(int j = len; j < n; j++)
    {
        Nazwa += " ";
    }
}

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
//    cout << IDs.Id << " | " << Nazwa << " | ";
//    printf("%.2f", Cena );
//    cout  << " \t\t\t| " << Dostepnosc  << " \t\t\t| " << CechaSzczegolna << endl;

    this->formatuj();
    cout << IDs.Id << " | " << Nazwa << " | " << Cena << "\t | " << Dostepnosc  << "\t\t\t| " << CechaSzczegolna << endl;

}
//Gettery
string Produkt::getNazwa() const
{
    return Nazwa;
}
float Produkt::getCena() const
{
    return stof(Cena);
}
int Produkt::getDostepnosc() const
{
    return Dostepnosc;
}
string Produkt::getCechaSzczegolna() const
{
    return CechaSzczegolna;
}
int Produkt::GetId() const
{
    return IDs.Id;
}
int Produkt::getId_Kategorii() const
{
    return IDs.Id_Kategorii;
}
