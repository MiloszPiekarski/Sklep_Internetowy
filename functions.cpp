#include <iostream>
#include "functions.h"
#include "fstream"
#include "cstring"
#include "vector"
#include "klasy/Produkt.h"
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

fstream OpenFile(string path)
{
    string fullPath = "..\\dane\\" + path;
    fstream file;
    file.open(fullPath);
    return file;
}
vector<string> split(const string &s, char delim) {
    vector<std::string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

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
                    string line, elementy[6];
                    getline(file, line);

                    cout << "ID" << " | Nazwa\t\t\t\t\t\t| Cena\t\t| Dostepnosc\t| Dodatkowe informacje" << endl;
                    while(getline(file, line))
                    {
                        vector<string> productV = split(line, ';');
                        Produkt* p = new Produkt(stoi(productV[0]), stoi(productV[1]), productV[2], productV[3], stoi(productV[4]), productV[5]);
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
                        cout << "Filtruj wedlug kategorii: " << endl;
                        for(int i = 2; i < Headers.size(); i++)
                        {
                            cout << (i - 1) << ". " << Headers[i] << endl;
                        }
                        cin >> wybor;
                    }
                    wybor++;

                    vector<vector<string>> allProducts;

                    cout << "ID" << setw( 20 ) << "| Nazwa\t\t\t\t\t\t| Cena\t\t| Dostepnosc\t| Dodatkowe informacje" << endl;
                    while(getline(file, line))
                    {
                        vector<string> product = split(line, ';');
                        // wyplenienie bialymi znakami w celu schludniejszego wyswieltenia w konsoli
                        int len = product[2].length();
                        int n = 0;
                        if(stoi(product[0]) < 10)
                        {
                            n = 51;
                        }
                        else
                        {
                            n = 50;
                        }
                        for(int j = len; j < n; j++)
                        {
                            product[2] += " ";
                        }
                        allProducts.push_back(product);
                    }
                    if(wybor == 4 || wybor == 4)
                    {
                        sort(allProducts.begin(), allProducts.end(),
                             [wybor](const std::vector<string>& a, const std::vector<string>& b) {
                                 return stoi(a[wybor]) < stoi(b[wybor]);
                             });
                    }
                    else
                    {
                        sort(allProducts.begin(), allProducts.end(),
                             [wybor](const std::vector<string>& a, const std::vector<string>& b) {
                                 return a[wybor] < b[wybor];
                             });
                    }


                    for(int i = 0; i < allProducts.size(); i++)
                    {
                        cout << allProducts[i][0] << " | " << allProducts[i][2]  << " | " << allProducts[i][3]  << " \t| " << allProducts[i][4]  << " \t\t| " << allProducts[i][5] << endl;

                    }

                    file.close();
                }
                break;
            case 3:
                {
                    std::cout << "Filtrowanie produktów...\n";

                    fstream file = OpenFile("kategorie.txt");

                    string line, elementy[2];
                    getline(file, line);

                    vector<int> categoryId;

                    while(getline(file, line))
                    {
                        vector<string> categories = split(line, ';');

                        cout << categories[0] << ". " << categories[1] << endl;
                        categoryId.push_back(stoi(categories[0]));
                    }
                    file.close();

                    int wybor = -1;
                    while(wybor < 1 || wybor > categoryId[categoryId.size() - 1])
                    {
                        cout << "Wybierz kategorie: (0 - " << categoryId[categoryId.size() - 1] << ")" << "\n";
                        cin >> wybor;
                    }

                    fstream file2 = OpenFile("produkty.txt");
                    string line2, elementy2[6];
                    getline(file2, line2);

                    cout << "ID" << setw( 20 ) << "| Nazwa\t\t\t\t\t\t| Cena\t\t| Dostepnosc\t| Dodatkowe informacje" << endl;
                    while(getline(file2, line2))
                    {
                        vector<string> product = split(line2, ';');
                        // wyplenienie bialymi znakami w celu schludniejszego wyswieltenia w konsoli
                        int len = product[2].length();
                        int n = 0;
                        if(stoi(product[0]) < 10)
                        {
                            n = 51;
                        }
                        else
                        {
                            n = 50;
                        }
                        for(int j = len; j < n; j++)
                        {
                            product[2] += " ";
                        }

                        //wypisywanie
                        if(stoi(product[1]) == wybor)
                        {
                            cout << product[0] << " | " << product[2]  << " | " << product[3]  << " \t| " << product[4]  << " \t\t| " << product[5] << endl;
                        }

                    }

                    file.close();

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
                int kategoria, ilosc = 0;
                std::cout << "Dodawanie nowego produktu...\n";
                cout << "1. Wybierz kategorię produktu\n";

                fstream file = OpenFile("kategorie.txt");
                string line;
                getline(file, line);

                while(getline(file, line))
                {
                    vector<string> categories = split(line, ';');

                    cout << categories[0] << ". " << categories[1] << endl;
                    ilosc++;
                }
                file.close();


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
    int wybor;
    do {
        std::cout << "Menu Edycji Produktu:\n";
        std::cout << "1. Edytuj istniejący produkt\n";
        std::cout << "2. Powrót do Menu Głównego\n";
        std::cout << "Wprowadź swój wybór (1-2): ";
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                std::cout << "Edycja istniejącego produktu...\n";
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

void menuUsuwanieProduktu() {
    int wybor;
    do {
        std::cout << "Menu Usuwania Produktu:\n";
        std::cout << "1. Usuń istniejący produkt\n";
        std::cout << "2. Powrót do Menu Głównego\n";
        std::cout << "Wprowadź swój wybór (1-2): ";
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                std::cout << "Usuwanie istniejącego produktu...\n";
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
