#include "Student.h"

using namespace std;

Student::Student(){
  taken = classTable();
  totalCredits = 0;
  totalC = 0;
  totalH = 0;
  totalF = 0;
  errorMessage = "Bad plan. Here's why:\n";
  table = CourseMap();
  prereqsGraph = requirements();
  
}

Student::Student(requirements r, CourseMap c){
  taken = classTable();
  prereqsGraph = r;
  table = c;
  totalCredits = 0;
  totalC = 0;
  totalH = 0;
  totalF = 0;
  errorMessage = "Bad plan. Here's why:\n";
}

/*
  time is 0 if spring, 1 if fall
  Returns 0 if all prereqs are taken and course is given at that time
  Returns 1 if prereqs are not fulfilled
  Returns 2 if not offered at that time
*/
int Student::checkClass(string courseName, int time){
  /*
    If not offered at time return 2
    Search up graph location in courseMap
       -> traverse all of prereqs
           ->for each prereq check if taken/being taken
	        ->if not return 1
    else return 0
   */
  if (time != (table[courseName]).offered && (table[courseName]).offered != 2) return 2;
  
  return 0;
}

vector<string> Student::reorderSchedule(string inputFile){
  ifstream f(inputFile);
  vector<string> temp;
  string data;
  string year1;
  string year2;
  vector<string>::iterator it;
  for (getline (f, data, '\n'); data != ""; getline(f, data, '\n')){
    for (it = temp.begin(); it < temp.end(); it++){
      year1 = data[1]+data[2]+data[3]+data[4];
      year2 = (*it)[1]+(*it)[2]+(*it)[3]+(*it)[4];
      if (year1 > year2){
	continue;
      }
      if (year1 == year2){
	if (data[0] == 'S'){
	  temp.insert(it, data);
	}
	else{
	  it++;
	  temp.insert(it, data);
	}
      }
      if (year1 < year2){
	temp.insert(it, data);
      }
      break;
    }
    if (it == temp.end()) temp.push_back(data);
  }
  return temp;
}

void Student::calculateSchedule(string inputFile){
  ifstream f(inputFile);
  if (f.fail()){
    cout << "Schedule file not found" << endl;
    return;
  }

  vector<string> ordered = reorderSchedule(inputFile);
  
  string data;
  stringstream stream;
  int semester; // 0 if spring 1 if fall
  int temp;
  /*
    for each line store time and add to Student's taken table
    go through each course one by one and checkClass on every one
       -> add to errorMessage if needed
    at end if all credits add up change errorMessage to "Good plan. Get to work."
   */
  for (vector<string>::iterator it = ordered.begin(); it < ordered.end(); it++){
    cout << *it << endl;
    stream = stringstream(*it);
    getline(stream, data, ' ');
    if (data[0] == 'S') semester = 0;
    else semester = 1;

    getline(stream, data, ' ');
    temp = checkClass(data, semester);
    if (temp){
      if (temp == 1) errorMessage += "Not all of the prereqs for " + data + " are completed.\n";
      if (temp == 2) errorMessage += data + " is not offered at that time.\n";
    }

    getline(stream, data, ' ');
    temp = checkClass(data, semester);
    if (temp){
      if (temp == 1) errorMessage += "Not all of the prereqs for " + data + " are completed.\n";
      if (temp == 2) errorMessage += data + " is not offered at that time.\n";
    }

    getline(stream, data, ' ');
    temp = checkClass(data, semester);
    if (temp){
      if (temp == 1) errorMessage += "Not all of the prereqs for " + data + " are completed.\n";
      if (temp == 2) errorMessage += data + " is not offered at that time.\n";
    }

    getline(stream, data, ' ');
    temp = checkClass(data, semester);
    if (temp){
      if (temp == 1) errorMessage += "Not all of the prereqs for " + data + " are completed.\n";
      if (temp == 2) errorMessage += data + " is not offered at that time.\n";
    }
  }
  
  cout << errorMessage << endl;
}
