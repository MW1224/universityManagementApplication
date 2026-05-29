// Manages the interaction of the other objects
#ifndef CONTROL_H
#define CONTROL_H

#include <iostream>
#include <string>
#include <vector>

#include "Brightplace.h"
#include "View.h"
#include "BrightplaceApp.h"

using namespace std;


class Control
{
  public:
    Control();
    
    void launch();
    

  private:
	// Brightplace functions
    void printCourses();
    void printCourse();
    void playLecture();
	  void removeCourse();
	  void removeLecture();

	// BrightplaceApp functions
    void downloadCourse();
    void printBrightplaceAppCourse();
    void playBrightplaceAppLecture();

    //helper function
    void initBrightplace();

    Brightplace brightplace;
    View view;
    BrightplaceApp brightplaceapp;


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
