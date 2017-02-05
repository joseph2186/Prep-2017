/*
 * RefCount.h
 *
 *  Created on: Jan 19, 2017
 *      Author: Joseph
 */

#ifndef REFCOUNT_H_
#define REFCOUNT_H_

class RefCount {
private:
	int count;
public:
	RefCount();
	virtual ~RefCount();
	void AddRef();
	int Release();
};

#endif /* REFCOUNT_H_ */
