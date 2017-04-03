//============================================================================
// Name        : PrimitiveTypes.cpp
// Author      : Joe
// Version     :
// Copyright   : Your copyright notice
// Description : Promitive types - consider only 8bit integers
//============================================================================

#include <iostream>
#include <stdio.h>
#include <bitset>
#include <stdlib.h>

using namespace std;

//5.1 - return 1 if number of bits set is odd, else 0 (O(log(n)) solution)
short bitParity(long x)
{
	x ^= x >> 32;
	x ^= x >> 16;
	x ^= x >> 8;
	x ^= x >> 4;
	x ^= x >> 2;

	return x & 0x1;
}

//5.2 - swap bits - O(1) solution
long swapBits(long x, int i, int j)
{
	long y = x;

	//swap only if the bit are not the same
	if(((y >> i) & 1) != ((y >> j) & 1))
	{
		unsigned long bitmask = (1L << i) | (1L << j);
		y ^= bitmask;
	}
	return y;
}

//5.3  - reverse bits - using precomputed lookup
//Computation with a 2 bit lookup - can be extended to 4 bit and a 64 bit word
long reverseBits(long x)
{
	long precomputed_reverse[4];
	precomputed_reverse[0] = 0;
	precomputed_reverse[1] = 2;
	precomputed_reverse[2] = 1;
	precomputed_reverse[3] = 3;

	const int kWord = 2;
	const int kBitMask = 0x3;

	return  precomputed_reverse[x & kBitMask] << (3*kWord) |
			precomputed_reverse[(x >> (kWord)) & kBitMask] << (2*kWord) |
			precomputed_reverse[(x >> (2*kWord)) & kBitMask] << (kWord)|
			precomputed_reverse[x >> (3*kWord)];
}

//5.7 - x^y without using pow operator
//x^y = x^(y/2)^2 if y is even else = x^(y/2)^2*x
double pow(int x, int y)
{
	double result = 1.0;
	long long power = y;

	if(y < 0)
	{
		power = -power;
		x = 1.0/x;
	}

	while(power)
	{
		//even or odd condition
		if (power & 1)
		{
			result *= x;
		}
		x *= x;
		power >>= 1;
	}

	return result;
}

//5.8 - Reverse digits
long reverseDigits(int x)
{
	long result = 0;
	int x_remaining = abs(x);

	while(x_remaining){
		result = (result*10) + (x_remaining%10);
		x_remaining /= 10;
	}
	return result;
}

int main() {
	int input;
	cout << "enter a number:";
	cin >> input;
	cout << "Bit parity of " << input << " is " << bitParity(input) << endl;

	cout << "input in binary: " << bitset<8>(input) << endl;
	int i,j;
	cout << "enter values for i and j" << endl;
	cout << "i:";
	cin >> i;
	cout << endl << "j:";
	cin >> j;

	int output = swapBits(input, i, j);
	cout << "Output after swapping: " << bitset<8>(output) << endl;

	cout << "reverse of " << bitset<8>(input) << " is " << bitset<8>(reverseBits(input)) << endl;

	int power;
	cout << "enter a power to which " << input << " has to be raised" << endl;
	cin >> power;

	cout << input << "to the power " << power << " is " << pow(input, power) << endl;

	cout << "reversing the digits of " << input << " result is " << reverseDigits(input) << endl;
	return 0;
}
