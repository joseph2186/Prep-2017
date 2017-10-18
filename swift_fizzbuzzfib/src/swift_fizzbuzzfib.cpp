//============================================================================
// Name        : swift_fizzbuzzfib.cpp
// Author      : Joe
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>

using namespace std;

/* isPrime(n) - Takes a integer as arg and returns true if it is a prime number, else false
 * Return type - bool
 */
bool isPrime(int n)
{
	if (n <= 1) return false;
	if (n <= 3) return true;

	if(n%2 == 0 || n%3 == 0) return false;

	for(int i=5; i*i<=n; i+= 6)
		if(n%i == 0 || n%(i+2) == 0)
			return false;

	return true;
}

/* fibTest(n) - Takes a integer as arg and generates that many fibonacci numbers
 * This is a test version of the function used only for verification
 * Return type - void
 */
void fibTest(int n)
{
	int a=0, b=1, c=0;
	for(int i=0 ; i<n ; i++)
	{
		if(a == 0)
			cout << a << endl;
		else if (a%15 == 0)
			cout << "value = " << a << " (/ by 15)FizzBuzz" << endl;
		else if (a%3 == 0)
			cout << "value = " << a << " (/ by 3)Buzz" << endl;
		else if (a%5 == 0)
			cout << "value = " << a << " (/ by 5)Fizz" << endl;
		else if (isPrime(a))
			cout << "value = " << a << " (prime)BuzzFizz" << endl;
		else
			cout << a << endl;

		c=a+b;
		a=b;
		b=c;
	}
}

/* fib(n) - Takes a integer as arg and generates that many fibonacci numbers
 * Return type - void
 */
void fib(int n)
{
	int a=0, b=1, c=0;
	for(int i=0 ; i<n ; i++)
	{
		if(a == 0)
			cout << a << endl;
		else if (a%15 == 0)
			cout << "FizzBuzz" << endl;
		else if (a%3 == 0)
			cout << "Buzz" << endl;
		else if (a%5 == 0)
			cout << "Fizz" << endl;
		else if (isPrime(a))
			cout << "BuzzFizz" << endl;
		else
			cout << a << endl;

		c=a+b;
		a=b;
		b=c;
	}
}

int main() {
	int n = 0;
	int input;
	cout << "Fizz Buzz Fib" << endl; // prints Fizz Buzz Fib

	while(true)
	{
		cout << " Enter 1 for testing with a random value of n or 2 for user input or 3 to exit: ";
		cin >> input;
		if(input == 1)
		{
			n = rand() % 100;
			cout << "random value generated for n is " << n << endl;
			fibTest(n);
		}
		else if (input == 2)
		{
			cout << "enter value of n:";
			cin >> n;
			fib(n);
			cout << endl;
		}
		else if (input == 3)
		{
			break;
		}
		else
		{
			cout << "wrong input, try again" << endl;
		}
	}

	cout << "exit!" << endl;
	return 0;
}
