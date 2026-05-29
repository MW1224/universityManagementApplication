// Manages the interaction of the other objects in order to run tests
#ifndef TESTCONTROL_H
#define TESTCONTROL_H

#include <iostream>
#include <string>
#include <vector>

#include "Brightplace.h"
#include "View.h"
#include "BrightplaceApp.h"
#include "Tester.h"

using namespace std;


class TestControl
{
  public:
    
    void launch();
    

  private:
    int courseListTest();
    int brightplaceCourseTest();
    int brightplaceLectureTest();
    int brightplaceappDownloadTest();
    int brightplaceappMemoryTest();

    //helper function
    void initBrightplace(Brightplace& brightplace);

    View view;
    Tester tester;

    const static vector<string> menu;

    // Course information
    const static string courseTitles[5];
    const static string instructors[5];

    // Lecture information
    const static string lectureTitles[5][5];
    const static string content[5][5];
    const static Date dates[5][5];


    
};

#endif
