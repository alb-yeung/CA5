#include "Student.h"

using namespace std;

int main(){
  CourseMap map = CourseMap();
  requirements r = requirements();
  map.load("input.txt");
  Student s = Student(r, map);
  s.calculateSchedule("scheduleInput.txt");
  return 0;
}
