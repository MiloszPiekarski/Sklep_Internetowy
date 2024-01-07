//
// Created by monik on 04.01.2024.
//

#ifndef PROJEKT_KATEGORIE_H
#define PROJEKT_KATEGORIE_H
#include <iostream>
#include <vector>

class kategoria{
private:
    int id_kategorii;
    std::string nazwa;
public:
    kategoria();
    kategoria(int p_id_kategorii, std::string p_nazwa);
    static std::vector<kategoria> lista_kategorii;
    static void wczytaj_kategorie();
    void wypisz();
    static void wypisz_liste();
};

#endif //PROJEKT_KATEGORIE_H
