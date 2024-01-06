#include <iostream>
#include "functions.h"
#include "fstream"
#include "vector"
#include "klasy/Produkt.h"
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "fileHelper.h"

using namespace std;



void wyswietlMenuGlowne() {
    std::cout << "Menu Główne:\n";
    std::cout << "1. Przeglądaj Produkty\n";
    std::cout << "2. Dodaj Produkt\n";
    std::cout << "3. Edytuj Produkt\n";
    std::cout << "4. Usuń Produkt\n";
    std::cout << "5. Generuj Raport\n";
    std::cout << "6. Odczytaj z Bazy Danych\n";
    std::cout << "7. Wyjście\n";
    std::cout << "\n\n";
}

void menuPrzegladaniaProduktow() {
    int wybor;
    do {
        std::cout << "Menu Przeglądania Produktów:\n";
        std::cout << "1. Wyświetl wszystkie produkty\n";
        std::cout << "2. Sortuj produkty\n";
        std::cout << "3. Filtrowanie produktów\n";
        std::cout << "4. Powrót do Menu Głównego\n";
        std::cout << "Wprowadź swój wybór (1-4):";
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                {
                    std::cout << "Wyświetlanie wszystkich produktów...\n";
                    fstream file = OpenFile("produkty.txt");
                    string line;
                    getline(file, line);

                    cout << "ID" << "| Nazwa" << setw(123) <<" | Cena \t | Dostepnosc \t| Dodatkowe informacje\n" << endl;
                    while(getline(file, line))
                    {
                        vector<string> productV = split(line, ';');
                        Produkt* p = new Produkt(stoi(productV[0]), stoi(productV[1]), productV[2], (productV[3]), stoi(productV[4]), productV[5]);
                        p->wypisz();
                    }

                    file.close();
                }
                break;
            case 2:
                {
                    std::cout << "Sortowanie produktow...\n";
                    fstream file = OpenFile("produkty.txt");
                    string line, elementy[6];
                    getline(file, line);

                    vector<string> Headers = split(line,';');

                    int wybor = -1;
                    while(wybor < 1 || wybor > Headers.size())
                    {
                        cout << "Sortuj wedlug kategorii: " << endl;
                        for(int i = 2; i < Headers.size(); i++)
                        {
                            cout << (i - 1) << ". " << Headers[i] << endl;
                        }
                        cin >> wybor;
                    }

                    vector<Produkt*> allProducts;


                    while(getline(file, line))
                    {
                        vector<string> productV = split(line, ';');
                        Produkt* p = new Produkt(stoi(productV[0]), stoi(productV[1]), productV[2], (productV[3]), stoi(productV[4]), productV[5]);
                        allProducts.push_back(p);
                    }
                    if(wybor == 2)
                    {
                        sort(allProducts.begin(), allProducts.end(),
                             [wybor](const Produkt* a, const Produkt* b) {
                                 return a->getCena() < b->getCena();
                             });
                    }
                    else if(wybor == 1)
                    {
                        sort(allProducts.begin(), allProducts.end(),
                             [wybor](const Produkt* a, const Produkt* b) {
                                 return a->getNazwa() < b->getNazwa();
                             });
                    }
                    else if(wybor == 3)
                    {
                        sort(allProducts.begin(), allProducts.end(),
                             [wybor](const Produkt* a, const Produkt* b) {
                                 return a->getDostepnosc() < b->getDostepnosc();
                             });
                    }
                    else if(wybor == 4)
                    {
                        sort(allProducts.begin(), allProducts.end(),
                             [wybor](const Produkt* a, const Produkt* b) {
                                 return a->getCechaSzczegolna() < b->getCechaSzczegolna();
                             });
                    }
                    else
                    {
                        cout << "Źle wybrany numerek!";
                        break;
                    }

                    cout << "ID" << "| Nazwa" << setw(123) <<" | Cena \t | Dostepnosc \t| Dodatkowe informacje\n" << endl;
                    for(int i = 0; i < allProducts.size(); i++)
                    {
                        allProducts[i]->wypisz();
                    }

                    file.close();
                }
                break;
            case 3:
                {
                    std::cout << "Filtrowanie produktów...\n";

                    fstream file = OpenFile("kategorie.txt");

                    string line;
                    getline(file, line);

                    vector<int> categoryId;
                    while(getline(file, line))
                    {
                        vector<string> category = split(line, ';');

                        cout << category[0] << ". " << category[1] << endl;
                        categoryId.push_back(stoi(category[0]));
                    }
                    file.close();

                    int wybor = -1;
                    while(wybor < 1 || wybor > categoryId[categoryId.size() - 1])
                    {
                        cout << "Wybierz kategorie: (1 - " << categoryId.size() << ")" << "\n";
                        cin >> wybor;
                    }
                    wybor--;

                    fstream file2 = OpenFile("produkty.txt");
                    string line2;
                    getline(file2, line2);

                    vector<Produkt*> allProducts;


                    while(getline(file2, line2))
                    {
                        vector<string> productV = split(line2, ';');
                        Produkt* p = new Produkt(stoi(productV[0]), stoi(productV[1]), productV[2], (productV[3]), stoi(productV[4]), productV[5]);
                        if(p->getId_Kategorii() == categoryId[wybor])
                        {
                            allProducts.push_back(p);
                        }
                    }
                    for(Produkt* p : allProducts)
                    {
                        p->wypisz();
                    }


                    file2.close();

                }
                break;
            case 4:
                break; // Powrót do menu głównego
            default:
                std::cout << "Nieprawidłowy wybór. Proszę wprowadzić liczbę od 1 do 4.\n";
                break;
        }
        std::cout << "\n\n";
    } while (wybor != 4);
}

void menuDodawaniaProduktu() {
    int wybor;
    do {
        std::cout << "Menu Dodawania Produktu:\n";
        std::cout << "1. Dodaj nowy produkt\n";
        std::cout << "2. Powrót do Menu Głównego\n";
        std::cout << "Wprowadź swój wybór (1-2): ";
        std::cin >> wybor;

        switch (wybor) {
            case 1:
            {
                bool wpisano = false;
                Produkt* pNew = new Produkt();
                while(!wpisano)
                {
                    if(pNew->uzupelnijDane())
                    {
                        wpisano = true;
                    }
                }

                pNew->wypisz();
                pNew->dodajProdukt();

            }
                break;
            case 2:
                break; // Powrót do menu głównego
            default:
                std::cout << "Nieprawidłowy wybór. Proszę wprowadzić liczbę od 1 do 2.\n";
                break;
        }
        std::cout << "\n\n";
    } while (wybor != 2);
}


void menuEdycjiProduktu() {
    while (true) {
        std::cout << "Podaj ID produktu do edycji (lub 0, aby powrócić do menu głównego): ";
        int idProduktu;
        std::cin >> idProduktu;
        std::cin.ignore();

        if (idProduktu == 0) {
            std::cout << "Powrót do menu głównego (naciśnij 'Enter')." << std::endl;
            break;
        }

        Produkt produkt;
        if (!produkt.wczytajProdukt(idProduktu)) {
            std::cout << "Produkt o podanym ID nie istnieje." << std::endl;
            continue;
        }

        // Wyświetlenie obecnych danych produktu
        cout << "ID " << "| Nazwa" << setw(123) <<" |  Cena \t | Dostepnosc \t| Dodatkowe informacje\n" << endl;
        produkt.wypisz();

        // Zapytanie o potwierdzenie edycji
        std::cout << "Czy na pewno chcesz edytować ten produkt? (tak/nie): ";
        std::string potwierdzenie;
        getline(std::cin, potwierdzenie);
        if (potwierdzenie != "tak") {
            std::cout << "Anulowano edycję produktu." << std::endl;
            continue;
        }

        // Zbieranie nowych danych produktu od użytkownika
        std::string nowaNazwa, nowaCena, nowaDostepnosc, nowaCecha;
        std::cout << "Podaj nową nazwę produktu (obecna: " << produkt.getNazwa() << "): ";
        getline(std::cin, nowaNazwa);
        nowaNazwa = nowaNazwa.empty() ? produkt.getNazwa() : nowaNazwa;

        std::cout << "Podaj nową cenę produktu (obecna: " << produkt.getCena() << "): ";
        getline(std::cin, nowaCena);
        nowaCena = nowaCena.empty() ? std::to_string(produkt.getCena()) : nowaCena;

        std::cout << "Podaj nową dostępność produktu (obecna: " << produkt.getDostepnosc() << "): ";
        getline(std::cin, nowaDostepnosc);
        nowaDostepnosc = nowaDostepnosc.empty() ? std::to_string(produkt.getDostepnosc()) : nowaDostepnosc;

        std::cout << "Podaj nową cechę szczególną produktu (obecna: " << produkt.getCechaSzczegolna() << "): ";
        getline(std::cin, nowaCecha);
        nowaCecha = nowaCecha.empty() ? produkt.getCechaSzczegolna() : nowaCecha;

        // Aktualizacja danych produktu
        if (produkt.edytujProdukt(idProduktu, nowaNazwa, nowaCena, nowaDostepnosc, nowaCecha)) {
            std::cout << "Produkt został pomyślnie zaktualizowany (naciśnij 'Enter')." << std::endl;
        } else {
            std::cout << "Nie udało się zaktualizować produktu." << std::endl;
        }
        break;
    }
}


void menuUsuwanieProduktu() {
    int idProduktu;
    cout << "Podaj ID produktu do usunięcia (lub 0 aby powrócić do menu głównego): ";
    cin >> idProduktu;

    // Jeśli użytkownik wpisał 0, powrót do menu głównego
    if (idProduktu == 0) {
        cout << "Powrót do menu głównego." << endl;
        return;
    }

    Produkt produkt;
    if (!produkt.usunProdukt(idProduktu)) {
        cout << "Nie udało się usunąć produktu." << endl;
    }
}

void menuGenerowaniaRaportu() {
    int wybor;
    do {
        std::cout << "Menu Generowania Raportu:\n";
        std::cout << "1. Wybierz zakres czasowy dla raportu\n";
        std::cout << "2. Powrót do Menu Głównego\n";
        std::cout << "Wprowadź swój wybór (1-2): ";
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                std::cout << "Wybieranie zakresu czasowego dla raportu...\n";
                // kod
                break;
            case 2:
                break; // Powrót do menu głównego
            default:
                std::cout << "Nieprawidłowy wybór. Proszę wprowadzić liczbę od 1 do 2.\n";
                break;
        }
        std::cout << "\n\n";
    } while (wybor != 2);
}

void menuOdczytuZBazyDanych() {
    int wybor;
    do {
        std::cout << "Menu Odczytu z Bazy Danych:\n";
        std::cout << "1. Produkty\n";
        std::cout << "2. Kategorie\n";
        std::cout << "3. Zamówienia\n";
        std::cout << "4. Pozycje Zamówień\n";
        std::cout << "5. Klienci\n";
        std::cout << "6. Raporty\n";
        std::cout << "7. Powrót do Menu Głównego\n";
        std::cout << "Wprowadź swój wybór (1-7): ";
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                std::cout << "Odczyt z tabeli Produkty...\n";
                // kod
                break;
            case 2:
                std::cout << "Odczyt z tabeli Kategorie...\n";
                // kod
                break;
            case 3:
                std::cout << "Odczyt z tabeli Zamówienia...\n";
                // kod
                break;
            case 4:
                std::cout << "Odczyt z tabeli Pozycje Zamówień...\n";
                // kod
                break;
            case 5:
                std::cout << "Odczyt z tabeli Klienci...\n";
                // kod
                break;
            case 6:
                std::cout << "Odczyt z tabeli Raporty...\n";
                // kod
                break;
            case 7:
                break; // Powrót do menu głównego
            default:
                std::cout << "Nieprawidłowy wybór. Proszę wprowadzić liczbę od 1 do 7.\n";
                break;
        }
        std::cout << "\n\n";
    } while (wybor != 7);
}
