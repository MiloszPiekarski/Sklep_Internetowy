//
// Created by kkosz on 13.12.2023.
//
using namespace std;


#include "Produkt.h"
#include <iostream>
#include "fstream"
#include "iomanip"
#include <locale>
#include <codecvt>
#include <vector>
#include "../fileHelper.h"
#include <limits>


int ilePolskich(const string str) {
    // Convert narrow string to wide string
    wstring_convert<std::codecvt_utf8<wchar_t>> converter;
    wstring wideStr = converter.from_bytes(str);

    // Define a set of Polish characters
    wstring polishCharacters = L"ąćęłńóśźżĄĆĘŁŃÓŚŹŻ";

    // Count occurrences of Polish characters
    int count = 0;
    for (wchar_t ch : wideStr) {
        if (polishCharacters.find(ch) != wstring::npos) {
            count++;
        }
    }

    return count;
}

// wyplenienie bialymi znakami w celu schludniejszego wyswieltenia w konsoli
string Produkt::formatujNazwe()
{
    string nazwaf = Nazwa;
    int len = 0;
    len = Nazwa.length();
    len = len - ilePolskich(Nazwa);
    int n = 0;
    if(IDs.Id < 10)
    {
        n = 81;
    }
    else
    {
        n = 80;
    }
    for(int j = len; j < n; j++)
    {
        nazwaf += " ";
    }
    return nazwaf;
}

Produkt::Produkt(int Id_p, int Id_kategorii_p, string Nazwa_p, string Cena_p, int Dostepnosc_p, string CechaSzczegolna_p)
{
    IDs.Id = Id_p;
    IDs.Id_Kategorii = Id_kategorii_p;
    Nazwa = Nazwa_p;
    Cena = Cena_p;
    Dostepnosc = Dostepnosc_p;
    CechaSzczegolna = CechaSzczegolna_p;
}

Produkt::Produkt()
{

}

void Produkt::wypisz()
{
//    cout << IDs.Id << " | " << Nazwa << " | ";
//    printf("%.2f", Cena );
//    cout  << " \t\t\t| " << Dostepnosc  << " \t\t\t| " << CechaSzczegolna << endl;

    string nazwaf = this->formatujNazwe();
    cout << IDs.Id << " | " << nazwaf << " | " << Cena << "\t | " << Dostepnosc  << "\t\t\t| " << CechaSzczegolna << endl;

}

bool Produkt::uzupelnijDane()
{
    int Idp, Idk = -1;

    //Przydzielenie nastepnego Id produktu na podsatwie produktow w pliku
    fstream file = OpenFile("produkty.txt");
    string line;
    while(getline(file, line))
    {
        //przejscie do ostatniej linijki
    }
    Idp = stoi(line.substr(0, line.find(';'))) + 1;


    //Wybor kategorii
    fstream file2 = OpenFile("kategorie.txt");
    string line2;
    getline(file2, line2);

    vector<int> categoryId;
    while(getline(file2, line2))
    {
        vector<string> category = split(line2, ';');

        cout << category[0] << ". " << category[1] << endl;
        categoryId.push_back(stoi(category[0]));
    }
    file.close();
    while(Idk < 1 || Idk > categoryId[categoryId.size() - 1])
    {
        cout << "Podaj numer kategorii produktu\n";
        cin >> Idk;
    }

    try
    {
        this->IDs.Id = Idp;
        this->IDs.Id_Kategorii = Idk;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        string dostepnosc;
        cout << "Podaj nazwe produktu:\n";
        getline(cin, this->Nazwa);
        cout << "Podaj cene produktu:\n"; //Cena jako float w postaci XXXX.XX
        getline(cin, this->Cena);
        cout << "Podaj dostepnosc produktu:\n"; // int
        getline(cin, dostepnosc);
        this->Dostepnosc = stoi(dostepnosc);
        cout << "Podaj cechę produktu:\n";
        getline(cin, this->CechaSzczegolna);
    }
    catch(exception &e)
    {
        return false;
    }

    return true;
}

bool Produkt::dodajProdukt() {
    fstream plik = OpenFile("produkty.txt");
    plik.seekp(0, ios_base::end);
    plik.seekg(0, ios_base::end);
    plik << "\n";
    string produkt = to_string(this->IDs.Id) + ";" + to_string(this->IDs.Id_Kategorii) + ";" + this->Nazwa + ";" + this->Cena + ";" + to_string(this->Dostepnosc) + ";" + this->CechaSzczegolna;
    plik << produkt;
    plik.close();


    return true;

}



//Gettery
string Produkt::getNazwa() const
{
    return Nazwa;
}
float Produkt::getCena() const
{
    return stof(Cena);
}
int Produkt::getDostepnosc() const
{
    return Dostepnosc;
}
string Produkt::getCechaSzczegolna() const
{
    return CechaSzczegolna;
}
int Produkt::GetId() const
{
    return IDs.Id;
}
int Produkt::getId_Kategorii() const
{
    return IDs.Id_Kategorii;
}




