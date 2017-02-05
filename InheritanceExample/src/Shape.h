/*
 * Shape.h
 *
 *  Created on: Jan 6, 2017
 *      Author: Joseph
 */

#ifndef SHAPE_H_
#define SHAPE_H_

#include <string>

using namespace std;

class Shape {
private:
	string shapeType;
public:
	Shape();
	Shape(string shapeType);
	Shape(const Shape& shape);
	Shape& operator=(const Shape& rhs);
	virtual ~Shape();
	virtual void print();
};

#endif /* SHAPE_H_ */
