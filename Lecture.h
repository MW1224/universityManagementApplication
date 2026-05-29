// Lecture information (title, content, date added)
#ifndef LECTURE_H
#define LECTURE_H

#include <iostream>
#include <string>

#include "DateTime.h"

using namespace std;

class Lecture {

    public:
        Lecture(const string& title, const string& content, const DateTime& date);
        Lecture(const Lecture& l);
        string getTitle() const;
        bool lessThan(const Lecture& lecture) const;
        void print() const;
        void play() const;
        
    private:
        string title;
        string content;
        DateTime dateTime;  // indicates when the Lecture was uploaded to the Brightplace Course

};

#endif
