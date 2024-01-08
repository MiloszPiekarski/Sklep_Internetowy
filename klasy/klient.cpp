//
// Created by monik on 04.01.2024.
//
#include "klient.h"
#include "everywhere_functions.h"
#include "../fileHelper.h"
#include <fstream>
#include <iomanip>
std::vector<Klient> Klient::lista_klientow;

void Klient::wczytaj_klientow() {
    if(!lista_klientow.empty()) return;
    std::fstream file;
    file.open("../dane/klienci.txt", std::ios::in);
    std::string line = "";
    getline(file,line);
    while(getline(file,line)){
        std::vector<std::string> list = split(line,';');
        Klient object(stringtoint(list[0]),list[1],list[2],list[3],list[4],list[5]);
        lista_klientow.push_back(object);
    }
    file.close();
}

Klient::Klient(int p_id, std::string p_imie, std::string p_nazwisko, std::string p_miasto, std::string p_ulica,std::string p_email){
    Id_klienta = p_id;
    imie = p_imie;
    nazwisko = p_nazwisko;
    miasto = p_miasto;
    for(char x : p_ulica){
        if(x == '_') break;
        ulica += x;
    }
    std::string snum;
    for(int i = ulica.length()+1;i<p_ulica.length();i++)
        snum += p_ulica[i];
    numer_budynku = stringtoint(snum);
    email = p_email;
}

void Klient::wypisz_liste() {
    for(Klient el: lista_klientow){
        el.wypisz();
    }
}

void Klient::wypisz() {
    int ul = 25 - ulica.length() - 1 - (numer_budynku >= 10 ? 2 : 1);
    std::cout<<Id_klienta<<setw(13 - (Id_klienta > 9 ? 2 : 1))<<"| "<<imie<<setw(15-(imie.length()))<<"| "<<nazwisko<<setw(18-(nazwisko.length()))<<"| "<<miasto<<setw(15 - (miasto.length()))<<"| "<<ulica<<" "<<numer_budynku<<setw(ul)<<"| "<<email<<std::endl;
}