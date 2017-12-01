
#ifndef COURSES_H
#define COURSES_H

using namespace std;

class courses {
	public:
		courses();

	private:
		string name;
		char courseType;
		courses* prereqs;
};

#endif
