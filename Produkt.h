//
// Created by kkosz on 13.12.2023.
//

#ifndef PROJEKT_PRODUKT_H
#define PROJEKT_PRODUKT_H


class Produkt {
protected:
    int Id_Produktu;
    int Id_Kategorii;
    std::string Nazwa;
    float Cena;
    int Dostepnosc;

public:
    Produkt(){

    };
};


#endif //PROJEKT_PRODUKT_H
