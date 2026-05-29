// Date and time information
#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>

#include "Date.h"

using namespace std;

class DateTime {

    public:
        DateTime();
        DateTime(const Date&);

        bool lessThan(const DateTime& date) const;
        void print() const;

    private:
        int day;
        int month;
        int year;
        int hour;
        int minute;
        int second;
 
};

#endif
