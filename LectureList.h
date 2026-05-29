// Data structure for Lectures
#ifndef LECTURELIST_H
#define LECTURELIST_H

#include "defs.h"
#include "Lecture.h"

using namespace std;

class LectureList {
    public:
        LectureList();
        ~LectureList();

        Lecture* get(int index) const;
        bool add(Lecture* const l);
        int size() const;
        Lecture* remove(int index);
        bool isFull() const;
        void print() const;

    private:
        Lecture** lectures;
        int numOfLectures;
};

#endif
