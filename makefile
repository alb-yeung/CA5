all:	Tester driver

driver:	CA5.o requirements.o
	g++ CA5.o requirements.o -o driver

CA5.o:	CA5.cpp
	g++ -c CA5.cpp

requirements.o:	requirements.cpp
	g++ -c requirements.cpp

Tester:	Tester.o CourseMap.o Course.o Student.o
	g++ Tester.o CourseMap.o Course.o Student.o -o Tester

Tester.o:	Tester.cpp CourseMap.h Course.h
	g++ -c Tester.cpp CourseMap.h Course.h

Student.o:	Student.cpp Student.h CourseMap.h Course.h
	g++ -c Student.cpp Student.h CourseMap.h Course.h

CourseMap.o:	CourseMap.cpp CourseMap.h Course.h
	g++ -c CourseMap.cpp CourseMap.h Course.h

Course.o:	Course.cpp Course.h
	g++ -c Course.cpp Course.h

clean:
	rm -f *o *.gch Tester driver
