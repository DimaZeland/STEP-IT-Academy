#pragma once

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class MyClass
{
public:
	MyClass();
	~MyClass();
	int GetFiboNumbers(int = 1, int = 1); // output 10 first numbers of the Fibonacci series
	int GetNumbersFall(int, int); // get the numbers from number to 1
	int GetNumbersGrowth(int, int); // get the numbers from 1 to number
	int GetDigits(int); // get the digits of the number
	int GetInvertedDigits(int); // get the inverted digits of the number
	void OutputNumber(int, int); // Output of all numbers from A to B inclusive, in ascending order, if A <B, or in descending order otherwise
};

