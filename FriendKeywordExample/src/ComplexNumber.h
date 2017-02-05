/*
 * ComplexNumber.h
 *
 *  Created on: Jan 6, 2017
 *      Author: Joseph
 */

#ifndef COMPLEXNUMBER_H_
#define COMPLEXNUMBER_H_

//Forward declaration
class ComplexNumberPolar;

class ComplexNumber {
private:
	double real;
	double imaginary;
	const static float PI;
public:
	ComplexNumber();
	ComplexNumber(double real, double imaginary);
	ComplexNumber(const ComplexNumber& cmp);
	explicit ComplexNumber(ComplexNumberPolar& cmpp);

	double getRealPart();
	void setRealPart(double real);

	double getImaginaryPart();
	void setImaginaryPart(double imaginary);

	ComplexNumber& operator+=(const ComplexNumber& rhs);
	ComplexNumber& operator++();
	const ComplexNumber operator++(int);

	void print();
	virtual ~ComplexNumber();

	friend ComplexNumber addComplexNumbers(ComplexNumber& cartesian, ComplexNumberPolar& polar);
};

#endif /* COMPLEXNUMBER_H_ */
