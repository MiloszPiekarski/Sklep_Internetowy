//
// Created by kkosz on 13.12.2023.
//

#ifndef PROJEKT_PRODUKT_H
#define PROJEKT_PRODUKT_H


#include <iostream>
#include "SprzetElektroniczny.h"
#include <vector>
using namespace std;

class Produkt : public SprzetElektroniczny{
private:
    string Cena; //STRING DLA ODPOWIEDNIEGO WYSWIETLENIA W KONSOLI
    int Dostepnosc;
    string CechaSzczegolna;
    string formatujNazwe();
public:
    Produkt();
    Produkt(int Id_p, int Id_kategorii_p, string Nazwa_p, string Cena_p, int Dostepnosc_p, string CechaSzczegolna_p);

    static std::vector<Produkt> lista_produktow;
    static void wczytaj_produkty();
    static void wypisz_liste();


    void wypisz();
    void wypisz2();
    bool uzupelnijDane();
    bool dodajProdukt();
    bool wczytajProdukt(int idProduktu);
    bool edytujProdukt(int idProduktu, const string& nowaNazwa, const string& nowaCena, const string& nowaDostepnosc, const string& nowaCecha);
    bool usunProdukt(int idProduktu);

    //gettery
    string getNazwa() const;
    float getCena() const;
    int getDostepnosc() const;
    string getCechaSzczegolna() const;
    int GetId() const;
    int getId_Kategorii() const;
};


#endif //PROJEKT_PRODUKT_H
