// Can "download" a copy of a Course and view Lectures "locally", and prints error messages
#ifndef BRIGHTPLACEAPP_H
#define BRIGHTPLACEAPP_H

#include <iostream>
#include <string>

#include "Course.h"
#include "Brightplace.h"

using namespace std;

class BrightplaceApp {
    public:
        BrightplaceApp(const string& name);
        ~BrightplaceApp();

        bool download(const Brightplace& brightplace, int course);

        void print() const;
        void printCourse() const;
        void play(int index) const;

    private:
        string name;    // who is using the BrightplaceApp
        Course* course;
};

#endif
