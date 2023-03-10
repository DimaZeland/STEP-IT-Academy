#include <iostream>
#include "Fraction.h"
using namespace std;
int main()
{
	Fraction a(1, 2), b(2, 4);
	//cout << a << " + " << b << " = ";
	//cout << a + b << endl;
	//cout << a << " + 1 = " << a + 1 << endl;
	//cout << a << " - " << b << " = " << a - b << endl;
	//cout << a << " * " << b << " = " << a * b << endl;
	//cout << a << " * 3 = " << a * 3 << endl;
	//cout << a << " / " << b << " = " << a / b << endl;
	cout << a << "++ = ";
	++a;
	cout << a << endl;
	cout << "--" << b << " = " << (--b) << endl;
	cout << a << " == " << b << " ? " << boolalpha << (a == b) << endl;
	cout << a << " != " << b << " ? " << boolalpha << (a != b) << endl;
	cout << a << " > " << b << " ? " << boolalpha << (a > b) << endl;
	cout << a << " < " << b << " ? " << boolalpha << (a < b) << endl;
	a.reduce(), b.reduce();
	cout << "\nfractions reduction: " << a << ", " << b << ".\n";

	system("pause");
	return 0;
}
