#include "localtime.h"
#include <iostream>
#include <ctime>

LocalTime::LocalTime() {
    timeL+= std::to_string  (1900 + ltm->tm_year)   + "/" +
            std::to_string  (1 + ltm->tm_mon)       + "/" +
            std::to_string  (ltm->tm_mday)          + " " +
            std::to_string  (1 + ltm->tm_hour)      + ":" +
            std::to_string  (1 + ltm->tm_min) ;
}
LocalTime::~LocalTime() {}
