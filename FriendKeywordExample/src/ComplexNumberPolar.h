/*
 * ComplexNumberPolar.h
 *
 *  Created on: Jan 6, 2017
 *      Author: Joseph
 */

#ifndef COMPLEXNUMBERPOLAR_H_
#define COMPLEXNUMBERPOLAR_H_

#include <iostream>

using namespace std;
//Forward declaration
class ComplexNumber;

class InvalidComplexNumber{
private:
	string error_msg;
public:
	InvalidComplexNumber(string error):error_msg(error){

	}
	~InvalidComplexNumber(){

	}
};

class ComplexNumberPolar {
private:
	double radial;
	double angular;
public:
	ComplexNumberPolar();
	ComplexNumberPolar(double radial, double angular);
	ComplexNumberPolar(ComplexNumberPolar& cmp);

	double getRadialPart();
	void setRadialPart(double radial);

	double getAngularPart();
	void setAngularPart(double angular);

	void print();
	virtual ~ComplexNumberPolar();
	friend ComplexNumber addComplexNumbers(ComplexNumber& cartesian, ComplexNumberPolar& polar);
};

#endif /* COMPLEXNUMBERPOLAR_H_ */
