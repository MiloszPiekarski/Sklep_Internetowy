#include "Raport.h"
#include <time.h>
#include "everywhere_functions.h"
#include <iostream>
#include <fstream>
#include "../fileHelper.h"
#include <iomanip>
#include "Zamowienia.h"
#include "Produkt.h"
#include <map>
#include "SprzetElektroniczny.h"
std::vector<Raport> Raport::lista_raportow;
int Raport::id = 1;
std::string Raport::dzisiejsza_data() {
    time_t tim = time(0);
    tm *mytime = localtime(&tim);
    std::string g = inttostring(mytime->tm_year+1900) + (mytime->tm_mon < 10 ? "-0" : "-") + inttostring(mytime->tm_mon+1)  + (mytime->tm_mday < 10 ? "-0" : "-") + inttostring(mytime->tm_mday);
    return g;
}
Raport::Raport(){}
Raport::Statistics::Statistics() {
    *amount = 0;
    *income = 0;
}
Raport::Statistics::Statistics(int gAmount, int gIncome, int gId, std::string gName) {
    *amount = gAmount;
    *income = gIncome;
    *id = gId;
    *name = gName;
}
Raport::Statistics::~Statistics() {
    delete amount;
    delete income;
    delete id;
    delete name;
}
void Raport::wczytaj_raporty() {
    if(!lista_raportow.empty()){
        return;
    }
    std::fstream file;
    file = OpenFile("raporty.txt");
    std::string line = "";
    getline(file,line); //Wczytuje pierwsza linie tak aby pozbyc sie naglowkow
    Raport *object;
    while(getline(file,line)){
        std::vector<std::string> list = split(line,';');
        if (list.size() >= 6) { // Make sure there are enough elements in the vector
            object = new Raport(list[2],list[3],stringtoint(list[4]), stringtoint_zz(list[5]),list[1]);
            lista_raportow.push_back(*object);
        } else {
            std::cerr << "Invalid line format: " << line << "\n";
        }
    }
    file.close();
    delete object;
}
std::map<int,Raport::Statistics> pot_get_income(std::vector<Zamowienie> pot_orders) {
    Produkt::wczytaj_produkty();
    std::map<int,Raport::Statistics> value;
    for(Zamowienie el: pot_orders){
        *value[el.zwroc_id()].amount += el.zwroc_ilosc();
    }
    for(Produkt el: Produkt::lista_produktow){
        try{
            int index = el.GetId();
            value.at(index);
            *value[index].id = index;
            *value[index].income = (float)*value[index].amount * el.getCena();
            *value[index].name = el.getNazwa();
        }
        catch(const exception &e){}
    }
    Produkt::lista_produktow.clear();
    return value;
}

void Raport::generuj_raport(int pot, std::string pot_2) {
    std::vector<Zamowienie> pot_orders = Zamowienie::find_pot_orders(pot);
    map<int,Statistics> pot_info = pot_get_income(pot_orders);
    Statistics *best_products = new Statistics[3];
    float *sum = new float;
    *sum = 0;
    for(auto i = pot_info.begin(); i != pot_info.end(); i++) {
        if (*i->second.amount > *best_products[2].amount) {
            if (*i->second.amount > *best_products[1].amount) {
                if (*i->second.amount > *best_products[0].amount) {
                    best_products[2] = best_products[1];
                    best_products[1] = best_products[0];
                    best_products[0] = i->second;
                } else {
                    best_products[2] = best_products[1];
                    best_products[1] = i->second;
                }
            } else {
                best_products[2] = i->second;
            }
            *sum += *i->second.income;
        }
    }
    std::cout<<"Raport za ostatnich "<<pot<<" dni:\n";
    std::cout<<"Najlepiej sprzedajace sie produkty:\n";
    for(int i=0;i<3;i++)
        *best_products[i].amount > 0 ? std::cout<<i+1<<"."<<*best_products[i].name<<" -- "<<*best_products[i].amount<<" sprzedanych sztuk\n":std::cout<<"";
    std::cout<<"Laczny obrot w tym okresie wynosil "<<*sum<< " zlotych\n";
    wczytaj_raporty();
    *best_products[0].income = *sum;
    this->info = &best_products[0];
    *this->data = dzisiejsza_data();
    *this->period_of_time = pot_2;
    *this->id_raportu = id;
    id++;
    lista_raportow.clear();
    id = 0;
}

void Raport::wypisz_liste() {
    for(Raport el: lista_raportow){
        el.wypisz();
    }
}
Raport::~Raport(){
}
void Raport::dopisz_do_pliku() {
    std::fstream file;
    std::string path = "../dane/raporty.txt";
    file.open(path.c_str(), std::ios::app);
    std::string linijka = "\n" + inttostring(*this->id_raportu) + ";" + *this->data + ";" + *this->period_of_time + ";" + *this->info->name + ";" +
            inttostring(*this->info->id) + ";" + inttostring_zz(*this->info->income);
    file.write(&linijka[0],linijka.length());
    file.close();
}
Raport::Raport(std::string p_zakres_czasowy,std::string p_najlepszy_produkt,int p_ID_produktu, float p_dochod,std::string p_data) {
    *data = p_data;
    *period_of_time = p_zakres_czasowy.length() > 8 ? p_zakres_czasowy : "Ostatni " + p_zakres_czasowy;
    *info->id = p_ID_produktu;
    *info->income = p_dochod;
    *info->name = p_najlepszy_produkt;
    *id_raportu = id;
    id++;
}

void Raport::wypisz() {
    std::cout<<*id_raportu<<setw(13 - (*id_raportu > 9 ? 2 : 1))<<"| "<<*data<<setw(9)<<"| "<<*period_of_time<<setw(25 - (period_of_time->length()))<<"| "<<*info->name<<setw(40 - (info->name->length()))<<"| "<<*info->id<<setw(14 - (*info->id > 9 ? 2 : 1))<<"| "<<*info->income<<std::endl;
}

