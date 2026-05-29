#include "CourseList.h"

CourseList::CourseList() {
    numOfCourses = 0;
    courses = new Course*[MAX_ARRAY];
}

CourseList::~CourseList() {
    delete [] courses;
}

Course* CourseList::get(int index) const {
    if (index < 0 || index >= numOfCourses) {
        return nullptr;
    }
    return courses[index];
}

bool CourseList::add(Course* const c) {
    if (isFull()) {
        return false;
    }

    courses[numOfCourses++] = c;
    return true;
}

Course* CourseList::remove(int index) {
    if (index < 0 || index >= numOfCourses) {
        return nullptr;
    }

    Course* courseToRemove = courses[index];
    for (int i = index; i < numOfCourses-1; ++i) {
        courses[i] = courses[i+1];
    }
    --numOfCourses;
    return courseToRemove;
}

int CourseList::size() const {
    return numOfCourses;
}

bool CourseList::isFull() const {
    return numOfCourses >= MAX_ARRAY;
}

void CourseList::print() const {
    for (int i = 0; i < numOfCourses; i++) {
        cout << "\n" << i << ") ";
        courses[i]->print();
    }
}
