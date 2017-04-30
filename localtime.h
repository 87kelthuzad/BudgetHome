#ifndef LOCALTIME_H
#define LOCALTIME_H
#include <ctime>
#include <string>


class LocalTime
{
private:
    time_t now = time(0);
    tm *ltm = localtime(&now);
    std::string timeL;
    std::string timeYear;
    std::string timeMonth;
    std::string timeDay;
public:
    LocalTime();
    ~LocalTime ();
    inline std::string getTime() {return timeL;}
    inline std::string getTimeYear() {return  timeYear = std::to_string(1900 + ltm->tm_year);}
    inline std::string getTimeMonth() {return  timeMonth = std::to_string(1 + ltm->tm_mon);}
    inline std::string getTimeDay() {return timeDay = std::to_string(ltm->tm_mday);}
};

#endif // LOCALTIME_H
