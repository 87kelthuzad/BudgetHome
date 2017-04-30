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
    double whoMuchSpentMoney;
    std::string whereSpentMoney;
public:
    Transaction();
//    Transaction() :whoMuchSpentMoney(0), whereSpentMoney(NULL) {}
//    Transaction(double whoMuchSpentMoney, std::string whereSpentMoney);
    ~Transaction();
    void PayCash(Budget &budget);

    void setWhereSpentMoney() noexcept;
    void setWhoMuchSpentMoney(Budget &budget) noexcept ;

    inline std::string getWhereSpentMoney() {return whereSpentMoney;}
    inline int getWhoMuchSpentMoney() {return  whoMuchSpentMoney*100;}
};

#endif // TRANSACTION_H
