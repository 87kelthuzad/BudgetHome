#include "interface.h"
#include "budget.h"
#include <iostream>
#include <ctype.h>
#include <time.h>

Interface::Interface() {}
Interface::~Interface() {}

void Interface::show() {
    std::cout << "====================================================" << std::endl;
    std::cout << "==== Wybierz jedna z opcji ktora Cie interesuje ====" << std::endl;
    std::cout << "================1)Platnosc gotowka: ================" << std::endl;
    std::cout << "=================2)Platnosc karta: =================" << std::endl;
    std::cout << "===============3)Wplata na budrzetu: ===============" << std::endl;
    std::cout << "========4)Pokaz dostepne sierodki z budzetu: =======" << std::endl;
    std::cout << "==5)Pokaz wszystkie transakcje z danego miesiaca: ==" << std::endl;
    std::cout << "====================================================" << std::endl;
}

void Interface::showMenuWhoPayCard() {
    std::cout << "====================================================" << std::endl;
    std::cout << "============= Czyja karta bylo placone =============" << std::endl;
    std::cout << "===================== 1)Mateusz: ===================" << std::endl;
    std::cout << "===================== 2)Justyna: ===================" << std::endl;
    std::cout << "====================================================" << std::endl;
}

