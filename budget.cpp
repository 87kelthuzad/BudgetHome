#include "budget.h"
#include "exception.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <time.h>
#include <iomanip>

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

void Budget::convertBudgetStringToInt() {
    bool test = false;
    int indexStep = 0;
    int loopCount = 0;
    while (true) {
        try {
            for (int j = 0 ; j < budgetString.size() ; ++j) {
                ++loopCount;
                if (budgetString[j] == '.') {
                    indexStep = j;
                    ++index;
                    loopCount = 0;
                }
            }
                for (int i = 0 ; i < budgetString.size() ; ++i) {
                    if (test == true) {
                        test = false;
                        indexStep = 0;
                        loopCount = 0;
                        std::cout << "Podaj budzet: " << std::endl;
                        getline(std::cin, budgetString);
                        continue;
                    }
                    else if (loopCount > 2 && index == 1 && test == false) {
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


/*void Budget::saveRecordToHistory(std::string record) {
    std::fstream myFileHis;
    std::string name;
    myFileHis.open(name, std::ios::out | std::ios::app);
    std::cout << record << std::endl;
    index = 0;
    while (index != 1) {
    if (myFileHis.is_open()) {
        if (myFileHis.tellp() == 0) {
            myFileHis << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
            myFileHis << "+                    +              +              +              +" << std::endl;
            myFileHis << "+    DATA Y:M:D      + GDZIE_WYDANE +      ILE     +     BUDZET   +" << std::endl;
            myFileHis << "+                    +              +              +              +" << std::endl;
            myFileHis << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << std::endl;
        }
        else {
            myFileHis.seekp(0,std::ios::end);
            myFileHis << "+            +         +         +         +" << std::endl;
            for (int i = 0; i < 45 ; ++i) {
                if (i == 0)
                    myFileHis << "+";
                else if (i == 2) {
//                    myFileHis << std::to_string(year);
                    myFileHis << "/";
//                    myFileHis << std::to_string(month);
                    myFileHis << "/";
//                    myFileHis << std::to_string(day);
                    i = i + 9;
                }
                else if (i == 14) {
                    myFileHis << "+";
                }
                else if (i == 17) {
                    for (int j = 8 ; j < record.size() ; ++j) {
                        char k;
                        k = record[j];
                        if (isalpha(k)) {
                            std::cout << "dd" << std::endl;
                            std::cout << record[j] << std::endl;
                            myFileHis << k;
                            ++i;
                            std::cout << i << std::endl;
                        }
                    }
                }
                else if (i == 25) {
                    myFileHis << "+";
                }
                else if (i == 28) {
                    for (int j = 17 ; j < record.size() ; ++j) {
                        char gg;
                        gg = record[j];
                        if(isdigit(gg)){
                            std::cout << "stsdsdsa" << std::endl;
                            myFileHis << gg;
                            ++i;
                        }
                        else {
                            break;
                        }
                    }
                    myFileHis << ".00";
                }
                else if (i == 33) {
                    myFileHis << "+";
                }
                else if (i == 36) {
                    std::cout << "555555" << std::endl;
                    for (int j = 19 ; j < record.size() ; ++j) {
                        char gg;
                        gg = record[j];
                        if(isdigit(gg) || gg == '.'){
                            std::cout << "stsdsdsa" << std::endl;
                            myFileHis << gg;
                            ++i;
                        }
//                        else {
//                            break;
//                        }
                    }
                }
                else if (i == 44) {
                    myFileHis << "+" << std::endl;
                }
                else
                    myFileHis << " ";
            }
            index = 1;
        }
    }
    }
}
*/
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

    helpSpentMoney = transaction.getWhoMuchSpentMoney();
    helpSpentMoney *= 0.01;
    setPrecisionSpentMoney << std::fixed << std::setprecision(2) << helpSpentMoney;
    helpStringWhoMuchSpenytMoney = setPrecisionSpentMoney.str();

    myFileHistory << "   " << localTime.getTime() + "         " << transaction.getWhereSpentMoney() <<
                     "           " << helpStringWhoMuchSpenytMoney << "          " << getBudget() << std::endl;

    //clear setPrecisionSpentMoney
//    setPrecisionSpentMoney.str(std::string() );
//    setPrecisionSpentMoney.clear();

//    helpString = transaction.getWhereSpentMoney();


//    std::cout << helpSpentMoney << " D" << std::endl;
//    saveRecordTransaction = "+  " + localTime.getTime() + "   +";
//    if (helpString.size() > 4) {
//        std::cout << "wiecej" << std::endl;
//        saveRecordTransaction += "    " + transaction.getWhereSpentMoney() + "     +";
//    }
//    else {
//        std::cout << "mniej" << std::endl;
//        saveRecordTransaction += "    " + transaction.getWhereSpentMoney() + "      +";
//    }
//    if (helpSpentMoney > 0) {
//        saveRecordTransaction += "   " + helpStringWhoMuchSpenytMoney;
//        saveRecordTransaction += "       +";
//    }
//    else if (helpSpentMoney > 10) {
//        saveRecordTransaction += "   " + helpStringWhoMuchSpenytMoney;
//        saveRecordTransaction += "    +";
//    }
//    else if (helpSpentMoney > 100) {
//        saveRecordTransaction += "   " + helpStringWhoMuchSpenytMoney;
//        saveRecordTransaction += "   +";
//    }
//    else if (helpSpentMoney > 1000) {
//        saveRecordTransaction += "   " + helpStringWhoMuchSpenytMoney;
//    }
//    setPrecisionSpentMoney.clear();
//    myFileHistory << saveRecordTransaction << std::endl;
//    for (int i = 0 ; i < 69 ; ++i) {
//        if ( i == 0 || i == 8 || i == 24 || i == 49) {
//            myFileHistory << '+';
//            ++i;
//        }
//        else if (i == 3 ) {
//            myFileHistory << localTime.getTime();
////            i += 9;
//        }
//        else if (i == 14) {
//            myFileHistory << transaction.getWhereSpentMoney();
//            i += 9;
////            ++i;
//        }
//        else if (i == 39) {
//            myFileHistory << transaction.getWhoMuchSpentMoney();
////            i += 6;
//        }
//        else if (i == 56) {
//            myFileHistory << getBudget();
////            i += 7;
//        }
//        else if (i == 68) {
//            myFileHistory << '+' << std::endl;
////            ++i;
//        }
//        else {
//            myFileHistory << ' ';
////            ++i;
//        }
//    }
}
