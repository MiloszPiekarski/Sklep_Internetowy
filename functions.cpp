#include <iostream>
#include "functions.h"

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
        std::cout << "Wprowadź swój wybór (1-4): ";
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                std::cout << "Wyświetlanie wszystkich produktów...\n";
                // kod
                break;
            case 2:
                std::cout << "Sortowanie produktów...\n";
                // kod
                break;
            case 3:
                std::cout << "Filtrowanie produktów...\n";
                // kod
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
                std::cout << "Dodawanie nowego produktu...\n";
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
