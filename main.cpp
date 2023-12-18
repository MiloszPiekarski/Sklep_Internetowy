#include <iostream>
#include <limits>
#include "functions.h"
#include <locale>
#include <codecvt>


int main() {

    int wybor;

    do {
        wyswietlMenuGlowne();
        std::cout << "Wprowadź swój wybór (1-7): ";
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                menuPrzegladaniaProduktow();
                break;
            case 2:
                menuDodawaniaProduktu();
                break;
            case 3:
                menuEdycjiProduktu();
                break;
            case 4:
                menuUsuwanieProduktu();
                break;
            case 5:
                menuGenerowaniaRaportu();
                break;
            case 6:
                menuOdczytuZBazyDanych();
                break;
            case 7:
                std::cout << "Zamykanie programu. Do widzenia!\n";
                break;
            default:
                std::cout << "Nieprawidłowy wybór. Proszę wprowadzić liczbę od 1 do 7.\n";
                break;
        }

        // Wyczyść bufor wejścia
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while (wybor != 7);
    std::cout<<"Krystian Dziala";
    return 0;
}
//test