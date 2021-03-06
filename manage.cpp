#include <iostream>
#include <string>
#include "manage.h"
#include "interface.h"
#include "exception.h"
#include "transaction.h"

Manage::Manage(){}
Manage::~Manage(){}

void Manage::mainLoop() {
    budget.openFileWithSmartSaver();
    budget.openFileWithBudget();
    budget.convertBudgetStringToInt();
    budget.openFileHistory();
    while (true) {
        ui.show();
        setWhatMenuOption();
        switch (getWhatMenuOption()) {
            case 1:
                transaction.payCash(budget);
                budget.changeBudget(transaction);
                budget.saveTransactionToFileHistory(transaction , localTime);
                break;
            case 2:
                transaction.payCard(budget , transaction , ui);
                budget.saveTransactionToFileHistory(transaction , localTime);
                break;
        }
    }
}

void Manage::setWhatMenuOption() noexcept {
    while (true) {
        try {
            getline(std::cin , whatMenuOptionString);
            if (whatMenuOptionString.empty()) {
                throw badWhatMenuOptionIsEmpty();
            }
            if (isalpha(whatMenuOptionString[0])) {
                throw badWhatMenuOptionIsAlpha();
            }
            if (isspace(whatMenuOptionString[0])) {
                throw badWhatMenuOptionIsWhiteSpace();
            }
            if (ispunct(whatMenuOptionString[0])) {
                throw  badWhatMenuOptionIsPunctuationMarks();
            }
            if (whatMenuOptionString[0] < '1') {
                throw badWhatMenuOptionTooSmall();
            }
            if (whatMenuOptionString[0] > '6') {
                throw badWhatMenuOptionTooBig();
            }
            if (whatMenuOptionString[0] >= '1' && whatMenuOptionString[0] <= '6') {
                whatMenuOption = std::stoi(whatMenuOptionString.c_str());
                std::cout << whatMenuOption << std::endl;
            }
            if (whatMenuOptionString[1]) {
                throw badWhatMenuOption();
            }
            break;
        }
        catch (badWhatMenuOptionIsEmpty &ref) {
            ref.message();
        }
        catch (badWhatMenuOptionTooSmall &ref) {
            ref.message();
        }
        catch (badWhatMenuOptionTooBig &ref) {
            ref.message();
        }
        catch (badWhatMenuOptionIsAlpha &ref) {
            ref.message();
        }
        catch (badWhatMenuOptionIsWhiteSpace &ref) {
            ref.message();
        }
        catch (badWhatMenuOptionIsPunctuationMarks &ref) {
            ref.message();
        }
        catch (badWhatMenuOption &ref) {
            ref.message();
        }
    }
}
