#include "Brightplace.h"

Brightplace::Brightplace() {
    courseList = new CourseList();
}

Brightplace::~Brightplace() {
    for (int i = 0; i < courseList->size(); ++i) {
        delete courseList->get(i);
    }
    delete courseList;
}

void Brightplace::addCourse(const string& title, const string& instructor) {
    if (!courseList->add(new Course(title, instructor))) {
        cout << "Error: unable to add Course" << endl;
    }
}

void Brightplace::deleteCourse(int index) {
    Course* courseToRemove = courseList->remove(index);
    if (courseToRemove == nullptr) {
        cout << "Error: invalid index -- no such course to remove" << endl;
    } else {
        delete courseToRemove;
    }
}

int Brightplace::getNumCourses() const {
    return courseList->size();
}

bool Brightplace::download(int index, Course** course) const {
    Course* coursePtr = courseList->get(index);
    if (coursePtr == nullptr) {
        cout << "Error: invalid course index -- unable to download" << endl;
        return false;
    }

    *course = coursePtr;
    return true;
}

void Brightplace::addLecture(int course, const string& title, const string& content, const Date& date) {
    DateTime dateTime = DateTime(date);
    Course* courseToFind = courseList->get(course);
    if (courseToFind == nullptr) {
        cout << "Error: invalid course index -- no such Course" << endl;
    } else {
        if (!courseToFind->addLecture(title, content, date)) {
            cout << "Error: unable to add lecture" << endl;
        }
    }
}

void Brightplace::deleteLecture(int course, int lecture) {
    Course* courseToFind = courseList->get(course);
    if (courseToFind == nullptr) {
        cout << "Error: invalid course index -- no such Course" << endl;
    } else {
        if (!courseToFind->removeLecture(lecture)) {
            cout << "Error: invalid lecture index -- no such Lecture" << endl;
        }
    }
}

void Brightplace::printCourses() const {
    cout << "Brightplace\n======" << endl;
    courseList->print();
}

void Brightplace::printCourse(int index) const {
    Course* courseToPrint = courseList->get(index);
    if (courseToPrint != nullptr) {
        courseToPrint->printLectures();
    } else {
        cout << "Error: invalid index -- unable to print course" << endl;
    }
}

void Brightplace::playLecture(int courseIndex, int lectureIndex) const {
    Course* course = courseList->get(courseIndex);
    if (course == nullptr) {
        cout << "Error: invalid course index -- unable to play course's lecture" << endl;
    } else {
        course->playLecture(lectureIndex);  // this method handles error message
    }
}
