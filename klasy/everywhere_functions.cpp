#include "everywhere_functions.h"
#include <cmath>
float stringtoint(std::string snum){
    float liczba = 0;
    for(int i = 0; i<snum.length();i++){
        liczba += float(snum[i] - '0') * pow(10,snum.length()-i-1);
    }
    return liczba;
}

float stringtoint_zz(std::string lancuch){
    try {
        size_t pozycjaPrzecinka = lancuch.find('.');
        if (pozycjaPrzecinka != std::string::npos) {
            std::string czescCalkowita = lancuch.substr(0, pozycjaPrzecinka);
            std::string czescUlamkowa = lancuch.substr(pozycjaPrzecinka + 1, 2);  // Dwa miejsca po przecinku

            int calkowita = std::stoi(czescCalkowita);
            int ulamkowa = std::stoi(czescUlamkowa);

            double wynik = calkowita + ulamkowa / 100.0;
            return wynik;
        } else {
            return std::stod(lancuch);
        }
    } catch (const std::invalid_argument& e) {
        std::cerr << "Blad konwersji: " << e.what() << std::endl;
        return 0.0;
    }
}

std::string inttostring(int num){
    std::string snum;
    while(num > 0){
        snum = char((num%10) + 48) + snum;
        num = floor(num/10);
    }
    return snum;
}

std::string inttostring_zz(float numc){
    std::string snum;
    int num = numc*100;
    while(num > 0){
        snum = char((num%10) + 48) + snum;
        if(snum.length() == 2) snum = "." + snum;
        num = floor(num/10);
    }
    return snum;
}