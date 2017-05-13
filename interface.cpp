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
    setChanceMenuWhoPayCard();
}

void Interface::setChanceMenuWhoPayCard() noexcept {
    while (true) {
        try {
            std::cout << "Podaj wlasciwa opcje" << std::endl;
            getline(std::cin , whatMenuWhoPayCardString);
            if (whatMenuWhoPayCardString.empty()) {
                throw badWhatMenuOptionIsEmpty();
            }
            if (isalpha(whatMenuWhoPayCardString[0])) {
                throw badWhatMenuOptionIsAlpha();
            }
            if (isspace(whatMenuWhoPayCardString[0])) {
                throw badWhatMenuOptionIsWhiteSpace();
            }
            if (ispunct(whatMenuWhoPayCardString[0])) {
                throw  badWhatMenuOptionIsPunctuationMarks();
            }
            if (whatMenuWhoPayCardString[0] < '1') {
                throw badWhatMenuOptionTooSmall();
            }
            if (whatMenuWhoPayCardString[0] > '2') {
                throw badWhatMenuOptionTooBig();
            }
            if (whatMenuWhoPayCardString[0] >= '1' && whatMenuWhoPayCardString[0] <= '2') {
                whatMenuWhoPayCard = std::stoi(whatMenuWhoPayCardString.c_str());
                std::cout << whatMenuWhoPayCard << std::endl;
            }
            if (whatMenuWhoPayCardString[1]) {
                throw badWhatMenuOption();
            }
            break;
        }
        catch (badWhatMenuOptionIsEmpty &ref) {
            ref.message();
        }
        catch (badWhatMenuOptionTooSmall &ref) {
            ref.message();
        }
        catch (badWhatMenuOptionTooBig &ref) {
            ref.message();
        }
        catch (badWhatMenuOptionIsAlpha &ref) {
            ref.message();
        }
        catch (badWhatMenuOptionIsWhiteSpace &ref) {
            ref.message();
        }
        catch (badWhatMenuOptionIsPunctuationMarks &ref) {
            ref.message();
        }
        catch (badWhatMenuOption &ref) {
            ref.message();
        }
    }
}
