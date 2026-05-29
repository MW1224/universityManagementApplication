#include "BrightplaceApp.h"

BrightplaceApp::BrightplaceApp(const string& name) {
    this->name = name;
    course = nullptr;
}

BrightplaceApp::~BrightplaceApp() {
    delete course;
}

bool BrightplaceApp::download(const Brightplace& brightplace, int course) {
    Course* tempCourse = nullptr;

    if (brightplace.download(course, &tempCourse)) {  // error message is already handled by Brightplace's download function
        delete this->course;
        this->course = new Course(*tempCourse);
        return true;
    }
    return false;
}

void BrightplaceApp::print() const {
    cout << "BrightPlaceApp name: " << name << "\nCourse: ";
    if (course == nullptr) {
        cout << "Error - course was not downloaded" << endl;
        return;
    }

    course->print();
}

void BrightplaceApp::printCourse() const {
    if (course == nullptr) {
        cout << "Error - course was not downloaded" << endl;
        return;
    }

    cout << "Course and Lectures: ";
    course->printLectures();
}

void BrightplaceApp::play(int index) const {
    if (course == nullptr) {
        cout << "Error - course was not downloaded" << endl;
        return;
    }

    course->playLecture(index); // course's playLecture method handles error message
}
