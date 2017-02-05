/*
 * Circle.h
 *
 *  Created on: Jan 6, 2017
 *      Author: Joseph
 */

#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Shape.h"

class Circle: public Shape {
private:
	float radius;
public:
	Circle();
	Circle(float r);
	Circle(const Circle& c);
	Circle& operator=(const Circle& rhs);
	virtual ~Circle();
	void print();
};

#endif /* CIRCLE_H_ */
