/*
 * Circle.cpp
 *
 *  Created on: Jan 6, 2017
 *      Author: Joseph
 */

#include <iostream>
#include "Circle.h"

using namespace std;
Circle::Circle()
{
	cout << "Inside the no arg constructor of circle" << endl;
}

Circle::Circle(float r):Shape("circle"), radius(r)
{
	cout << "Inside the constructor of circle, radius = " << r << endl;
}

Circle::Circle(const Circle& c):radius(c.radius)
{
	cout << "Inside the copy constructor of circle, radius = "<< c.radius << endl;
}

Circle& Circle::operator=(const Circle& rhs)
{
	if (this != &rhs)
	{
		Shape::operator =(rhs);
		this->radius = rhs.radius;
	}
	return *this;
}

Circle::~Circle()
{
	cout << "Inside the destructor of circle" << endl;
}

void Circle::print()
{
	cout << "i am a circle of radius " << this->radius << endl;
}
