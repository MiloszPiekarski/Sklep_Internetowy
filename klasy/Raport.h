//
// Created by Krystian Ziaja on 20/12/2023.
//
#ifndef PROJEKT_RAPORT_H
#define PROJEKT_RAPORT_H
#include <vector>
#include <map>
#include <iostream>
#include <optional>
#include "Zamowienia.h"
#include "Produkt.h"
class Raport{
protected:
    class Statistics{
    public:
        std::string *name = new std::string;        //  product name
        int *amount = new int;                      //  product quantiti
        float *income = new float;                  //  product income
        int *id = new int;                          //  product id
        Statistics();
        Statistics(int gAmount, int gIncome, int gId, std::string gName);
        ~Statistics();

    };
    Statistics *info = new Statistics;
    int *id_raportu = new int;
    std::string *data = new std::string;
    std::string *period_of_time = new std::string;
    static std::string dzisiejsza_data();
public:
    static int id;
    static std::vector<Raport> lista_raportow;
    static void wczytaj_raporty();
    static void wypisz_liste();
    void generuj_raport(int pot, std::string pot_2);
    void dopisz_do_pliku();
    Raport();
    ~Raport();
    Raport(std::string p_zakres_czasowy,std::string p_najlepszy_produkt,int p_ID_produktu, float p_dochod,std::string p_data = dzisiejsza_data());
    friend std::map<int,Statistics> pot_get_income(std::vector<Zamowienie> pot_orders);
    void wypisz();

};

#endif //PROJEKT_RAPORT_H
