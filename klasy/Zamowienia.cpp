#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <optional>
#include <ctime>
#include <iomanip>
#include "Zamowienia.h"
#include "everywhere_functions.h"
#include "../fileHelper.h"

std::vector<Zamowienie> Zamowienie::lista_zamowien;
std::string path = "../dane/zamowienia.txt";

Zamowienie::Zamowienie(int p_id,std::string p_dane_zamowienie, int p_id_klienta, int p_id_produktu, int p_ilosc) {
    data_zamowienia.emplace(p_dane_zamowienie);
    id_klienta = p_id_klienta;
    id_produktu = p_id_produktu;
    ilosc = p_ilosc;
    id = p_id;
}

void Zamowienie::wypisz_liste() {
    for(Zamowienie el: lista_zamowien){
        el.wypisz();
    }
}

int Zamowienie::date::podaj(int tryb) {
    switch (tryb) {
        case 1:
            return this->dzien;
            break;
        case 2:
            return this->miesiac;
            break;
        case 3:
            return this->rok;
            break;
        default:
            std::cout<<"Niepoprawny tryb.";
    }
    return 0;
}

std::string Zamowienie::date::zwroc_date() {
    std::string data = "";
    data = inttostring(this->rok) +"-" + (miesiac > 9 ? "" : "0") + inttostring(this->miesiac)+"-"+ (this->dzien > 9 ? "" : "0") + inttostring(this->dzien);
    return data;

}

int Zamowienie::zwroc_id(){
    return id_produktu;
}

int Zamowienie::zwroc_ilosc() {
    return ilosc;
}

Zamowienie::date::date(){
    time_t tim = time(NULL);
    tm *mytime = localtime(&tim);
    dzien = mytime->tm_mday;
    miesiac = mytime->tm_mon+1;
    rok = mytime->tm_year + 1900;
}
Zamowienie::date::date(std::string dana){
    std::vector<std::string> data_zamowienia = split(dana, '-');
    rok = stringtoint(data_zamowienia[0]);
    miesiac = stringtoint(data_zamowienia[1]);
    dzien = stringtoint(data_zamowienia[2]);
}

void Zamowienie::wczytaj_zamowienia() {
    if(!lista_zamowien.empty()){
        return;
    }
    std::fstream file;
    file.open(path.c_str(), std::ios::in);
    std::string line = "";
    getline(file,line); //Wczytuje pierwsza linie tak aby pozbyc sie naglowkow
    while(getline(file,line)){
        std::vector<std::string> list = split(line,';');
        Zamowienie object(stringtoint(list[0]),list[1],stringtoint(list[2]),stringtoint(list[3]),stringtoint(list[4]));
        lista_zamowien.push_back(object);
    }
    file.close();
}

std::vector<Zamowienie> Zamowienie::find_pot_orders(int pot) {
    Zamowienie::wczytaj_zamowienia();
    std::vector<Zamowienie> pot_orders;
    for(Zamowienie el: lista_zamowien){
        if(el.roznica() <= pot) pot_orders.push_back(el);
    }
    lista_zamowien.clear();
    return pot_orders;
}

int Zamowienie::roznica() {
    date *dzis = new date;
    int roznica_dzien = 0;
    int roznica_miesiac = 0;
    int roznica_rok = dzis->podaj(3) - this->data_zamowienia->podaj(3);
    if (roznica_rok > 0) {
        roznica_miesiac = roznica_rok * 12;
    }
    roznica_miesiac = roznica_miesiac + (dzis->podaj(2) - this->data_zamowienia->podaj(2));
    if (roznica_miesiac > 0) {
        roznica_dzien = floor(roznica_miesiac * 30.5);
    }
    roznica_dzien = roznica_dzien +(dzis->podaj(1) - this->data_zamowienia->podaj(1));
    delete dzis;
    return roznica_dzien;
}
void Zamowienie::wypisz() {
    std::cout<<id<<setw(16 - (id > 9 ? 2 : 1))<<"| "<<data_zamowienia->zwroc_date()<<setw(8)<<"| "<<id_klienta<<setw(13 - (id_klienta > 9 ? 2 : 1))<<"| "<<id_produktu<<setw(14 - (id_produktu > 9 ? 2 : 1))<<"| "<<ilosc<<std::endl;
}