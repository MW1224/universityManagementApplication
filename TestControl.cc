
#include "TestControl.h"


const vector<string> TestControl::menu ={
    "CourseList test",
    "Brightplace course test",
    "Brightplace lecture test",
    "BrightplaceApp download test",
    "BrightplaceApp memory test\n",
    "Test all and get mark\n"
};


void TestControl::launch(){
    //get input, launch the appropriate test
    int choice = -1;

    while (choice!= 0){
        view.menu(menu, choice);
        switch(choice){
            case 1: courseListTest(); break;
            case 2: brightplaceCourseTest(); break;
            case 3: brightplaceLectureTest(); break;
            case 4: brightplaceappDownloadTest(); break;
            case 5: brightplaceappMemoryTest(); break;
            case 6: int mark = 0;
                    mark += courseListTest();
                    mark += brightplaceCourseTest();
                    mark += brightplaceLectureTest();
                    mark += brightplaceappDownloadTest();
                    mark += brightplaceappMemoryTest();
                    cout<<endl<<"Your mark is "<<mark<<"/50"<<endl;
                    break;
        }
    }
}

void TestControl::initBrightplace(Brightplace& brightplace){
    cout<<"Initializing Brightplace..."<<endl;
    for (int j = 0; j < 5; ++j){
        brightplace.addCourse(courseTitles[j],instructors[j]);
    }
    //we add the courses first, then the lectures for test purposes
     for(int j = 0; j < 5; ++j){  
        for (int i = 0; i <5; ++i){
            brightplace.addLecture(j,lectureTitles[j][i], content[j][i], dates[j][i]);
        }
    }
}

int TestControl::courseListTest(){
    // Add Courses to the list.
    // Print the list.
    // Check the size
    // Remove two courses.
    // Print the list. Check the size
    // Add a course
    // Print the list. Check the size
    // Remove all courses
    // Print the list. Check the size

    cout<<"CourseList test"<<endl;
    Course* courses[5];
    CourseList courseList;
    cout<<"Adding courses"<<endl;
    for (int i = 0; i < 5; ++i){
        cout<<"Course title "<<courseTitles[i]<<" instructor "<<instructors[i]<<endl;
        courses[i] = new Course(courseTitles[i], instructors[i]);
        courseList.add(courses[i]);
    }
    cout<<"Printing courses"<<endl;
    tester.initCapture();
    for (int i = 0; i < courseList.size(); ++i){
        courseList.get(i)->print();
    }
    tester.endCapture();

    int marks = 0;

    cout<<"Checking size"<<endl;
    if (courseList.size() != 5){
        cout<<"Error: size should be 5, but is "<<courseList.size()<<endl;
    }else{
        marks += 1;
    }

    cout<<"Checking output"<<endl;
    int errors = 0;
    tester.find({0,1,2,3,4}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 1;
    }

    cout<<"Removing two courses"<<endl;
    courseList.remove(0);
    courseList.remove(2);
    courseList.remove(3);

    cout<<"Checking size"<<endl;
    if (courseList.size() != 3){
        cout<<"Error: size should be 3, but is "<<courseList.size()<<endl;
    }else{
        cout<<"Size is correct"<<endl;
        marks += 1;
    }

    cout<<"Printing courses"<<endl;
    tester.initCapture();
    for (int i = 0; i < courseList.size(); ++i){
        courseList.get(i)->print();
    }
    tester.endCapture();

    

    cout<<"Checking output for"<<endl;
    cout<<courseTitles[1]<<endl;
    cout<<courseTitles[2]<<endl;
    cout<<courseTitles[4]<<endl;

    tester.find({1,2,4}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 1;
    }

    tester.confirmAbsent({0,3}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: removed courses found"<<endl;
    }else{
        cout<<"No removed courses found, output is correct"<<endl;
        marks += 1;
    }

    cout<<"Adding a course"<<endl;
    courseList.add(courses[3]);

    cout<<"Checking size"<<endl;
    if (courseList.size() != 4){
        cout<<"Error: size should be 4, but is "<<courseList.size()<<endl;
    }else{
        cout<<"Size is correct"<<endl;
        marks += 1;
    }

    cout<<"Printing courses"<<endl;
    tester.initCapture();
    for (int i = 0; i < courseList.size(); ++i){
        courseList.get(i)->print();
    }
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({1,2,3,4}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 1;
    }

    tester.confirmAbsent({0}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: removed courses found"<<endl;
    }else{
        cout<<"No removed courses found, output is correct"<<endl;
        marks += 1;
    }

    cout<<"Removing all courses"<<endl;
    courseList.remove(0);
    courseList.remove(0);
    courseList.remove(0);
    courseList.remove(0);
    
    cout<<"Checking size"<<endl;
    if (courseList.size() != 0){
        cout<<"Error: size should be 0, but is "<<courseList.size()<<endl;
    }else{
        cout<<"Size is correct"<<endl;
        marks += 1;
    }

    cout<<"Printing courses"<<endl;
    tester.initCapture();
    for (int i = 0; i < courseList.size(); ++i){
        courseList.get(i)->print();
    }
    tester.endCapture();
    
    cout<<"Checking output"<<endl;
    tester.confirmAbsent({0,1,2,3,4}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: removed courses found"<<endl;
    }else{
        cout<<"No removed courses found, output is correct"<<endl;
        marks += 1;
    }

    cout<<"CourseList test complete, deleting Courses"<<endl;

    for (int i = 0; i < 5; ++i){
        delete courses[i];
    }
    cout<<"Marks: "<<marks<<"/10"<<endl;
    return marks;
}

int TestControl::brightplaceCourseTest(){
    
    cout<<"Brightplace course test"<<endl;
    Brightplace brightplace;
    initBrightplace(brightplace);
    int marks = 0;

    cout<<"Printing courses"<<endl;
    tester.initCapture();
    brightplace.printCourses();
    tester.endCapture();

    cout<<"Checking output"<<endl;
    int errors = 0;
    tester.find({0,1,2,3,4}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }

    cout<<"Deleting course 0"<<endl;
    brightplace.deleteCourse(0);

    cout<<"Printing courses"<<endl;
    tester.initCapture();
    brightplace.printCourses();
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({1,2,3,4}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }

    cout<<"Deleting course 2"<<endl;
    brightplace.deleteCourse(2);

    cout<<"Printing courses"<<endl;
    tester.initCapture();
    brightplace.printCourses();
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({1,2,4}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }

    cout<<"Printing the Course at index 1 (should be "<<courseTitles[2]<<")"<<endl;
    tester.initCapture();
    brightplace.printCourse(1);
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({2}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }
    tester.confirmAbsent({0,1,3,4}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: other courses found"<<endl;
    }else{
        cout<<"No removed courses found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"brightplace course test complete"<<endl;   
    cout<<"Marks: "<<marks<<"/10"<<endl;

    return marks;
}


int TestControl::brightplaceLectureTest(){
    cout<<"Brightplace course test"<<endl;
    Brightplace brightplace;
    initBrightplace(brightplace);
    int marks = 0;

    // print out and capture the relevant dates
    // so that we can search for them in the output
    string dates[5][5];
    cout<<"Capturing Date data, please ignore"<<endl;
    for (int i = 0; i < 5; ++i){
        for (int j = 0; j < 5; j++){
            tester.initCapture();
            DateTime t(TestControl::dates[i][j]);
            t.print();
            tester.endCapture();
            dates[i][j] = tester.getOutput();
        }
    }

    cout<<endl<<endl<<"Printing course at index 2"<<endl;
    tester.initCapture();
    brightplace.printCourse(2);
    tester.endCapture();

    cout<<"Checking output for correct Lectures and Dates"<<endl;
    int errors = 0, errors2 = 0;
    tester.find({0,1,2,3,4}, lectureTitles[2], errors);
    tester.find({0,1,2,3,4}, dates[2], errors2);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else if (errors2 != 0){
        cout<<"Error: dates not found"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }   

    cout<<"Deleting lecture 2 and 3 from course 2"<<endl;
    brightplace.deleteLecture(2,2);
    brightplace.deleteLecture(2,2);

    cout<<"Printing course at index 2"<<endl;
    tester.initCapture();
    brightplace.printCourse(2);
    tester.endCapture();

    cout<<"Checking output for correct Lectures and Dates"<<endl;
    errors = 0, errors2 = 0;
    tester.find({0,1,4}, lectureTitles[2], errors);
    tester.find({0,1,4}, dates[2], errors2);
    if (errors != 0){
        cout<<"Error: output is incorrect"<<endl;
    }else if (errors2 != 0){
        cout<<"Error: dates not found"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }

    tester.confirmAbsent({2,3}, lectureTitles[2], errors);
    tester.confirmAbsent({2,3}, dates[2], errors2);
    if (errors != 0){
        cout<<"Error: removed lectures found"<<endl;
    }else if (errors2 != 0){
        cout<<"Error: removed dates found"<<endl;
    }else{
        cout<<"No removed lectures or dates found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"Testing play lecture"<<endl;
    cout<<"Playing Lecture lecture 1 from course 2"<<endl;
    tester.initCapture();
    brightplace.playLecture(2,1);
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({4}, content[2], errors);
    if (errors != 0){
        cout<<"Error: lecture content not found"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }


    cout<<"Removing all lectures from course 2"<<endl;
    brightplace.deleteLecture(2,0);
    brightplace.deleteLecture(2,0);
    brightplace.deleteLecture(2,0);

    cout<<"Printing course at index 2"<<endl;
    tester.initCapture();
    brightplace.printCourse(2);
    tester.endCapture();

    cout<<"Checking output for correct Lectures and Dates (should be none)"<<endl;

    errors = 0, errors2 = 0;
    tester.confirmAbsent({0,1,2,3,4}, lectureTitles[2], errors);

    if (errors != 0 || errors2 != 0){
        cout<<"Error: something was found"<<endl;
    }else{
        cout<<"Output is correct"<<endl;
        marks += 2;
    }

    cout<<"brightplace lecture test complete"<<endl;
    cout<<"Marks: "<<marks<<"/10"<<endl;

    return marks;
}

int TestControl::brightplaceappDownloadTest(){
    cout<<"BrightplaceApp download test"<<endl;
    Brightplace brightplace;
    initBrightplace(brightplace);
    BrightplaceApp brightplaceapp("Your name here");
    int marks = 0;

    cout<<"Attempting to print Course"<<endl;
    tester.initCapture();
    brightplaceapp.printCourse();
    tester.endCapture();

    cout<<"Checking output"<<endl;
    int errors = 0;
    tester.confirmAbsent({0,1,2,3,4}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: something was found"<<endl;
    }else{
        cout<<"No courses found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"Downloading Course 3"<<endl;
    brightplaceapp.download(brightplace, 3);

    cout<<"Printing Course"<<endl;
    tester.initCapture();
    brightplaceapp.printCourse();
    tester.endCapture();

    cout<<"Checking for Course title"<<endl;
    errors = 0;
    tester.find({3}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: course not found"<<endl;
    }else{
        cout<<"Course title found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"Checking for Lecture titles"<<endl;
    errors = 0;
    tester.find({0,1,2,3,4}, lectureTitles[3], errors);
    if (errors != 0){
        cout<<"Error: lecture titles not found"<<endl;
    }else{
        cout<<"Lecture titles found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"Playing Lecture lecture 2"<<endl;
    tester.initCapture();
    brightplaceapp.play(2);
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({2}, content[3], errors);
    if (errors != 0){
        cout<<"Error: lecture content not found"<<endl;
    }else{
        cout<<"Lecture content found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"Downloading Course 1"<<endl;
    brightplaceapp.download(brightplace, 1);

    cout<<"Printing Course"<<endl;
    brightplaceapp.printCourse();


    cout<<"Playing Lecture Lecture 4"<<endl;
    tester.initCapture();
    brightplaceapp.play(4);
    tester.endCapture();

    cout<<"Checking output"<<endl;
    tester.find({2}, content[1], errors);
    if (errors != 0){
        cout<<"Error: lecture content not found - are your lectures in order by Date?"<<endl;
    }else{
        cout<<"Lecture content found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"BrightplaceApp download test complete"<<endl;
    cout<<"Marks: "<<marks<<"/10"<<endl;

    // for (int i = 0; i < 5; ++i){
    //     cout<<i<<") "<<lectureTitles[1][i]<<endl;
    //     cout<<content[1][i]<<endl;
    // }

    return marks;


}


int TestControl::brightplaceappMemoryTest(){
    cout<<"BrightplaceApp memory test"<<endl;
    Brightplace brightplace;
    initBrightplace(brightplace);
    BrightplaceApp brightplaceapp("Your name here");
    int marks = 0;

    
    cout<<endl<<"Downloading Course 3"<<endl;
    brightplaceapp.download(brightplace, 3);

    cout<<endl<<"Deleting Course 3 from Brightplace"<<endl;

    brightplace.deleteCourse(3);

    cout<<endl<<"Printing Course 3 from BrightplaceApp"<<endl;
    tester.initCapture();
    brightplaceapp.printCourse();
    tester.endCapture();

    cout<<endl<<"Checking for Course title"<<endl;
    int errors = 0;
    tester.find({3}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: course not found"<<endl;
    }else{
        cout<<"Course title found, output is correct"<<endl;
        marks += 3;
    }

    cout<<endl<<"Checking for Lecture titles"<<endl;
    errors = 0;
    tester.find({0,1,2,3,4}, lectureTitles[3], errors);
    if (errors != 0){
        cout<<"Error: lecture titles not found"<<endl;
    }else{
        cout<<"Lecture titles found, output is correct"<<endl;
        marks += 3;
    }

    cout<<endl<<"Downloading Course 1, then Course 0"<<endl;
    brightplaceapp.download(brightplace, 1);
    brightplaceapp.download(brightplace, 0);

    cout<<endl<<"Printing Course 1 from Brightplace"<<endl;
    tester.initCapture();
    brightplace.printCourse(1);
    tester.endCapture();

    cout<<endl<<"Checking for Course title"<<endl;
    errors = 0;
    tester.find({1}, courseTitles, errors);
    if (errors != 0){
        cout<<"Error: course not found"<<endl;
    }else{
        cout<<"Course title found, output is correct"<<endl;
        marks += 2;
    }

    cout<<endl<<"Checking for Lecture titles"<<endl;
    errors = 0;
    tester.find({0,1,2,3,4}, lectureTitles[1], errors);
    if (errors != 0){
        cout<<"Error: lecture titles not found"<<endl;
    }else{
        cout<<"Lecture titles found, output is correct"<<endl;
        marks += 2;
    }

    cout<<"BrightplaceApp memory test complete"<<endl;
    cout<<"Marks: "<<marks<<"/10"<<endl;

    return marks;
}



const string TestControl::courseTitles[5] = {
    "Ladders",
    "History of Ice Cream",
    "Who's the Boss?",
    "Air Conditioning Repair",
    "Can I Fry That?"};

const string TestControl::instructors[5] = {"Bob", "Sue", "Joe", "Mary", "Bill"};

// These do not make any sense - just for testing
const string TestControl::lectureTitles[5][5] = {
    {"Intro to Ladders", "Stepladders", "Fire Engine Ladders", "Advanced Ladders", "Lawsuits"},
    {"Vanilla", "Chocolate", "Strawberry","Neapolitan","Sundaes"},
    {"Angela", "Tony","Mona","Samantha","Jonathan"},
    {"Window","Portable","Central","Automobile AC","Refridgerators"},
    {"Helicopters","Lions","Santa's Sleigh", "Guitars","Whales"}
};

// some of these dates are out of order - on purpose for testing
 const Date TestControl::dates[5][5]={
    {Date(2024, 1, 1), Date(2023, 1, 2), Date(2024, 8, 3), Date(2022, 6, 4), Date(2023, 3, 5)},
    {Date(2024, 1, 1), Date(2023, 1, 2), Date(2024, 8, 3), Date(2022, 6, 4), Date(2023, 3, 5)},
    {Date(2023, 4, 15), Date(2024, 11, 7), Date(2023, 8, 22), Date(2024, 5, 12), Date(2023, 6, 30)},
    {Date(2023, 7, 18), Date(2024, 3, 12), Date(2023, 11, 5), Date(2024, 2, 20), Date(2023, 9, 9)},
    {Date(2024, 7, 25), Date(2023, 2, 14), Date(2024, 10, 8), Date(2023, 5, 28), Date(2024, 1, 19)},
 };

const string TestControl::content[5][5] = {
R"(
 ▄▀▀▀▀▀───▄█▀▀▀█▄
▐▄▄▄▄▄▄▄▄██▌▀▄▀▐██
▐▒▒▒▒▒▒▒▒███▌▀▐███
 ▌▒▓▒▒▒▒▓▒██▌▀▐██
 ▌▓▐▀▀▀▀▌▓─▀▀▀▀▀)",

R"(
┼┼┼┼┼┼┼┼▓▓▓▓┼┼┼
┼╔═▒▒▒▒▓▄░░▄▓┼┼
┼▀┼▒▒▒▓▓▒──▒▓▓┼
┼┼┼▒▌▒▐┼▓▓▓▓┼┼┼)",

R"(
─▀▀▌───────▐▀▀
─▄▀░◌░░░░░░░▀▄
▐░░◌░▄▀██▄█░░░▌
▐░░░▀████▀▄░░░▌
═▀▄▄▄▄▄▄▄▄▄▄▄▀═
)",

R"(
▒▒▄▀▀▀▀▀▄▒▒▒▒▒▄▄▄▄▄▒▒▒
▒▐░▄░░░▄░▌▒▒▄█▄█▄█▄█▄▒
▒▐░▀▀░▀▀░▌▒▒▒▒▒░░░▒▒▒▒
▒▒▀▄░═░▄▀▒▒▒▒▒▒░░░▒▒▒▒
▒▒▐░▀▄▀░▌▒▒▒▒▒▒░░░▒▒▒▒
)",
R"(
─────────█▄██▄█
█▄█▄█▄█▄█▐█┼██▌█▄█▄█▄█▄█
███┼█████▐████▌█████┼███
█████████▐████▌█████████
)",
R"(
█───▄▀▀▀▀▄─▐█▌▐█▌▐██
█──▐▄▄────▌─█▌▐█─▐▌─
█──▐█▀█─▀─▌─█▌▐█─▐██
█──▐████▄▄▌─▐▌▐▌─▐▌─
███─▀████▀───██──▐██
)",
R"(
─────█─▄▀█──█▀▄─█─────
────▐▌──────────▐▌────
────█▌▀▄──▄▄──▄▀▐█────
───▐██──▀▀──▀▀──██▌───
──▄████▄──▐▌──▄████▄──
)",
R"(
─▄▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▄
█░░░█░░░░░░░░░░▄▄░██░█
█░▀▀█▀▀░▄▀░▄▀░░▀▀░▄▄░█
█░░░▀░░░▄▄▄▄▄░░██░▀▀░█
─▀▄▄▄▄▄▀─────▀▄▄▄▄▄▄▀
)",
R"(
║░█░█░║░█░█░█░║░█░█░║
║░█░█░║░█░█░█░║░█░█░║
║░║░║░║░║░║░║░║░║░║░║
╚═╩═╩═╩═╩═╩═╩═╩═╩═╩═╝
)",
R"(
█▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀█
█░░╦─╦╔╗╦─╔╗╔╗╔╦╗╔╗░░█
█░░║║║╠─║─║─║║║║║╠─░░█
█░░╚╩╝╚╝╚╝╚╝╚╝╩─╩╚╝░░█
█▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄█

)",
R"(
───▄██▄─────────────▄▄
──█████▄▄▄▄───────▄▀
────▀██▀▀████▄───▄▀
───▄█▀▄██▄████▄─▄█
▄▄█▀▄▄█─▀████▀██▀
)",
R"(
█▓▒▓█▀██▀█▄░░▄█▀██▀█▓▒▓█
█▓▒░▀▄▄▄▄▄█░░█▄▄▄▄▄▀░▒▓█
█▓▓▒░░░░░▒▓░░▓▒░░░░░▒▓▓█
)",
R"(
──▄──▄────▄▀
───▀▄─█─▄▀▄▄▄
▄██▄████▄██▄▀█▄
─▀▀─█▀█▀▄▀███▀
──▄▄▀─█──▀▄▄
)",
R"(
─▄▀▀▀▄────▄▀█▀▀█▄
▄▀─▀─▀▄▄▀█▄▀─▄▀─▄▀▄
█▄▀█───█─█▄▄▀─▄▀─▄▀▄
──█▄▄▀▀█▄─▀▀▀▀▀▀▀─▄█
─────▄████▀▀▀▀████─▀▄
)",
R"(
╔══╗░░░░╔╦╗░░╔═════╗
║╚═╬════╬╣╠═╗║░▀░▀░║
╠═╗║╔╗╔╗║║║╩╣║╚═══╝║
╚══╩╝╚╝╚╩╩╩═╝╚═════╝
)",
R"(
░░▄█▀▀▀░░░░░░░░▀▀▀█▄
▄███▄▄░░▀▄██▄▀░░▄▄███▄
▀██▄▄▄▄████████▄▄▄▄██▀
░░▄▄▄▄██████████▄▄▄▄
░▐▐▀▐▀░▀██████▀░▀▌▀▌▌
)",
R"(
▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒
▒▒▄▄▄▒▒▒█▒▒▒▒▄▒▒▒▒▒▒▒▒
▒█▀█▀█▒█▀█▒▒█▀█▒▄███▄▒
░█▀█▀█░█▀██░█▀█░█▄█▄█░
░█▀█▀█░█▀████▀█░█▄█▄█░
████████▀█████████████
)",
R"(
┊┊┊┊┊┊┊╱▏┊┊┊┊┊┊┊
┊┊┊┊┊┊▕╱┊┊┊┊┊┊┊┊
┊┊┊╱▔▔╲┊╱▔▔╲┊┊┊┊
┊┊▕┈┈┈┈▔┈┈┈╱┊┊┊┊
┊┊▕┈┈┈┈┈┈┈┈╲┊┊┊┊
┊┊┊╲┈┈┈┈┈┈┈╱┊┊┊┊
┊┊┊┊╲▂▂▂▂▂╱┊┊┊┊┊
)",
R"(
▂╱▔▔╲╱▔▔▔▔╲╱▔▔╲▂
╲┈▔╲┊╭╮┈┈╭╮┊╱▔┈╱
┊▔╲╱▏┈╱▔▔╲┈▕╲╱▔┊
┊┊┊┃┈┈▏┃┃▕┈┈┃┊┊┊
┊┊┊▏╲┈╲▂▂╱┈╱▕┊┊┊
)",
R"(
╥━━━━━━━━╭━━╮━━┳
╢╭╮╭━━━━━┫┃▋▋━▅┣
╢┃╰┫┈┈┈┈┈┃┃┈┈╰┫┣
╢╰━┫┈┈┈┈┈╰╯╰┳━╯┣
╢┊┊┃┏┳┳━━┓┏┳┫┊┊┣
╨━━┗┛┗┛━━┗┛┗┛━━┻
)",
R"(
▀▀▀▀█▀▀▀▀
─▄▀█▀▀█──────▄
█▄▄█▄▄██████▀
▀▀█▀▀▀█▀▀
─▀▀▀▀▀▀▀
)",
R"(
──▄▀▀▀▄───────────────
──█───█───────────────
─███████─────────▄▀▀▄─
░██─▀─██░░█▀█▀▀▀▀█░░█░
░███▄███░░▀░▀░░░░░▀▀░░
)",
R"(
░╔╔╩╩╝
▄██▄
░░██████▄░░░░░░▄▄▄▄▄▄█
░░█▀█▀█▀█░░▄░▄████████
░▄▌▄▌▄▌▄▌░▀▄▄▄▄█▄▄▄▄█▄
)",
R"(
░▄▀▀▀▀▄░░▄▄
█░░░░░░▀▀░░█░░░░░░▄░▄
█░║░░░░██░████████████ 
█░░░░░░▄▄░░█░░░░░░▀░▀
░▀▄▄▄▄▀░░▀▀
)",
R"(
─────▀▄▀─────▄─────▄
──▄███████▄──▀██▄██▀
▄█████▀█████▄──▄█
███████▀████████▀
─▄▄▄▄▄▄███████▀
)"
};

