/*
 * ComplexNumberPolar.cpp
 *
 *  Created on: Jan 6, 2017
 *      Author: Joseph
 */

#include <iostream>
#include "ComplexNumberPolar.h"

using namespace std;

ComplexNumberPolar::ComplexNumberPolar() {
	cout << "Inside the no-arg constructor of polar complex numbers" << endl;

}

ComplexNumberPolar::ComplexNumberPolar(double radial, double angular): radial(radial), angular(angular)
{
	cout << "Inside the constructor of polar complex numbers" << endl;
	if (radial < 0)
	{
		throw InvalidComplexNumber("radial cant be negative");
	}
}

ComplexNumberPolar::ComplexNumberPolar(ComplexNumberPolar& cmp): radial(cmp.radial), angular(cmp.angular)
{
	cout << "Inside the copy constructor of polar complex numbers" << endl;
}

double ComplexNumberPolar::getRadialPart()
{
	return this->radial;
}

void ComplexNumberPolar::setRadialPart(double radial)
{
	this->radial = radial;
}

double ComplexNumberPolar::getAngularPart()
{
	return this->angular;
}

void ComplexNumberPolar::setAngularPart(double angular)
{
	this->angular = angular;
}

void ComplexNumberPolar::print()
{
	cout << "Angular = " << this->angular << "Radial = " << this->radial << endl;
}

ComplexNumberPolar::~ComplexNumberPolar() {
	cout << "Inside the destructor of complex polar" << endl;
}

