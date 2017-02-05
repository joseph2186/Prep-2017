/*
 * PairTemplate.h
 *
 *  Created on: Jan 19, 2017
 *      Author: Joseph
 */

#ifndef PAIRTEMPLATE_H_
#define PAIRTEMPLATE_H_

#include <iostream>

using namespace std;

template <class T>
class PairTemplate {
private:
	T first;
	T second;
public:
	PairTemplate(){
		cout << "constructor with no args" << endl;
	}

	PairTemplate(T first, T second):first(first), second(second){
		cout << "constructor with args" << endl;
	}

	PairTemplate(PairTemplate<T>& rhs):first(rhs.first), second(rhs.second){
		cout << "copy constructor" << endl;
	}

	virtual ~PairTemplate(){
		cout << "destructor" << endl;
	}

	T getFirst()
	{
		return this->first;
	}

	T getSecond()
	{
		return this->second;
	}
};

#endif /* PAIRTEMPLATE_H_ */
