#include "DateTime.h"

// default constructor
DateTime::DateTime() {
    day = 0;
    month = 0;
    year = 2025;
    hour = 0;
    minute = 0;
    second = 0;
}

// conversion constructor
DateTime::DateTime(const Date& d) {
    day = d.getDay();
    month = d.getMonth();
    year = d.getYear();
    hour = 1;
    minute = 1;
    second = 1;
}

bool DateTime::lessThan(const DateTime& date) const {
    if (year == date.year && month == date.month && day == date.day && hour == date.hour && minute == date.minute) {
        return second < date.second;
    } else if (year == date.year && month == date.month && day == date.day && hour == date.hour) {
        return minute < date.minute;
    } else if (year == date.year && month == date.month && day == date.day) {
        return hour < date.hour;
    } else if (year == date.year && month == date.month) {
        return day < date.day;
    } else if (year == date.year) {
        return month < date.month;
    } else {
        return year < date.year;
    }
}

void DateTime::print() const {
    const string MONTHS[12] = {"January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
        cout << MONTHS[month-1] << " " << day << ", " << year << ", ";
    
    if (hour < 10) {
        cout << "0";
    }
    cout << hour << ": ";

    if (minute < 10) {
        cout << "0";
    }
    cout<< minute << ": ";

    if (second < 10) {
        cout << "0";
    }
    cout << second << endl;
}
