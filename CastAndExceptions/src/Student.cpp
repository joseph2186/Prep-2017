/*
 * Student.cpp
 *
 *  Created on: Jan 22, 2017
 *      Author: Joseph
 */

#include <iostream>
#include "Student.h"

using namespace std;

Student::Student():name(NULL), id(0) {
	cout << "Student no-arg constructor" << endl;

}

Student::Student(string name, int id):name(name), id(id) {
	cout << "Student arg constructor" << endl;

}

Student::Student(const Student& rhs):name(rhs.name), id(rhs.id) {
	cout << "Student copy constructor" << endl;

}

string Student::getName(){
	return this->name;
}

int Student::getId(){
	return this->id;
}

Student::~Student() {
	cout << "Student destructor" << endl;
}

