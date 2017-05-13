#include "transaction.h"
#include "exception.h"
//#include "budget.h"
#include <iostream>
//#include <fstream>
#include <string>
//#include <time.h>
//#include <ctime>
//#include <iomanip>
//#include <sstream>

Transaction::Transaction() {}
Transaction::~Transaction() {}

void Transaction::payCash(Budget &budget) {
    std::cout << budget.getBudget() << std::endl;
    std::cout << "Gdzie zostaly wydane pieniadze: " << std::endl;
    std::cout << "Sklep , Rynek , Inne" << std::endl;
    setWhereSpentMoney();
    std::cout << getWhereSpentMoney() << std::endl;
    std::cout << "Ile zostalow wydanych pieniedzy: " << std::endl;
    getline(std::cin , whoMuchSpentMoneyString);
    setWhoMuchSpentMoney(budget);
    std::cout << getWhoMuchSpentMoney() << std::endl;
}

void Transaction::setWhereSpentMoney() noexcept {
    while (true) {
        try {
            std::cin.clear();
            getline(std::cin , whereSpentMoney);
            if (whereSpentMoney.size() == 0) {
                throw badWhereSpentMoneyIsEmpty();
            }
            else if (whereSpentMoney    == "rynek"      || whereSpentMoney == "Rynek"
                    || whereSpentMoney  == "sklep"      || whereSpentMoney == "Sklep"
                    || whereSpentMoney  == "inne"       || whereSpentMoney == "Inne"
                    || whereSpentMoney  == "allegro"    || whereSpentMoney == "Allegro") {
            }
            else {
                throw badWhereSpentMoney();
            }
            break;
        }
        catch (badWhereSpentMoneyIsEmpty &ref) {
            ref.message();
        }
        catch (badWhereSpentMoney &ref) {
            ref.message();
        }
    }
}

void Transaction::setWhoMuchSpentMoney(Budget &budget) noexcept {
    while (true) {
        try {
            indexStep = 0;
            for (int i = 0 ; i < whoMuchSpentMoneyString.size() ; ++i) {
                ++loopCount;
                if (whoMuchSpentMoneyString[i] == '.') {
                    indexStep = i;
                    loopCount = 0;
                }
            }
            if (indexStep == 0) {
                indexStep = 100; // by indexStep napewno znajdowała sie poza zakresem
            }
            if (test == true) {
                loopCount = 0;
                test = false;
                std::cout << "Podaj ile wydales pieniedzy: " << std::endl;
                getline(std::cin, whoMuchSpentMoneyString);
                continue;
            }
            for (int j = 0; j < whoMuchSpentMoneyString[j] ; ++j) {
                if (loopCount > 2 && loopCount != whoMuchSpentMoneyString.size() && test == false) {
                    test = true;
                    throw badWhoMuchSpentMoneyStringPlaceDot();
                }
                else if (whoMuchSpentMoneyString[j] == '-' && j == 0 && test == false) {
                    test = true;
                    throw badWhoMuchSpentMoneyStringIsNegativeNumber();
                }
                else if (isalpha(whoMuchSpentMoneyString[j]) && test == false) {
                    test = true;
                    throw badWhoMuchSpentMoneyStringIsLetter();
                }
                else if (ispunct(whoMuchSpentMoneyString[j]) && j != indexStep && test == false) {
                    test = true;
                    throw badWhoMuchSpentMoneyStringIsPunctuationMarks();
                }
                else if (isspace(whoMuchSpentMoneyString[j]) && test == false) {
                    test = true;
                    throw badWhoMuchSpentMoneyStringIsWhiteSpace();
                }
                whoMuchSpentMoney = std::stod(whoMuchSpentMoneyString.c_str())*100;
                if ((whoMuchSpentMoney <= 0) && test == false) {
                    test = true;
                    throw badWhoMuchSpentMoneyTooSmall();
                }
                else if (((whoMuchSpentMoney) > budget.getBudget()) && test == false) {
                    test = true;
                    throw badWhoMuchSpentMoneyIsGreaterThanBudget();
                }
            }
            whoMuchSpentMoney = 0;
            whoMuchSpentMoney = std::stod(whoMuchSpentMoneyString.c_str())*100;
            break;
        }
        catch (badWhoMuchSpentMoneyStringPlaceDot &ref) {
            ref.message();
        }
        catch (badWhoMuchSpentMoneyStringIsNegativeNumber &ref) {
            ref.message();
        }
        catch (badWhoMuchSpentMoneyStringIsLetter &ref) {
            ref.message();
            continue;
        }
        catch (badWhoMuchSpentMoneyStringIsPunctuationMarks &ref) {
            ref.message();
        }
        catch (badWhoMuchSpentMoneyStringIsWhiteSpace &ref) {
            ref.message();
        }
        catch (badWhoMuchSpentMoneyTooSmall &ref) {
            ref.message();
        }
        catch (badWhoMuchSpentMoneyIsGreaterThanBudget &ref) {
            ref.message();
        }
    }
}

void Transaction::payCard(Budget &budget , Transaction &transaction, Interface &ui) {
    std::cout << budget.getBudget() << std::endl;
    std::cout << "Gdzie zostaly wydane pieniadze: " << std::endl;
    std::cout << "Sklep , Allegro , Inne" << std::endl;
    setWhereSpentMoney();
    std::cout << "Ile zostalow wydanych pieniedzy: " << std::endl;
    getline(std::cin , whoMuchSpentMoneyString);
    setWhoMuchSpentMoney(budget);
    ui.showMenuWhoPayCard();
    switch (ui.getChanceMenuWhoPayCard()) {
        case 1:
            std::cout << "budget" << budget.getBudget() << std::endl;
            budget.SplitIntoIntegerAndFractionParts(transaction);
            budget.verificationSmartSaver(transaction);
            budget.setSmartSaverMateusz();
            budget.changeBudgetAfterSmartSaver(transaction);
            std::cout << "budget" << budget.getBudget() << std::endl;
            break;
    }
}
