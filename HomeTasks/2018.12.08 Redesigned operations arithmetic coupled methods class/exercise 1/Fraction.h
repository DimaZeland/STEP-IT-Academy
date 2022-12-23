#pragma once
class Fraction {
private:
	int num = 0, denom = 1;
public:
	// Ctor
	Fraction() = default;
	Fraction(int num, int denom = 1);//  Fraction fr(3, -2)  -3/2       2 or 1
	~Fraction() {}
	inline int getNum() const {	return num;}
	inline int getDenom() const {return denom;}
	inline void setNum(int num)	{
		this->num = num;
		if (!num) // 0 == num
			denom = 1;
	}

	inline void setDenom(int denom) {
		if (denom == 0)	{
			denom = 1;
		}
		else if (denom < 0)	{
			num *= -1;
			denom *= -1;
		}
		else
			this->denom = denom;
	}
	void print() const;

	Fraction operator + (const Fraction& two) const; // this (1 operand) 2 ()
	bool operator == (const Fraction& two) const; // this    two
	Fraction & operator ++ ();// unary   prefix
	Fraction  operator ++ (int);// postfix
	Fraction & operator -- ();// unary   prefix
	Fraction  operator -- (int);// postfix
	Fraction operator-(const Fraction& two) const;
	Fraction operator*(const Fraction& two) const;
	Fraction operator/(const Fraction& two) const;
	Fraction& operator-();
	bool operator>(const Fraction& two) const;
	bool operator<(const Fraction& two) const;
	bool operator!=(const Fraction& two) const;
	Fraction operator+(const int number)const;
	Fraction operator*(const int number)const;
	void reduce();
	friend std::ostream& operator<<(std::ostream& os, const Fraction&);
};