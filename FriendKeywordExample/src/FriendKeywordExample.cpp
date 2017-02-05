//============================================================================
// Name        : FriendKeywordExample.cpp
// Author      : JKB
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>
#include "ComplexNumber.h"
#include "ComplexNumberPolar.h"
using namespace std;

ComplexNumber addComplexNumbers(ComplexNumber& cartesian, ComplexNumberPolar& polar)
{
	double realPart = polar.angular * cos(polar.radial * ComplexNumber::PI/180);
	double imgPart = polar.angular * sin(polar.radial * ComplexNumber::PI/180);

	ComplexNumber result(cartesian.real+realPart, cartesian.imaginary+imgPart);
	return result;
}

int main() {
#if 0
	ComplexNumber cmp(5,3);
	ComplexNumber cmp2(2,4);
	ComplexNumberPolar polar(10,3);

	cmp.print();
	polar.print();

	cmp2.print();
	cmp2 += cmp;

	cmp2.print();

	ComplexNumber cmp3(cmp++);
	cmp3.print();
	cmp.print();
	ComplexNumber cmp4 = ++cmp;
	cmp4.print();
	cmp.print();

	addComplexNumbers(cmp,polar).print();
#endif

	try{
		ComplexNumberPolar p1(7.5,45);

	    ComplexNumber c1 = static_cast<ComplexNumber>(p1);

	    ComplexNumber c2 = ComplexNumber(p1);

	    c1.print();
	    c2.print();

	    return 0;
	}
	catch(InvalidComplexNumber e){
		cout << "error" << endl;
	}

	return 0;
}
