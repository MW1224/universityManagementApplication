
#include <iostream>
#include <string>
#include <vector>
#include "Control.h"


const vector<string> Control::menu ={
    "Print all courses",
    "Print course",
    "Play lecture",
    "Remove course",
    "Remove lecture",
    "Download course",
    "Print BrightplaceApp course",
    "Play BrightplaceApp lecture"
};

// void printCourses();
// void printCourse();
// void playLecture();
// void removeCourse();
// void removeLecture();

// // BrightplaceApp functions
// void downloadCourse();
// void printBrightplaceAppCourse();
// void playBrightplaceAppLecture();

Control::Control():brightplaceapp("Joe"){
    
}

void Control::launch(){
    //make a view, get input, launch the appropriate test
    View view;
    int choice = -1;

    initBrightplace();

    while (choice!= 0){
        view.menu(menu, choice);
        switch(choice){
            case 1: printCourses(); break;
            case 2: printCourse(); break;
            case 3: playLecture(); break;
            case 4: removeCourse(); break;
            case 5: removeLecture(); break;
            case 6: downloadCourse(); break;
            case 7: printBrightplaceAppCourse(); break;
            case 8: playBrightplaceAppLecture(); break;
        }
    }
}

void Control::initBrightplace(){
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

void Control::printCourses(){
    brightplace.printCourses();
}

void Control::printCourse(){
    int course;
    brightplace.printCourses();
    cout<<"Enter course number: ";
    view.getNumber(course);
    brightplace.printCourse(course);
}

void Control::playLecture(){
    int course, lecture;
    brightplace.printCourses();
    cout<<"Enter course number: ";
    view.getNumber(course);
    brightplace.printCourse(course);
    cout<<"Enter lecture number: ";
    view.getNumber(lecture);
    brightplace.playLecture(course,lecture);
}

void Control::removeCourse(){
    int course;
    brightplace.printCourses();
    cout<<"Enter course number to delete: ";
    view.getNumber(course);
    brightplace.deleteCourse(course);
    cout<<"Course deleted."<<endl;
}

void Control::removeLecture(){
    int course, lecture;
    brightplace.printCourses();
    cout<<"Enter course number: ";
    view.getNumber(course);
    brightplace.printCourse(course);
    cout<<"Enter lecture number to delete: ";
    view.getNumber(lecture);
    brightplace.deleteLecture(course,lecture);
    cout<<"Lecture deleted."<<endl;
}

// BrightplaceApp functions
void Control::downloadCourse(){
    int course;
    brightplace.printCourses();
    cout<<"Enter course number: ";
    view.getNumber(course);
    if(brightplaceapp.download(brightplace, course)){
        cout<<"Course downloaded."<<endl;
    }else{
        cout<<"Course not downloaded."<<endl;
    }
}

void Control::printBrightplaceAppCourse(){
    brightplaceapp.printCourse();
}

void Control::playBrightplaceAppLecture(){
    int lecture;
    brightplaceapp.printCourse();
    cout<<"Enter lecture number: ";
    view.getNumber(lecture);
    brightplaceapp.play(lecture);
}

const string Control::courseTitles[5] = {
    "Ladders",
    "History of Ice Cream",
    "Who's the Boss?",
    "Air Conditioning Repair",
    "Can I Fry That?"};

const string Control::instructors[5] = {"Bob", "Sue", "Joe", "Mary", "Bill"};

// These do not make any sense - just for testing
const string Control::lectureTitles[5][5] = {
    {"Intro to Ladders", "Stepladders", "Fire Engine Ladders", "Advanced Ladders", "Lawsuits"},
    {"Vanilla", "Chocolate", "Strawberry","Neapolitan","Sundaes"},
    {"Angela", "Tony","Mona","Samantha","Jonathan"},
    {"Window","Portable","Central","Automobile AC","Refridgerators"},
    {"Helicopters","Lions","Santa's Sleigh", "Guitars","Whales"}
};

// some of these dates are out of order - on purpose for testing
 const Date Control::dates[5][5]={
    {Date(2024, 1, 1), Date(2023, 1, 2), Date(2024, 8, 3), Date(2022, 6, 4), Date(2023, 3, 5)},
    {Date(2024, 1, 1), Date(2023, 1, 2), Date(2024, 8, 3), Date(2022, 6, 4), Date(2023, 3, 5)},
    {Date(2023, 4, 15), Date(2024, 11, 7), Date(2023, 8, 22), Date(2024, 5, 12), Date(2023, 6, 30)},
    {Date(2023, 7, 18), Date(2024, 3, 12), Date(2023, 11, 5), Date(2024, 2, 20), Date(2023, 9, 9)},
    {Date(2024, 7, 25), Date(2023, 2, 14), Date(2024, 10, 8), Date(2023, 5, 28), Date(2024, 1, 19)},
 };


// Also nonsense
const string Control::content[5][5] = {
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


