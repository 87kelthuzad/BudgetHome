#ifndef INTERFACE_H
#define INTERFACE_H
#include <iostream>
#include <string>
#include "budget.h"
#include "exception.h"

class Interface
{
private:
    std::string whatMenuWhoPayCardString;
    int whatMenuWhoPayCard;
public:
    Interface();
    ~Interface();
    void show();
    void showMenuWhoPayCard();
    void setChanceMenuWhoPayCard() noexcept;
    inline int getChanceMenuWhoPayCard() {return whatMenuWhoPayCard; }
};

#endif // INTERFACE_H
