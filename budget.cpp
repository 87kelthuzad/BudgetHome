#include "budget.h"
#include "exception.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <time.h>
#include <iomanip>
#include <math.h>

Budget::Budget() {}
Budget::~Budget() {}

void Budget::openFileWithBudget() {
    std::cout << getNameBudgetFile(localTime) << std::endl;
        myFileBudget.open(getNameBudgetFile(localTime), std::ios::in);
        if (myFileBudget.is_open()) {
            myFileBudget.seekg(0 , std::ios::end);
            if (myFileBudget.tellg() == 0) {
                std::cout << "Podaj budzet" << std::endl;
                std::getline(std::cin, budgetString);
            }
            else {
                myFileBudget.seekg(0, std::ios::beg);
                std::getline(std::cin,budgetString);
            }
        }
        else {
            myFileBudget.close();
            createFileOnBudget();
        }
}

void Budget::createFileOnBudget() {
    std::cout << getNameBudgetFile(localTime) << std::endl;
    myFileBudget.open(getNameBudgetFile(localTime) , std::ios::out);
    std::cout << "Podaj budzet" << std::endl;
    std::getline(std::cin, budgetString);
    myFileBudget.close();
}

void Budget::convertBudgetStringToInt() noexcept{
    while (true) {
        try {
            indexStep = 0;
            for (int j = 0 ; j < budgetString.size() ; ++j) {
                ++loopCount;
                if (budgetString[j] == '.') {
                    indexStep = j;
                    loopCount = 0;
                }
            }
            if (indexStep == 0) {
                indexStep = 100;
            }
            if (test == true) {
                loopCount = 0;
                test = false;
                std::cout << "Podaj budzet: " << std::endl;
                getline(std::cin, budgetString);
                continue;
            }
            for (int i = 0 ; i < budgetString.size() ; ++i) {
                std::cout << "indexx " << i << std::endl;
                std::cout << "loopC " << loopCount << std::endl;
                if (loopCount > 2 && loopCount != budgetString.size() && test == false) {
                    test = true;
                    throw badBudgetStringPlaceDot();
                }
                else if (budgetString[i] == '-' && i == 0 && test == false) {
                    test = true;
                    throw badBudgetStringIsNegativeNumber();
                }
                else if (isalpha(budgetString[i]) && test == false) {
                    test = true;
                    throw badBudgetStringIsLetter();
                }
                else if (ispunct(budgetString[i]) && i != indexStep && test == false) {
                    test = true;
                    throw  badBudgetStringIsPunctuationMarks();
                }
                else if (isspace(budgetString[i]) && test == false) {
                    test = true;
                    throw badBudgetStringIsWhiteSpace();
                }
            }
            budget = std::stoi(budgetString.c_str())*100;
            break;
        }
        catch (badBudgetStringPlaceDot &ref) {
            ref.message();
        }
        catch (badBudgetStringIsNegativeNumber &ref) {
            ref.message();
        }
        catch (badBudgetStringIsLetter &ref) {
            ref.message();
        }
        catch (badBudgetStringIsPunctuationMarks &ref) {
            ref.message();
        }
        catch (badBudgetStringIsWhiteSpace &ref) {
            ref.message();
        }
    }
}

void Budget::changeBudget(Transaction &transaction) {
    budget = budget - transaction.getWhoMuchSpentMoney();
}

void Budget::openFileHistory() {
    myFileHistory.open( getNameHistoryFile(localTime) , std::ios::app);
    myFileHistory.seekg(0 , std::ios::end);
    if (myFileHistory.tellg() == 0) {
        drawHeadlines();
    }
}

void Budget::drawHeadlines() {
    myFileHistory << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
    myFileHistory << "+                    +              +              +              +" << std::endl;
    myFileHistory << "+    DATA Y:M:D      + GDZIE_WYDANE +      ILE     +     BUDZET   +" << std::endl;
    myFileHistory << "+                    +              +              +              +" << std::endl;
    myFileHistory << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
}

void Budget::saveTransactionToFileHistory(Transaction &transaction , LocalTime &localTime) {
    setPrecision.str(std::string());
    setPrecision.clear();

    helpSpentMoney = transaction.getWhoMuchSpentMoney();
    helpSpentMoney *= 0.01;
    setPrecision << std::fixed << std::setprecision(2) << helpSpentMoney;
    helpStringWhoMuchSpenytMoney = setPrecision.str();

    setPrecision.str(std::string());
    setPrecision.clear();

    helpBudget = getBudget();
    helpBudget *= 0.01;
    setPrecision << std::fixed << std::setprecision(2) << helpBudget;
    helpStringBudget = setPrecision.str();

    myFileHistory << "   " << localTime.getTime() + "         " << transaction.getWhereSpentMoney() <<
                     "           " << helpStringWhoMuchSpenytMoney << "          " << helpStringBudget << std::endl;
}

void Budget::SplitIntoIntegerAndFractionParts(Transaction &transaction) {
    fractionPart = modf( transaction.getWhoMuchSpentMoney() , &integerPart);
    std::cout << "FFF:" << fractionPart << std::endl;
    std::cout << "III:" << integerPart << std::endl;
}
