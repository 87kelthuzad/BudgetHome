#include "transaction.h"
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
//    std::cout << getWhereSpentMoney() + "d" << std::endl; wyjaśnienia czemu jak tak zrobię to w innej klasie mam tylko sklep a nie skelpd
    std::cout << "Ile zostalow wydanych pieniedzy: " << std::endl;
    setWhoMuchSpentMoney(budget);
    std::cout << getWhoMuchSpentMoney() << std::endl;
//    budget.setBudgetStart(budget.getBudgetStart() - getWhoMuchSpentMoney());

//    std::cin >> spend;
//    budget = budget - spend*100;
//    t += std::to_string(spend) + " ";
    //wyświetlenie budrzetu w formie 000.00
//    ss.setf(std::ios_base::fixed);
//    ss.precision(2);
//    ss << budget*0.01;
//    t += ss.str();
//    std::cout << t << std::endl;
//    return t;
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

void Transaction::setWhoMuchSpentMoney(Budget &budget) noexcept {
    while (true) {
        try {
//            std::cin.ignore();
            std::cin >> whoMuchSpentMoney;
            if (whoMuchSpentMoney <= 0) {
                throw badWhoMuchSpentMoneyTooSmall();
//                continue;
            }
            if ((whoMuchSpentMoney*100) > budget.getBudget()) {
                throw badWhoMuchSpentMoneyIsGreaterThanBudget();
//                continue;
            }
            break;
        }
        catch (badWhoMuchSpentMoneyTooSmall &ref) {
            ref.message();
        }
        catch (badWhoMuchSpentMoneyIsGreaterThanBudget &ref) {
            ref.message();
        }
    }
}
