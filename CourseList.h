// Data structure for Courses
#ifndef COURSELIST_H
#define COURSELIST_H

#include <iostream>

#include "defs.h"
#include "Course.h"

using namespace std;

class CourseList {
    public:
        CourseList();
        ~CourseList();

        Course* get(int index) const;
        bool add(Course* const c);
        Course* remove(int index);
        int size() const;
        bool isFull() const;
        void print() const;

    private:
        Course** courses;
        int numOfCourses;
};

#endif
