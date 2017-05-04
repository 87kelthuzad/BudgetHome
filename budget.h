#ifndef BUDGET_H
#define BUDGET_H
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <sstream>
#include "transaction.h"
#include "localtime.h"


class LocalTime;
class Transaction;

class Budget
{
private:

    LocalTime localTime;

    bool test = false;

    int index = 0;
    int budget = 0;
    int indexStep = 0;
    int loopCount = 0;

    double helpSpentMoney = 0.0;
    double helpBudget = 0.0;

    double fractionPart = 0.0;
    double integerPart = 0.0;

    std::fstream myFileBudget;
    std::fstream myFileHistory;

    std::string budgetString;
    std::string nameBudgetFile;
    std::string nameHistoryFile;
    std::string saveRecordTransaction;
    std::string helpStringBudget;
    std::string helpStringWhoMuchSpenytMoney;
    std::stringstream setPrecision;
public:
    Budget();
    ~Budget();

    void openFileWithBudget();
    void createFileOnBudget();
    void convertBudgetStringToInt() noexcept;
    void SplitIntoIntegerAndFractionParts(Transaction &transaction);
    void changeBudget(Transaction &transaction);
    void openFileHistory();
    void drawHeadlines();
    void saveTransactionToFileHistory(Transaction &transaction , LocalTime &localTime);

    inline int getBudget() {return  budget;}
    inline std::string getNameBudgetFile(LocalTime &localTime) {return nameBudgetFile = "budgetM:" + localTime.getTimeMonth();}
    inline std::string getNameHistoryFile(LocalTime &localTime) {
        return nameHistoryFile = "historyY:" + localTime.getTimeYear() + "M:" + localTime.getTimeMonth();}

};

#endif // BUDGET_H
