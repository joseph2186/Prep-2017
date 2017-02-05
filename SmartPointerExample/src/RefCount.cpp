/*
 * RefCount.cpp
 *
 *  Created on: Jan 19, 2017
 *      Author: Joseph
 */

#include <iostream>
#include "RefCount.h"

using namespace std;

RefCount::RefCount() {
	cout << "reference constructor" << endl;

}

RefCount::~RefCount() {
	cout << "reference destructor" << endl;
}

void RefCount::AddRef()
{
	this->count++;
	cout << "increment reference, ref count = " << this->count << endl;
}

int RefCount::Release()
{
	cout << "decrement reference" << endl;
	return --(this->count);
}
