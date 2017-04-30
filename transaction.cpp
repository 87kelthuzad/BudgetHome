#include "transaction.h"
#include "exception.h"
#include <iostream>
//#include <fstream>
#include <string>
//#include <time.h>
//#include <ctime>
//#include <iomanip>
//#include <sstream>

Transaction::Transaction() {}
Transaction::~Transaction() {}

void Transaction::PayCash(Budget &budget) {
    std::cout << budget.getBudget() << std::endl;
    std::cout << "Gdzie zostaly wydane pieniadze: " << std::endl;
    std::cout << "Sklep , Rynek , Inne" << std::endl;
    setWhereSpentMoney();
    std::cout << getWhereSpentMoney() << std::endl;
    std::cout << "Ile zostalow wydanych pieniedzy: " << std::endl;
    getline(std::cin , whoMuchSpentMoneyString);
    whoMuchSpentMoney = std::stod(whoMuchSpentMoneyString.c_str());
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
            else if (whereSpentMoney == "rynek" || whereSpentMoney == "Rynek"
                || whereSpentMoney == "sklep" || whereSpentMoney == "Sklep"
                || whereSpentMoney == "inne" || whereSpentMoney == "Inne") {

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
//do sprawdzenia wywala bład jak podam wartosc np. s333.55
void Transaction::setWhoMuchSpentMoney(Budget &budget) noexcept {
    bool test = false;
    int indexStep = 0;
    int loopCount = 0;
//    int index = 0;
    while (true) {
        try {
            for (int i = 0 ; i < whoMuchSpentMoneyString.size() ; ++i) {
                ++loopCount;
                if (whoMuchSpentMoneyString[i] == '.') {
                    indexStep = i;
                    ++index;
                    loopCount = 0;
                }
            }
            for (int j = 0; j < whoMuchSpentMoneyString[j] ; ++j) {
                if (test == true) {
                    test = false;
                    indexStep = 0;
                    loopCount = 0;
                    std::cout << "Podaj ile wydales pieniedzy: " << std::endl;
                    getline(std::cin, whoMuchSpentMoneyString);
                    whoMuchSpentMoney = std::stod(whoMuchSpentMoneyString.c_str())*100;
                    continue;
                }
                else if (loopCount > 2 && index == 1 && test == false) {
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
                else if ((whoMuchSpentMoney <= 0) && test == false) {
                    test = true;
                    throw badWhoMuchSpentMoneyTooSmall();
                }
                else if (((whoMuchSpentMoney) > budget.getBudget()) && test == false) {
                    test = true;
                    throw badWhoMuchSpentMoneyIsGreaterThanBudget();
                }
            }
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
