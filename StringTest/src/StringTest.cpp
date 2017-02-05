//============================================================================
// Name        : StringTest.cpp
// Author      : JKB
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
	string firstName;
	string lastName;
	string fullName;
	string address;
	string nickName;
	//declare inside the class
	static int numObjsCreated;
public:

    Person()
    {
    	cout << "Inside the no arg constructor" << endl;
    	numObjsCreated++;
    	cout << "num objs created = " << numObjsCreated << endl;
    }

    Person(const Person& person):
    	firstName(person.firstName),
    	lastName(person.lastName),
    	fullName(person.fullName),
    	address(person.address),
    	nickName(person.nickName)
    {
    	cout << "Inside the copy constructor" << endl;
    }
    ~Person()
    {
    	cout << "Inside the destructor" << endl;
    }

    static void getNumObjs()
    {
    	cout << " num objects = " << numObjsCreated << endl;
    }

    void getFirstName()
	{
		cout << "input your first name" << endl;
		getline(cin, this->firstName);
	}

    void getLastName()
    {
    	cout << "input your last name" << endl;
    	getline(cin, this->lastName);
    }

    void getNickName()
    {
    	cout << "input your nick name" << endl;
    	getline(cin, this->nickName);
    }

    void getAddress()
    {
    	cout << "enter address and end it with ~" << endl;
    	getline(cin, this->address, '~');
    }

    void setFullName()
    {
    	this->fullName = this->firstName + this->lastName;
    }

    void findNickName()
    {
    	int pos = this->fullName.find(this->firstName);
    	cout << "Position of first name: " << pos << endl;
    	pos = this->fullName.find(this->lastName);
    	cout << "Position of last name: " << pos << endl;
    	pos = this->fullName.find(this->nickName);
    	cout << "Position of nick name: " << pos << endl;
    }

    void print()
    {
    	cout << "first name:" << this->firstName << endl;
    	cout << "last name:" << this->lastName << endl;
    	cout << "nick name:" << this->nickName << endl;
    	cout << "full name:" << this->fullName << endl;
    	cout << "address:" << this->address << endl;
    }
};

//A static variable has to always be defined outside the class - Not sure what to do for private
//variable - Maybe friend
int Person::numObjsCreated = 0;

int main() {
	Person Joe;
	Person Radhika;

	Person::getNumObjs();
	Joe.getFirstName();
	Joe.getLastName();
	Joe.getNickName();
	Joe.setFullName();
	Joe.getAddress();
	Joe.print();

	Joe.findNickName();

	Radhika.getFirstName();
	Radhika.getLastName();
	Radhika.getNickName();
	Radhika.setFullName();
	Radhika.getAddress();
	Radhika.print();

	Joe = Radhika;

	Joe.print();
	return 0;
}
