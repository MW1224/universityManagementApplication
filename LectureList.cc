#include "LectureList.h"

LectureList::LectureList() {
    numOfLectures = 0;
    lectures = new Lecture*[MAX_ARRAY];
}

LectureList::~LectureList() {
    delete [] lectures;
}

Lecture* LectureList::get(int index) const {
    if (index < 0 || index >= numOfLectures) {
        return nullptr;
    }
    return lectures[index];
}

bool LectureList::add(Lecture* const l) {
    if (isFull()) {
        return false;
    }

    int i = numOfLectures - 1;
    while (i >= 0 && l->lessThan(*lectures[i])) {
        lectures[i+1] = lectures[i];
        --i;
    }

    lectures[i+1] = l;
    ++numOfLectures;
    return true;
}

int LectureList::size() const {
    return numOfLectures;
}

Lecture* LectureList::remove(int index) {
    if (index < 0 || index >= numOfLectures) {
        return nullptr;
    }

    Lecture* lectureToRemove = lectures[index];
    for (int i = index; i < numOfLectures-1; ++i) {
        lectures[i] = lectures[i+1];
    }
    --numOfLectures;
    return lectureToRemove;
}

bool LectureList::isFull() const {
    return numOfLectures >= MAX_ARRAY;
}

void LectureList::print() const {
    for (int i = 0; i < numOfLectures; i++) {
        cout << "\n" << i << ") ";
        lectures[i]->print();
    }
}
