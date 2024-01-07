//
// Created by kkosz on 13.12.2023.
//
using namespace std;


#include "Produkt.h"
#include <iostream>
#include "fstream"
#include <sstream>
#include <string>
#include "iomanip"
#include <locale>
#include <codecvt>
#include <vector>
#include "../fileHelper.h"
#include <limits>
#include "regex"
#include <filesystem>
#include "everywhere_functions.h"

bool sprawdzCene(string C)
{
    string r = "^[1-9][0-9]*(.){1}[0-9]{2}$";
    if(regex_match(C, regex(r)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool sprawdzDostepnosc(string D)
{
    string r = "^[0-9]*$";
    if(regex_match(D, regex(r)))
    {
        return true;
    }
    else
    {
        return false;
    }
}

vector<Produkt> Produkt::lista_produktow;

void Produkt::wczytaj_produkty() {
    if(!lista_produktow.empty()){
        return;
    }
    std::string path = "..\\dane\\produkty.txt";
    std::fstream file;
    file.open(path.c_str(), std::ios::in);
    std::string line = "";
    getline(file,line);
    while(getline(file,line)){
        std::vector<std::string> info = split(line,';');
        Produkt object(stringtoint(info[0]), stringtoint(info[1]),info[2], info[3],stringtoint(info[4]),info[5]);
        lista_produktow.push_back(object);
    }
    file.close();
}

void Produkt::wypisz_liste() {
    for(Produkt el: lista_produktow){
        el.wypisz();
    }
}


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

        string cenaP, dostepnosc;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "Podaj nazwe produktu:\n";
        getline(cin, this->Nazwa);
        cout << "Podaj cene produktu: (np.: 220.99)\n";
        getline(cin, cenaP);
        while(!sprawdzCene(cenaP))
        {
            cout << "Podaj poprawną cene produktu: (np.: 220.99)\n"; //Cena jako float w postaci XXXX.XX
            getline(cin, cenaP);
        }
        this->Cena = cenaP;
        cout << "Podaj dostepnosc produktu:\n";
        getline(cin, dostepnosc);
        while(!sprawdzDostepnosc(dostepnosc))
        {
            cout << "Podaj poprawną dostepność produktu:\n"; // int
            getline(cin, dostepnosc);
        }
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

bool Produkt::edytujProdukt(int idProduktu, const string& nowaNazwa, const string& nowaCena, const string& nowaDostepnosc, const string& nowaCecha) {
    vector<string> linie;
    string linia;
    ifstream plikWe("../dane/produkty.txt");
    bool znaleziono = false;

    while (getline(plikWe, linia)) {
        stringstream ss(linia);
        string itemId;
        getline(ss, itemId, ';');
        itemId.erase(remove_if(itemId.begin(), itemId.end(), ::isspace), itemId.end());

        if (!itemId.empty() && std::all_of(itemId.begin(), itemId.end(), ::isdigit) && stoi(itemId) == idProduktu) {
            znaleziono = true;
            string zmodyfikowanaCena = nowaCena.empty() ? this->Cena : nowaCena;
            string zmodyfikowanaDostepnosc = nowaDostepnosc.empty() ? std::to_string(this->Dostepnosc) : nowaDostepnosc;

            string zmodyfikowanaLinia = to_string(idProduktu) + ";" + to_string(IDs.Id_Kategorii) + ";" + nowaNazwa + ";" + zmodyfikowanaCena + ";" + zmodyfikowanaDostepnosc + ";" + nowaCecha;
            linie.push_back(zmodyfikowanaLinia);
        } else {
            linie.push_back(linia);
        }
    }
    plikWe.close();

    if (!znaleziono) {
        cout << "Produkt o ID " << idProduktu << " nie został znaleziony." << endl;
        return false;
    }

    ofstream plikWy("../dane/produkty.txt");
    for (size_t i = 0; i < linie.size(); i++) {
        plikWy << linie[i];
        if (i < linie.size() - 1) {
            plikWy << endl;
        }
    }
    plikWy.close();

    return true;
}


bool Produkt::wczytajProdukt(int idProduktu) {
    std::string sciezkaDoPliku = "../dane/produkty.txt"; // Ustawiamy względną ścieżkę do folderu 'dane'
    std::fstream plik(sciezkaDoPliku);

    if (!plik.is_open()) {
        std::cerr << "Nie można otworzyć pliku produkty.txt" << std::endl;
        return false;
    }

    std::string linia;
    while (getline(plik, linia)) {
        std::stringstream liniaStream(linia);
        std::string segment;
        std::vector<std::string> segmenty;

        while(std::getline(liniaStream, segment, ';')) {
            segmenty.push_back(segment);
        }

        if (segmenty.size() >= 6) {
            // Sprawdzanie, czy ID produktu i ID kategorii to liczby
            if (std::all_of(segmenty[0].begin(), segmenty[0].end(), ::isdigit) &&
                std::stoi(segmenty[0]) == idProduktu &&
                std::all_of(segmenty[1].begin(), segmenty[1].end(), ::isdigit)) {

                this->IDs.Id = std::stoi(segmenty[0]);
                this->IDs.Id_Kategorii = std::stoi(segmenty[1]);
                this->Nazwa = segmenty[2];
                this->Cena = segmenty[3]; // Zakładamy, że cena jest przechowywana jako string
                this->Dostepnosc = std::all_of(segmenty[4].begin(), segmenty[4].end(), ::isdigit) ? std::stoi(segmenty[4]) : 0;
                this->CechaSzczegolna = segmenty[5];
                plik.close();
                return true;
            }
        }
    }

    plik.close();
    return false; // Produkt nie został znaleziony
}

bool Produkt::usunProdukt(int idProduktu) {
    vector<string> linie;
    string linia;
    ifstream plikWe("../dane/produkty.txt");
    bool znaleziono = false;
    string produktDoUsuniecia;

    if (getline(plikWe, linia)) {
        linie.push_back(linia); // Zachowaj nagłówek
    }

    while (getline(plikWe, linia)) {
        stringstream ss(linia);
        string itemId;
        getline(ss, itemId, ';');
        itemId.erase(remove_if(itemId.begin(), itemId.end(), ::isspace), itemId.end());

        if (!itemId.empty() && std::all_of(itemId.begin(), itemId.end(), ::isdigit) && stoi(itemId) == idProduktu) {
            znaleziono = true;
            produktDoUsuniecia = linia; // Zapisz informacje o produkcie do usunięcia
            continue;
        }
        linie.push_back(linia);
    }
    plikWe.close();

    if (!znaleziono) {
        cout << "Produkt o ID " << idProduktu << " nie został znaleziony." << endl;
        return false;
    }

    // Rozdziel informacje o produkcie i wyświetl z nagłówkami
    stringstream sstream(produktDoUsuniecia);
    string pole;
    vector<string> pola;
    while (getline(sstream, pole, ';')) {
        pola.push_back(pole);
    }

    cout << "ID produktu: " << pola[0] << endl;
    cout << "ID kategorii: " << pola[1] << endl;
    cout << "Nazwa: " << pola[2] << endl;
    cout << "Cena: " << pola[3] << endl;
    cout << "Dostępność: " << pola[4] << endl;
    cout << "Cecha: " << pola[5] << endl;

    cout << "Czy na pewno chcesz usunąć ten produkt? (tak/nie): ";
    string odpowiedz;
    cin >> odpowiedz;
    if (odpowiedz != "tak") {
        cout << "Anulowano usuwanie produktu." << endl;
        return false;
    }

    ofstream plikWy("../dane/produkty.txt");
    for (size_t i = 0; i < linie.size(); i++) {
        plikWy << linie[i];
        if (i < linie.size() - 1) { // Kontrola, aby nie dodawać nowej linii po ostatniej linii
            plikWy << endl;
        }
    }
    plikWy.close();

    cout << "Produkt został pomyślnie usunięty." << endl;
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