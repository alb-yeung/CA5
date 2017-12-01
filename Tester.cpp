#include "CourseMap.h"

using namespace std;

int main(){
  CourseMap map = CourseMap();
  map.load("input.txt");
  map.read();
  return 0;
}
