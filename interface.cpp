#include "interface.h"
#include "budget.h"
#include <iostream>
#include <ctype.h>
#include <time.h>

Interface::Interface() {}
Interface::~Interface() {}
int Interface::optionMenu() {
    while (true) {
        std::cin >> choice;
        int aa = std::atoi(&choice);
        if ( aa < 1 || aa > 5 || isalpha(choice) ){
            std::cerr << "Nie wlasciwy przedzial" << std::endl;
        }
        else {
            return aa;
        }
    }
}

void Interface::show() {
    std::cout << "====================================================" << std::endl;
    std::cout << "=====Wybierz jedna z opcji ktora Cie interesuje=====" << std::endl;
    std::cout << "================1)Platnosc gotowka: ================" << std::endl;
    std::cout << "=================2)Platnosc karta: =================" << std::endl;
    std::cout << "===============3)Wplata na budrzetu: ===============" << std::endl;
    std::cout << "========4)Pokaz dostepne sierodki z budzetu: =======" << std::endl;
    std::cout << "==5)Pokaz wszystkie transakcje z danego miesiaca: ==" << std::endl;
    std::cout << "====================================================" << std::endl;
}

void Interface::DrawMenu() {

}
