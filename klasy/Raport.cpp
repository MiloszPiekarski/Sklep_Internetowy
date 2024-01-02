#include "Raport.h"
#include <time.h>
#include "everywhere_functions.h"
#include <iostream>
#include <fstream>

int Raport::id = 1;
std::string path = "dane/raporty.txt";
std::vector<Raport> lista_raportow;

std::string Raport::dzisiejsza_data() {
    time_t tim = time(0);
    tm *mytime = localtime(&tim);
    std::string g = inttostring(mytime->tm_year) + "-" + inttostring(mytime->tm_mon)  + "-" + inttostring(mytime->tm_mday);
    return g;
}
Raport::Raport(){}
void Raport::wczytaj_raporty() {
    std::fstream file;
    file.open(path.c_str(), std::ios::in);
    std::string line = "";
    getline(file,line); //Wczytuje pierwsza linie tak aby pozbyc sie naglowkow
    while(getline(file,line)){
        std::vector<std::string> list = split(line,';');
        Raport object(list[2],list[3],stringtoint(list[4]), stringtoint(list[5]),list[1]);
        lista_raportow.push_back(object);
    }
    file.close();
}

void Raport::dopisz_do_pliku() {
    std::fstream file;
    file.open("dane/raporty.txt", std::ios::app);
    std::string linijka = inttostring(this->id_raportu) + ";" + this->data + ";" + this->zakres_czasowy + ";" + this->najlepszy_produkt + ";" +
            inttostring(this->id_produktu) + ";" + inttostring(this->dochód);
    file.write(linijka);
    file.close();
}
Raport::Raport(std::string p_zakres_czasowy,std::string p_najlepszy_produkt,int p_ID_produktu, int p_dochod,std::string p_data = dzisiejsza_data()) {
    id_raportu = id;
    data = p_data;
    zakres_czasowy = "Ostatni " + p_zakres_czasowy;
    najlepszy_produkt = p_najlepszy_produkt;
    id_produktu = id;
    dochód = p_dochod;
    id++;
}
