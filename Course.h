// Course information (title and instructor) and manages a collection of Lectures
#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>

#include "Lecture.h"
#include "LectureList.h"

class Course {
    public:
        Course(const string& title, const string& instructor);
        Course(const Course& c);
        ~Course();

        bool lessThan(const Course& course) const;
        bool addLecture(const string& title, const string& content, const DateTime& date);
        bool removeLecture(int index);
        int getNumLectures() const;
        
        void print() const;
        void printLectures() const;
        void playLecture(int index) const;

        string getTitle() const;
        string getInstructor() const;

    private:
        string title;
        string instructor;
        LectureList* lectureList;
};

#endif
