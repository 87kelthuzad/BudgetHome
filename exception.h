#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <iostream>
//sprawdza czy poprawna zostala wybran opcja z menu
class badWhatMenuOptionIsEmpty {
    public:
    void message() {
        std::cerr << "wartosc jest pusta" << std::endl;
    }
};

class badWhatMenuOptionTooSmall {
    public:
    void message() {
        std::cerr << "wartosc jest za mala" << std::endl;
    }
};

class badWhatMenuOptionTooBig {
    public:
    void message() {
        std::cerr << "wartosc jest za duza" << std::endl;
    }
};

class badWhatMenuOptionIsAlpha {
    public:
    void message() {
        std::cerr << "wartosc jest litera" << std::endl;
    }
};

class badWhatMenuOptionIsWhiteSpace {
    public:
    void message() {
        std::cerr << "wartosc jest bialym znakiem" << std::endl;
    }
};

class badWhatMenuOptionIsPunctuationMarks {
    public:
    void message() {
        std::cerr << "wartosc jest znakiem drukowalnym" << std::endl;    }
};

class badWhatMenuOption {
    public:
    void message() {
        std::cerr << "wartosc jest bledna" << std::endl;    }
};

//sprawdzam czy string gdzie wydalem pieniadze jest poprawny

class badWhereSpentMoneyIsEmpty {
    public:
    void message() {
        std::cerr << "wartosc jest pusta" << std::endl;
    }
};

class badWhereSpentMoney {
    public:
    void message() {
        std::cerr << "bledna wartosc" << std::endl;
    }
};

//sprawdzam ile wydalem pieniedzy

class badWhoMuchSpentMoneyStringIsLetter {
    public:
    void message() {
        std::cerr << "wartosc jest nie poprawna bo posiada litere" << std::endl;    }
};

class badWhoMuchSpentMoneyStringIsPunctuationMarks {
    public:
    void message() {
        std::cerr << "wartosc jest znakiem drukowalnym" << std::endl;    }
};

class badWhoMuchSpentMoneyStringIsWhiteSpace {
    public:
    void message() {
        std::cerr << "wartosc jest bialym znakiem" << std::endl;    }
};

class badWhoMuchSpentMoneyStringPlaceDot {
    public:
    void message() {
        std::cerr << "przecinke w niedpowiednim miejscu" << std::endl;
    }
};

class badWhoMuchSpentMoneyStringIsNegativeNumber {
    public:
    void message() {
        std::cerr << "liczba jest ujemna" << std::endl;
    }
};

class badWhoMuchSpentMoneyTooSmall {
    public:
    void message() {
        std::cerr << "wartosc jest za mala" << std::endl;
    }
};

class badWhoMuchSpentMoneyIsGreaterThanBudget {
    public:
    void message() {
        std::cerr << "wartosc jest wieksza od budzetu" << std::endl;
    }
};

//sprawdzanie budzetu pobranego z pliku

class badBudgetStringIsLetter {
    public:
    void message() {
        std::cerr << "wartosc jest nie poprawna bo posiada litere" << std::endl;    }
};

class badBudgetStringIsPunctuationMarks {
    public:
    void message() {
        std::cerr << "wartosc jest znakiem drukowalnym" << std::endl;    }
};

class badBudgetStringIsWhiteSpace {
    public:
    void message() {
        std::cerr << "wartosc jest bialym znakiem" << std::endl;    }
};

class badBudgetStringPlaceDot {
    public:
    void message() {
        std::cerr << "przecinke w niedpowiednim miejscu" << std::endl;
    }
};

class badBudgetStringIsNegativeNumber {
    public:
    void message() {
        std::cerr << "liczba jest ujemna" << std::endl;
    }
};

#endif // EXCEPTION_H
