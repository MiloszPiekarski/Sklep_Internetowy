//
// Created by monik on 04.01.2024.
//

#ifndef PROJEKT_KLIENT_H
#define PROJEKT_KLIENT_H
#include <iostream>
#include <vector>
class Klient{
private:
    int Id_klienta;
    std::string imie;
    std::string nazwisko;
    std::string miasto;
    std::string ulica;
    int numer_budynku;
    std::string email;
public:
    Klient(int p_id, std::string p_imie, std::string p_nazwisko, std::string p_miasto, std::string p_ulica,std::string p_email);
    static void wczytaj_klientow();
    static std::vector<Klient> lista_klientow;
    void wypisz();
    static void wypisz_liste();
};

#endif //PROJEKT_KLIENT_H
