#include "Lecture.h"

Lecture::Lecture(const string& title, const string& content, const DateTime& date) {
    this->title = title;
    this->content = content;
    dateTime = date;
}

Lecture::Lecture(const Lecture& l) {
    this->title = l.title;
    this->content = l.content;
    this->dateTime = l.dateTime;
}

string Lecture::getTitle() const {
    return title;
}

// returns true if this Lecture's DateTime comes before d, false otherwise
bool Lecture::lessThan(const Lecture& lecture) const {
    return dateTime.lessThan(lecture.dateTime);
}

void Lecture::print() const {
    cout << "Lecture: " << title << "\nDate added: ";
    dateTime.print();
}

void Lecture::play() const {
    print();
    cout << "Content: " << content << endl;
}
