/*
 * SmartPointer.h
 *
 *  Created on: Jan 19, 2017
 *      Author: Joseph
 */

#ifndef SMARTPOINTER_H_
#define SMARTPOINTER_H_

#include "RefCount.h"

using namespace std;

template<class T> class SmartPointer {
private:
	T* pData;
	RefCount* reference;

public:
	SmartPointer():pData(0), reference(0)
    {
		cout << " smart pointer constructor with no arg" << endl;
		reference = new RefCount();
		reference->AddRef();
	}

	SmartPointer(T* pData):pData(pData), reference(0)
	{
		cout << "smart pointer constructor with arg" << endl;
		reference = new RefCount();
		reference->AddRef();
	}

	SmartPointer(SmartPointer<T>& sp):pData(sp.pData), reference(sp.reference)
	{
		cout << "smart pointer copy constructor" << endl;
		reference->AddRef();
	}

	virtual ~SmartPointer(){
		int refCount = reference->Release();
		cout << "Smart pointer destructor, ref count = " << refCount << endl;

		if (refCount == 0)
		{
			delete pData;
			delete reference;
			cout << "Ref count is 0, delete the ptr" << endl;
		}
	}

	SmartPointer<T>& operator=(const SmartPointer<T>& sp){
		if (this!=sp)
		{
			if(this->reference->Release() == 0)
			{
				delete this->pData;
				delete this->reference;
			}

			this->pData = sp.pData;
			this->reference = sp.reference;
			this->reference->AddRef();
		}

		return *this;
	}

	T& operator*(){
		return *this->pData;
	}

	T* operator->(){
		return this->pData;
	}
};

#endif /* SMARTPOINTER_H_ */
