//============================================================================
// Name        : CastAndExceptions.cpp
// Author      : JKB
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Student.h"
using namespace std;

int main() {
	const Student studentOne("Joe", 1);

	//this will be a compiler error
	//error: invalid initialization of reference of type 'Student&' from expression of type 'const Student'
	//Student& studentTwo = studentOne;

	//this will work
	Student& studentThree = const_cast<Student&>(studentOne);

	cout << "name: " << studentThree.getName() << " id: " << studentThree.getId() << endl;
	return 0;
}
