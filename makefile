all:	Tester driver

driver:	CA5.o requirements.o
	g++ CA5.o requirements.o -o driver

CA5.o:	CA5.cpp
	g++ -c CA5.cpp

requirements.o:	requirements.cpp requirements.h
	g++ -c requirements.cpp requirements.h

Tester:	Tester.o CourseMap.o Course.o Student.o requirements.o
	g++ Tester.o CourseMap.o Course.o Student.o requirements.o -o Tester

Tester.o:	Tester.cpp Student.h
	g++ -c Tester.cpp Student.h

Student.o:	Student.cpp Student.h
	g++ -c Student.cpp Student.h

CourseMap.o:	CourseMap.cpp CourseMap.h
	g++ -c CourseMap.cpp CourseMap.h

Course.o:	Course.cpp Course.h
	g++ -c Course.cpp Course.h

clean:
	rm -f *o *.gch Tester driver
