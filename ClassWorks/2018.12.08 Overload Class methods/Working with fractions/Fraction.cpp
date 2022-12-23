#include <iostream>
using namespace std;
#include "Fraction.h"



//Fraction::Fraction():num(0), denom(1)
//{
//}

Fraction::Fraction(int num, int denom)// 
{
	setNum(num);
	setDenom(denom);
}

void Fraction::print() const
{
	cout << num << "/" << denom << endl;
}

Fraction Fraction::operator+(const Fraction & two) const
{
	int num = this->num * two.denom + this->denom * two.num;
	int denom = this->denom * two.denom;
	Fraction result(num, denom);
	//result.reduce();
	return  result;
}

bool Fraction::operator==(const Fraction & two) const
{
	return this->num * two.denom == this->denom * two.num;
}


Fraction & Fraction::operator++() // *this
{
	this->num += denom;
	return *this;
}

Fraction Fraction::operator++(int)
{
	//Fraction old ( *this); // ctor copy
	Fraction old(num, denom);
	++(*this);
	//num += denom;

	return old;
}

Fraction::~Fraction()
{
}

Fraction
Fraction::operator-(const Fraction& two) const {
	Fraction result(*this);

	result.num *= two.denom;
	result.denom *= two.denom;
	result.num -= (two.num * denom);
	return result;
}

Fraction
Fraction::operator*(const Fraction& two) const {
	return Fraction(num * two.num, denom * two.denom);
}

Fraction
Fraction::operator/(const Fraction& two) const {
	return Fraction(num * two.denom, denom * two.num);
}

Fraction&
Fraction::operator-() {
	num *= -1;
	return *this;
}
bool
Fraction::operator>(const Fraction& two) const {
	Fraction res1(*this), res2(two);
	res1.num *= two.denom;
	/*res1.denom = two.denom;
	res2.num *= denom;*/
	res2.denom = denom;
	if (res1.num > res2.num)
		return true;
	else
		return false;
}

bool
Fraction::operator<(const Fraction& two) const {
	Fraction res1(*this), res2(two);
	res1.num *= two.denom;
	/*res1.denom = two.denom;
	res2.num *= denom;*/
	res2.denom = denom;
	if (res1.num < res2.num)
		return true;
	else
		return false;
}

void
Fraction::reduce() {
	int rest = 0;
	int Num = num, Denom = denom;

	if (Denom >= Num)
	do{
		rest = Denom % Num;
		if (0 == Num % rest)
			break;
	} while (0 != rest);

	num /= rest;
	denom /= rest;

	std::cout << num  << '/'<< denom << '\n';
}
