#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include "everywhere_functions.h"
#include <optional>

class Zamowienie{
private:
    int id_klienta;
    int id_produktu;
    int ilosc;
    int id;
    class date{
    protected:
        int rok,miesiac,dzien;
    public:
        date();
        date(std::string dana);
        std::string zwroc_date();
        int podaj(int tryb);
    };
    std::optional<date> data_zamowienia;
public:
    static std::vector<Zamowienie> lista_zamowien;
    static void wczytaj_zamowienia();
    Zamowienie(int p_id,std::string p_dane_zamowienie, int p_id_klienta, int p_id_produktu, int p_ilosc);
    int zwroc_id();
    int zwroc_ilosc();
    int roznica();
    void wypisz();
    static void wypisz_liste();
};