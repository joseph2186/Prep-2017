/*
 * ShapeVirtual.h
 *
 *  Created on: Jan 6, 2017
 *      Author: Joseph
 */

#ifndef SHAPEVIRTUAL_H_
#define SHAPEVIRTUAL_H_

class ShapeVirtual {
public:
	ShapeVirtual();
	virtual ~ShapeVirtual();
	virtual void print() = 0;
};

#endif /* SHAPEVIRTUAL_H_ */
