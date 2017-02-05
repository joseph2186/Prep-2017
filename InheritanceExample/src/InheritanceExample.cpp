//============================================================================
// Name        : InheritanceExample.cpp
// Author      : JKB
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "ShapeVirtual.h"
#include <typeinfo>
#include <exception>

using namespace std;

void SignalHandler(int signal)
{
    cout << "Signal" << signal << endl;
    throw "!Access Violation!";
}

int main() {
#if 0
	cout << "start" << endl;
	cout << "instantiate c1" << endl;
	Circle c1("some shape", 3.5);
	cout << "instantitate c2" << endl;
	Circle c2("some other shape", 10.2);
	cout << "assign c1=c1" << endl;
	c1=c2;
	cout << "instantiate c3" << endl;
	Circle c3 = c1;
	cout << "end" << endl;

	Circle circle1(1);
	Shape& shape1 = circle1;
	Circle *circle2 = new Circle(2);
	shape1.print();
	circle2->print();
	delete circle2;
	Shape shape2("Rectangle");
	shape2.print();
	Circle circle3(3);
	shape2 = circle3;
	shape2.print();
#endif
	typedef void (*SignalHandlerPointer)(int);

	SignalHandlerPointer previousHandler;
	previousHandler = signal(SIGSEGV , SignalHandler);
	Shape * shape = new Shape("square");
	Shape * shape2 = new Circle(4);

	//This wont work - downcast from circle* to shape* but which does not point to a circle obj
	//RTTI fails here - no compilation error - null ptr exception
	try{
		Circle * circle = dynamic_cast<Circle*>(shape);
		circle->print();
	}
	catch(...){
		cout << "Null ptr exception" << endl;
		return 0;
	}

	//This will work - Downcasting circle * to a shape *
	Circle * circle2 = dynamic_cast<Circle*>(shape2);

	circle2->print();
	cout << "typeid : " << typeid(*circle2).name() << endl;
	return 0;
}
