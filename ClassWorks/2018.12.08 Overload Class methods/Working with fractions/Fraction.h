#pragma once
class Fraction
{

	int num = 0, denom = 1;
public:
	int getNum() const
	{
		return num;
	}
	int getDenom() const // inline
	{
		return denom;
	}
	void setNum(int num)
	{
		this->num = num;
	}
	void setDenom(int denom) // -3/4 + -1/8
	{
		if (denom == 0)
		{
			denom = 1;
		}
		else if (denom < 0)
		{
			num *= -1;
			denom *= -1;
		}
		this->denom = denom;
	}
	Fraction() = default;
	Fraction(int num, int denom = 1);//  Fraction fr(3, -2)  -3/2       2 or 1
	void print() const;

	Fraction operator + (const Fraction& two) const; // this (1 operand) 2 ()
	bool operator == (const Fraction& two) const; // this    two

	Fraction & operator ++ ();// unary   prefix
	Fraction  operator ++ (int);// postfix
	~Fraction();
	Fraction operator-(const Fraction& two) const;
	Fraction operator*(const Fraction& two) const;
	Fraction operator/(const Fraction& two) const;
	Fraction& operator-();
	bool operator>(const Fraction& two) const;
	bool operator<(const Fraction& two) const;
	void reduce();
};
// global function
// method of class
//operator + ()
// -b
