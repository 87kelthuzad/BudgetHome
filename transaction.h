#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
//#include <fstream>
#include <string>
//#include <time.h>
//#include <ctime>
#include "budget.h"
#include "exception.h"
class Budget;

class Transaction
{
private:
//    int index;
    bool test = false;
    int indexStep = 0;
    int loopCount = 0;

    double whoMuchSpentMoney;
    std::string whereSpentMoney;
    std::string whoMuchSpentMoneyString;
public:
    Transaction();
    ~Transaction();
    void payCash(Budget &budget);
    void payCard(Budget &budget , Transaction &transaction);

    void setWhereSpentMoney() noexcept;
    void setWhoMuchSpentMoney(Budget &budget) noexcept ;

    inline std::string getWhereSpentMoney() {return whereSpentMoney;}
    inline int getWhoMuchSpentMoney() {return  whoMuchSpentMoney;}
};

#endif // TRANSACTION_H
