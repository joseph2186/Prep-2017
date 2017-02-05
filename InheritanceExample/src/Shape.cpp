/*
 * Shape.cpp
 *
 *  Created on: Jan 6, 2017
 *      Author: Joseph
 */

#include <iostream>
#include "Shape.h"

using namespace std;
Shape::Shape()
{
	cout << "Inside the no arg constructor of shape" << endl;
}

Shape::Shape(string shapeType):shapeType(shapeType)
{
	cout << "Inside the constructor of shape, shapeType = "<< shapeType << endl;
}

Shape::Shape(const Shape& shape):shapeType(shape.shapeType)
{
	cout << "Inside the copy constructor of shape, shapeType = "<< shape.shapeType << endl;
}

Shape& Shape::operator=(const Shape& rhs)
{
	// Do this only if the references are not the same
	if(this != &rhs)
	{
		this->shapeType = rhs.shapeType;
	}
	return *this;
}

Shape::~Shape()
{
	cout << "Inside the destructor of shape" << endl;
}

void Shape::print()
{
	cout << "I am a shape, shapeType = "<< this->shapeType << endl;
}

