/*
 * Student.h
 *
 *  Created on: Jan 22, 2017
 *      Author: Joseph
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

using namespace std;

class Student {
private:
	string name;
	int id;

public:
	Student();
	Student(string name, int id);
	Student(const Student& rhs);
	string getName();
	int getId();
	virtual ~Student();
};

#endif /* STUDENT_H_ */
