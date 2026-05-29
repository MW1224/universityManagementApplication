objects = main.o View.o Control.o Date.o DateTime.o Brightplace.o BrightplaceApp.o Course.o CourseList.o Lecture.o LectureList.o
testobjects = test.o View.o TestControl.o Tester.o Date.o DateTime.o Brightplace.o BrightplaceApp.o Course.o CourseList.o Lecture.o LectureList.o

all: a2 a2test

debug: $(testobjects)
	g++ -g -o a2test $(testobjects)

a2: $(objects)
	g++ -o a2 $(objects)

a2test: $(testobjects)
	g++ -o a2test $(testobjects)

test.o: test.cc TestControl.h Course.h
	g++ -c test.cc
	
main.o: main.cc Control.h Course.h
	g++ -c main.cc 

View.o: View.h View.cc 
	g++ -c View.cc

TestControl.o: TestControl.h TestControl.cc Brightplace.h View.h BrightplaceApp.h Tester.h
	g++ -c TestControl.cc

Tester.o: Tester.h Tester.cc
	g++ -c Tester.cc

Control.o: Control.h Control.cc Brightplace.h View.h BrightplaceApp.h
	g++ -c Control.cc

Date.o: Date.cc Date.h
	g++ -c Date.cc

DateTime.o: DateTime.cc DateTime.h Date.h
	g++ -c DateTime.cc

Brightplace.o: Brightplace.cc Brightplace.h CourseList.h
	g++ -c Brightplace.cc

BrightplaceApp.o: BrightplaceApp.cc BrightplaceApp.h Course.h Brightplace.h
	g++ -c BrightplaceApp.cc

Course.o: Course.cc Course.h Lecture.h LectureList.h
	g++ -c Course.cc

CourseList.o: CourseList.cc CourseList.h defs.h Course.h
	g++ -c CourseList.cc

Lecture.o: Lecture.cc Lecture.h DateTime.h
	g++ -c Lecture.cc

LectureList.o: LectureList.cc LectureList.h defs.h Lecture.h
	g++ -c LectureList.cc

clean:
	rm -f a2 a2test *.o	

