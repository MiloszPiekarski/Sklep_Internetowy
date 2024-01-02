#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <fstream>
#include "everywhere_functions.h"
#include <optional>

class Zamowienie{
private:
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
    Zamowienie(int p_id,std::string p_dane_zamowienie, int p_id_klienta, int p_id_produktu, int p_ilosc);
};