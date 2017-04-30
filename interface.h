#ifndef INTERFACE_H
#define INTERFACE_H
#include <time.h>
#include "budget.h"

class Interface
{
private:
    char choice;
    int aa;
public:
    Interface();
    ~Interface();
    int optionMenu();
    void show();
    void DrawMenu();
};

#endif // INTERFACE_H
