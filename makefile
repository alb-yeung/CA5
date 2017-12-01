all:	Tester

Tester:	Tester.o CourseMap.o Course.o
	g++ Tester.o CourseMap.o Course.o -o Tester

Tester.o:	Tester.cpp CourseMap.h Course.h
	g++ -c Tester.cpp CourseMap.h Course.h

CourseMap.o:	CourseMap.cpp CourseMap.h Course.h
	g++ -c CourseMap.cpp CourseMap.h Course.h

Course.o:	Course.cpp Course.h
	g++ -c Course.cpp Course.h

clean:
	rm -f *o Tester
