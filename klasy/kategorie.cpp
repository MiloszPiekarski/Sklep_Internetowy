//
// Created by monik on 05.01.2024.
//
#include "kategorie.h"
#include "everywhere_functions.h"
#include "../fileHelper.h"
#include <fstream>
#include <iomanip>
std::vector<kategoria> kategoria::lista_kategorii;

kategoria::kategoria(int p_id_kategorii, std::string p_nazwa) {
    id_kategorii = p_id_kategorii;
    nazwa = p_nazwa;
}
kategoria::kategoria(){}
void kategoria::wczytaj_kategorie() {
    if(!lista_kategorii.empty()){
        return;
    }
    std::fstream file;
    file.open("../dane/kategorie.txt", std::ios::in);
    std::string line = "";
    getline(file,line);
    while(getline(file,line)){
        std::vector<std::string> list = split(line,';');
        kategoria object(stringtoint(list[0]),list[1]);
        lista_kategorii.push_back(object);
    }
    file.close();
}

void kategoria::wypisz_liste() {
    for(kategoria el: lista_kategorii){
        el.wypisz();
    }
}

void kategoria::wypisz(){
    std::cout<<id_kategorii<<setw(15 - (id_kategorii > 9 ? 2 : 1))<<"| "<<nazwa<<'\n';
}