#include "budget.h"
#include "exception.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <time.h>

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
//    budget = std::stoi(budgetString.c_str())*100;
    bool test = false;
    int indexStep = 0;
    int loopCount = 0;
    while (true) {
        try {
            std::cout << "MMMM" << std::endl;
            std::cout << budgetString << std::endl;
            for (int j = 0 ; j < budgetString.size() ; ++j) {
                std::cout << "Ddd" << std::endl;
                ++loopCount;
                if (budgetString[j] == '.') {
                    std::cout << "lopcount po ." << loopCount << std::endl;
                    indexStep = j;
                    ++index;
                    loopCount = 0;
                }
            }
                for (int i = 0 ; i < budgetString.size() ; ++i) {
                    std::cout << budgetString[i] << "index" << i << std::endl;
                    std::cout << "index" << index << std::endl;
                    std::cout << "lopcounssssssssssssssssssssssssssSS" << std::endl;
                    std::cout << "lopcount" << loopCount << std::endl;
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
                    else if (budgetString[0] == '-' && test == false) {
                        test = true;
                        throw badBudgetStringIsNegativeNumber();
                    }
                    else if (isalpha(budgetString[i]) && test == false) {
//                        testFirstIf = true;
                        test = true;
                        throw badBudgetStringIsLetter();
                    }
                    else if (ispunct(budgetString[i]) && indexStep != i && test == false) {
//                        testFirstIf = true;
                        test = true;
                        throw  badBudgetStringIsPunctuationMarks();
                    }
                    else if (isspace(budgetString[i]) && test == false) {
//                        testFirstIf = true;
                        test = true;
                        throw badBudgetStringIsWhiteSpace();
                    }
                    std::cout << "yyyyyyyyyyyyyyyy" << std::endl;
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

//void Budget::setBudgetStartWithFile(std::string budget) {
//        while (true) {
//            try {
//                int loopCount = 0;
//                std::cout << budget << std::endl;
//                for (auto i = 0 ; i < budget.size() ; ++i) {
//                    std::cout << "dddsd" << i << std::endl;
//                    if (isalpha(budget[i])) {
////                        std::cin >> budgetStart;
////                        loopCount = 1;
//                        throw badBudgetStartIsLetter();
////                        continue;
//                    }
//                    else if (ispunct(budget[i]) && budget[i] != '.') {
//                        throw badBudgetStartIsPunctuationMarks();
////                        continue;
//                    }
//                    if (isspace(budget[i])) {
////                        std::cin >> budgetStart;
////                        loopCount = 1;
//                        throw  badBudgetStartIsWhiteSpace();
////                        continue;
//                    }
//                }
//                for (int i = budget.size()-1 ; i >= 0  ; --i) {
//                    ++index;
//                    if (ispunct(budget[i])) {
//                        if (index > 3) {
////                            loopCount = 1;
//                            throw badBudgetStartPlaceDot();
////                            continue;
//                        }
//                        break;
//                    }
//                    break;
//                }
//                std::cout << "dd" << loopCount << std::endl;
//                if (loopCount == 1){
//                    std::cin >> budget;
//                    continue;
//                }
//                else if (loopCount == 0) {
////                    budgetStart =
//                    break;
//                }
////                std::cout <<  "index "<<index << std::endl;
////                break;
//            }
//            catch (badBudgetStartIsLetter &ref) {
//                ref.message();
//                continue;
//            }
//            catch (badBudgetStartIsWhiteSpace &ref) {
//                ref.message();
//                continue;
//            }
//            catch (badBudgetStartIsPunctuationMarks &ref) {
//                ref.message();
//                continue;
//            }
//            catch (badBudgetStartPlaceDot &ref) {
//                ref.message();
//                continue;
//            }
//        }
//}

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
    myFileHistory.open( getNameHistoryFile(localTime) , std::ios::out);
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
