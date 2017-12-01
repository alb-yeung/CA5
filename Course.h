#include <stdlib.h>
#include <string>
#include <iostream>

using namespace std;

class Course{
 public:
  string courseName;
  int credits; // ranging from 1 to 4
  int offered; // 0 is spring 1 is fall 2 is both
  string tags;
  /*change pointer type later*/
  void * graphLocation;

  Course();
};
