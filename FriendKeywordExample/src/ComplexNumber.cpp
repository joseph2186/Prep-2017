/*
 * ComplexNumber.cpp
 *
 *  Created on: Jan 6, 2017
 *      Author: Joseph
 */

#include <iostream>
#include <cmath>
#include "ComplexNumberpolar.h"
#include "ComplexNumber.h"

using namespace std;

const float ComplexNumber::PI = 3.142;

ComplexNumber::ComplexNumber() {
	cout << "Inside the no-arg constructor of complex number" << endl;

}

ComplexNumber::ComplexNumber(double real, double imaginary) : real(real), imaginary(imaginary)
{
	cout << "Inside the constructor of complex numbers" << endl;
}

ComplexNumber::ComplexNumber(const ComplexNumber& cmp): real(cmp.real), imaginary(cmp.imaginary)
{
	cout << "Inside the copy constructor of complex numbers" << endl;
}

ComplexNumber::ComplexNumber(ComplexNumberPolar& cmpp){
	this->real = cmpp.getAngularPart() * cos(cmpp.getRadialPart() * ComplexNumber::PI/180);
	this->imaginary = cmpp.getAngularPart() * sin(cmpp.getRadialPart() * ComplexNumber::PI/180);
}

double ComplexNumber::getRealPart()
{
	return this->real;
}

void ComplexNumber::setRealPart(double real)
{
	this->real = real;
}

double ComplexNumber::getImaginaryPart()
{
	return this->imaginary;
}

void ComplexNumber::setImaginaryPart(double imaginary)
{
	this->imaginary = imaginary;
}

//Operator overloading
ComplexNumber& ComplexNumber::operator +=(const ComplexNumber& rhs)
{
	this->real += rhs.real;
	this->imaginary += rhs.imaginary;

	//Return value should be reference. Hence *this is returned
	return *this;
}

ComplexNumber& ComplexNumber::operator ++()
{
	this->real += 1;
	this->imaginary += 1;

	//Return value should be reference. Hence *this is returned
	return *this;
}
const ComplexNumber ComplexNumber::operator ++(int)
{
	ComplexNumber ret(this->real, this->imaginary);
	this->real += 1;
	this->imaginary += 1;

	//Return value should be reference. Hence *this is returned
	return ret;
}
void ComplexNumber::print()
{
	cout << "real = " << this->real << "imaginary = " << this->imaginary << endl;
}

ComplexNumber::~ComplexNumber() {
	cout << "Inside the destructor of complex numbers" << endl;
}
