#include "Course.h"

Course::Course(const string& title, const string& instructor) {
    this->title = title;
    this->instructor = instructor;
    lectureList = new LectureList();
}

Course::Course(const Course& c) {
    this->title = c.title;
    this->instructor = c.instructor;
    lectureList = new LectureList();
    for (int i = 0; i < c.lectureList->size(); ++i) {
        lectureList->add(new Lecture(*c.lectureList->get(i)));
    }
}

Course::~Course() {
    for (int i = 0; i < lectureList->size(); ++i) {
        delete lectureList->get(i);
    }
    delete lectureList;
}

string Course::getTitle() const {
    return title;
}

string Course::getInstructor() const {
    return instructor;
}

bool Course::lessThan(const Course& course) const {
    return this->title < course.title;
}

bool Course::addLecture(const string& title, const string& content, const DateTime& date) {
    return lectureList->add(new Lecture(title, content, date));
}

bool Course::removeLecture(int index) {
    Lecture* lectureToRemove = lectureList->remove(index);
    if (lectureToRemove == nullptr) {
        return false;
    } else {
        delete lectureToRemove;
        return true;
    }
}

int Course::getNumLectures() const {
    return lectureList->size();
}

void Course::print() const {
    cout << "Title: " << title << "\nInstructor: " << instructor << endl;
}

void Course::printLectures() const {
    print();
    lectureList->print();
}

void Course::playLecture(int index) const {
    if (index < 0 || index >= lectureList->size()) {
        cout << "Error: invalid index" << endl;
        return;
    }

    lectureList->get(index)->play();
}
