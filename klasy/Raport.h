//
// Created by Krystian Ziaja on 20/12/2023.
//
#ifndef PROJEKT_RAPORT_H
#define PROJEKT_RAPORT_H
#include <vector>
#include <iostream>
class Raport{
private:
    int id_raportu;
    std::string data;
    std::string zakres_czasowy;
    std::string najlepszy_produkt;
    static std::string dzisiejsza_data();
    int id_produktu;
    float dochod;
public:
    static int id;
    static std::vector<Raport> lista_raportow;
    void dopisz_do_pliku();
    Raport();
    Raport(std::string p_zakres_czasowy,std::string p_najlepszy_produkt,int p_ID_produktu, float p_dochod,std::string p_data = dzisiejsza_data());
    static void wczytaj_raporty();
    void wypisz();
    static void wypisz_liste();
};

#endif //PROJEKT_RAPORT_H
