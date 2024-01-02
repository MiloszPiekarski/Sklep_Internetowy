#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include <optional>
#include "Zamowienia.h"
#include "everywhere_functions.h"

std::vector<Zamowienie> Zamowienie::lista_zamowien;
std::string path = "dane/zamowienia.txt";

Zamowienie::Zamowienie(int p_id,std::string p_dane_zamowienie, int p_id_klienta, int p_id_produktu, int p_ilosc) {
    data_zamowienia.emplace(p_dane_zamowienie);
    id_klienta = p_id_klienta;
    id_produktu = p_id_produktu;
    ilosc = p_ilosc;
    id = p_id;
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
        default:
            std::cout<<"Niepoprawny tryb."
    }
}

std::string Zamowienie::date::zwroc_date() {
    std::string data = "";
    data = inttostring(this->rok) +"-"+ inttostring(this->miesiac)+"-"+ inttostring(this->dzien);
    return data;

}

int Zamowienie::zwroc_id(){
    return id;
}

int Zamowienie::zwroc_ilosc() {
    return ilosc;
}

Zamowienie::date::date(){
    time_t tim = time(0);
    tm *mytime = localtime(&tim);
    dzien = mytime->tm_mday;
    miesiac = mytime->tm_mon;
    rok = mytime->tm_year;
}
Zamowienie::date::date(std::string dana){
    std::vector<std::string> data_zamowienia = split(dana, '-');
    rok = stringtoint(data_zamowienia[0]);
    miesiac = stringtoint(data_zamowienia[1]);
    dzien = stringtoint(data_zamowienia[2]);
}

void Zamowienie::wczytaj_zamowienia() {
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

int Zamowienie::roznica() {
    date dzis;
    int roznica_dzien = 0;
    int roznica_miesiac = 0;
    int roznica_rok = this->data_zamowienia->podaj(3) - dzis.podaj(3);
    if (roznica_rok > 0) {
        roznica_miesiac = roznica_rok * 12;
    }
    roznica_miesiac = roznica_miesiac + (this->data_zamowienia->podaj(2) - dzis.podaj(2));
    if (roznica_miesiac > 0) { //pierdole te kurewskie przestepne miesiace, licze kazdy jako 30,5 i zaokraglam w dol.
        roznica_dzien = floor(roznica_miesiac * 30.5);
    }
    roznica_dzien = this->data_zamowienia->podaj(1) - dzis.podaj(1);
    return roznica_dzien;
}