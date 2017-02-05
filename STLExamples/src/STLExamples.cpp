//============================================================================
// Name        : STLExamples.cpp
// Author      : JKB
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <algorithm>

using namespace std;

template<class t>
void stack_func(stack<t> stack_var)
{
	int input;
	while(1){
		cout << "1. Push" << endl << "2. Pop" << endl << "3. Top" << endl;
		cout << "Input: ";
		cin >> input;
		switch(input)
		{
				case 1:
				{
					t value;
					cout << "Value: ";
					cin >> value;
					stack_var.push(value);
					break;
				}
				case 2:
				{
					stack_var.pop();
					break;
				}
				case 3:
				{
					cout << "top = " << stack_var.top() << endl;
					break;
				}
				default:
					return;
		}
	}
}

template<typename t>
void vector_func(vector<t> vec)
{
	int input;
	typename vector<t>::iterator itr;
	while(1){
		cout << "1. Insert" << endl << "2. Erase" << endl << "3. Display at" << endl << "4. Print" << endl;
		cout << "Input: ";
		cin >> input;
		switch(input)
		{
				case 1:
				{
					t value;
					cout << "Value: ";
					cin >> value;
					vec.push_back(value);
					break;
				}
				case 2:
				{
					t value;
					cout << "Value to be erased:";
					cin >> value;
					itr = find(vec.begin(), vec.end(), value);
					vec.erase(itr);
					break;
				}
				case 3:
				{
					int index;
					cout << "Index: ";
					cin >> index;
					cout << vec.at(index);
					break;
				}
				case 4:
				{
					for ( itr = vec.begin() ; itr != vec.end() ; itr++)
					{
						cout << *itr << endl;
					}
					break;
				}
				default:
					return;
		}
	}
}

template<class t>
void map_func(multimap<int, t> map)
{
	int input;
	typename multimap<int, t>::iterator itr;
	while(1){
		cout << "1. Insert" << endl << "2. Erase" << endl << "3. Find" << endl << "4. Print" << endl;
		cout << "Input: ";
		cin >> input;
		switch(input)
		{
				case 1:
				{
					t value;
					int key;
					cout << "Key:";
					cin >> key;
					cout << "Value: ";
					cin >> value;
					map.insert(pair<int, t>(key, value));
					break;
				}
				case 2:
				{
					int key;
					cout << "key to be erased:";
					cin >> key;
					map.erase(key);
					break;
				}
				case 3:
				{
					int index;
					cout << "key: ";
					cin >> index;
					itr = map.find(index);
					cout << " value: " << itr->second << endl;
					break;
				}
				case 4:
				{
					for ( itr = map.begin() ; itr != map.end() ; itr++)
					{
						cout << "key = " << itr->first << "value = " << itr->second << endl;
					}
					break;
				}
				default:
					return;
		}
	}
}

int main() {
	int input;
	int choice;
	cout << "Types:" << endl << "1. int" << endl << "2. string" << endl;
	cin >> input;
	cout << "structure: " << endl << "1. stack" << endl << "2. vector" << endl << "3. map" << endl;
	cin >> choice;
	switch(choice)
	{
	case 1:
		if (input == 1)
		{
			stack<int> stack_var;
			stack_func(stack_var);
		}
		else
		{
			stack<string> stack_var;
			stack_func(stack_var);
		}
		break;
	case 2:
		if (input == 1)
		{
			vector<int> vec;
			vector_func(vec);
		}
		else
		{
			vector<string> vec;
			vector_func(vec);
		}
		break;
	case 3:
		if (input == 1)
		{
			multimap<int, int> map_var;
			map_func(map_var);
		}
		else
		{
			multimap<int, string> map_var;
			map_func(map_var);
		}
		break;
	default:
		return 0;
	}

	return 0;
}
