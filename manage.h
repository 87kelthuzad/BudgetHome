#ifndef MANAGE_H
#define MANAGE_H
#include "interface.h"
#include "transaction.h"
#include "localtime.h"


class Interface;
class Budget;
class Transaction;
class LocalTime;

class Manage
{
    private:
        Interface ui;
        Budget budget;
        Transaction transaction;
        LocalTime localTime;
        int whatMenuOption = 0;
        std::string whatMenuOptionString;
    public:
        Manage();
        ~Manage();
        void mainLoop();
        void setWhatMenuOption() noexcept;
        inline int getWhatMenuOption() {return  whatMenuOption;}
};

#endif // MANAGE_H
