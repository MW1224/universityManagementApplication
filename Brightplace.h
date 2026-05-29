/*
Allows adding, deleting, accessing and printing of Courses and the Lectures for the Courses.
Manages a collection of Courses. Prints error messages to std::cout.
*/

#ifndef BRIGHTPLACE_H
#define BRIGHTPLACE_H

#include <iostream>
#include <string>

#include "CourseList.h"

using namespace std;

class Brightplace {
    public:
        Brightplace();
        ~Brightplace();

        void addCourse(const string& title, const string& instructor);
        void deleteCourse(int index);
        int getNumCourses() const;
        bool download(int index, Course** course) const;

        void addLecture(int course, const string& title, const string& content, const Date& date);
        void deleteLecture(int course, int lecture);

        void printCourses() const;
        void printCourse(int index) const;
        void playLecture(int courseIndex, int lectureIndex) const;

    private:
        CourseList* courseList;
};

#endif
