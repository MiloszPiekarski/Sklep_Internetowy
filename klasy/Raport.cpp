#include "Raport.h"
#include <time.h>
#include "everywhere_functions.h"
#include <iostream>
#include <fstream>
#include "../fileHelper.h"
#include <iomanip>
int Raport::id = 1;
std::vector<Raport> Raport::lista_raportow;
std::string Raport::dzisiejsza_data() {
    time_t tim = time(0);
    tm *mytime = localtime(&tim);
    std::string g = inttostring(mytime->tm_year+1900) + (mytime->tm_mon < 10 ? "-0" : "-") + inttostring(mytime->tm_mon+1)  + (mytime->tm_mday < 10 ? "-0" : "-") + inttostring(mytime->tm_mday);
    return g;
}
Raport::Raport(){}
void Raport::wczytaj_raporty() {
    if(!lista_raportow.empty()){
        return;
    }
    std::fstream file;
    file = OpenFile("raporty.txt");
    std::string line = "";
    getline(file,line); //Wczytuje pierwsza linie tak aby pozbyc sie naglowkow
    while(getline(file,line)){
        std::vector<std::string> list = split(line,';');
        if (list.size() >= 6) { // Make sure there are enough elements in the vector
            Raport object(list[2],list[3],stringtoint(list[4]), stringtoint_zz(list[5]),list[1]);
            lista_raportow.push_back(object);
        } else {
            std::cerr << "Invalid line format: " << line << "\n";
        }
    }
    file.close();
}

void Raport::wypisz_liste() {
    for(Raport el: lista_raportow){
        el.wypisz();
    }
}

void Raport::dopisz_do_pliku() {
    std::fstream file;
    std::string path = "../dane/raporty.txt";
    file.open(path.c_str(), std::ios::app);
    std::string linijka = "\n" + inttostring(this->id_raportu) + ";" + this->data + ";" + this->zakres_czasowy + ";" + this->najlepszy_produkt + ";" +
            inttostring(this->id_produktu) + ";" + inttostring_zz(this->dochod);
    file.write(&linijka[0],linijka.length());
    file.close();
}
Raport::Raport(std::string p_zakres_czasowy,std::string p_najlepszy_produkt,int p_ID_produktu, float p_dochod,std::string p_data) {
    id_raportu = id;
    data = p_data;
    zakres_czasowy = p_zakres_czasowy.length() > 8 ? p_zakres_czasowy : "Ostatni " + p_zakres_czasowy;
    najlepszy_produkt = p_najlepszy_produkt;
    id_produktu = p_ID_produktu;
    dochod = p_dochod;
    id++;
}

void Raport::wypisz() {
    std::cout<<id_raportu<<setw(13 - (id_raportu > 9 ? 2 : 1))<<"| "<<data<<setw(9)<<"| "<<zakres_czasowy<<setw(25 - (zakres_czasowy.length()))<<"| "<<najlepszy_produkt<<setw(40 - (najlepszy_produkt.length()))<<"| "<<id_produktu<<setw(14 - (id_produktu > 9 ? 2 : 1))<<"| "<<dochod<<std::endl;
}

