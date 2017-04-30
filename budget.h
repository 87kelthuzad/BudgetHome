#ifndef BUDGET_H
#define BUDGET_H
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include "transaction.h"
#include "localtime.h"

class LocalTime;
class Transaction;

class Budget
{
private:

    LocalTime localTime;

//    int loopCount = 0;
    int index = 0;
    int budget = 0;
//    bool test = false;
//    bool testFirstIf = false;
//    int indexStep = 0;
//    int loopCount = 0;

    std::fstream myFileBudget;
    std::fstream myFileHistory;

    std::string budgetString;
    std::string nameBudgetFile;
    std::string nameHistoryFile;
public:
    Budget();
    ~Budget();

    void openFileWithBudget();
    void createFileOnBudget();
    void convertBudgetStringToInt();
    void changeBudget(Transaction &transaction);
    void openFileHistory();
    void drawHeadlines();

//    void saveRecordToHistory(std::string record);
//    void setBudgetStartWithFile(std::string budgetStart);

    inline int getBudget() {return  budget;}
    inline std::string getNameBudgetFile(LocalTime &localTime) {return nameBudgetFile = "budgetM:" + localTime.getTimeMonth();}
    inline std::string getNameHistoryFile(LocalTime &localTime) {
        return nameHistoryFile = "historyY:" + localTime.getTimeYear() + "M:" + localTime.getTimeMonth();}

};

#endif // BUDGET_H
