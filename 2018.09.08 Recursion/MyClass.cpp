#include "MyClass.h"

MyClass::MyClass()
{
}

MyClass::~MyClass()
{
}

int
MyClass::GetFiboNumbers(int one, int two) { // output 10 first numbers of the Fibonacci series

	if (2 == one + two)
		cout << "1 1 ";
	if (89 == one + two)
		return 89;
	else {
		two = one + two;
		one = two - one;
		cout << two << ' ';
		return this->GetFiboNumbers(one, two);	
	}
}

int
MyClass::GetNumbersFall(int num, int b) { // get the numbers from numbers to 

	if (b == num) {
		cout << num << endl;
		return b;
	}
	else {
		cout << num << endl;
		return this->GetNumbersFall(num - 1, b);
	}
}

int
MyClass::GetNumbersGrowth(int num, int size) { // get the numbers

	if (num <= size) {
		cout << num << endl;
		return this->GetNumbersGrowth(num + 1, size);
	}
	else
		return 0;
}

int
MyClass::GetDigits(int num) { // get the digits of the number

	if (10 <= num) {
		cout << num % this->GetDigits(num *0.1) << ' ';
		return num * 10;
	}
	else {
		cout << num << ' ';
		return num * 10;
	}
}

int
MyClass::GetInvertedDigits(int num) { // get the inverted digits of the number

	if (0 == num) {
		cout << '\n';
		return 0;
	}
	else {
		cout << num % 10 << ' ';
		return this->GetInvertedDigits(num / 10);
	}
}

void
MyClass::OutputNumber(int a, int b) {// Output of all numbers from A to B inclusive, in ascending order, if A <B, or in descending order otherwise

	if (a > b)
		this->GetNumbersFall(a, b);
	else
		this->GetNumbersGrowth(a, b);

}