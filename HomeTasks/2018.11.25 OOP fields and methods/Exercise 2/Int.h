#pragma once
#include<iostream>


class Int {
private:
	int its_my_value = 0;
public:
	Int(int value = 0) { its_my_value = value; }
	~Int() {};
	Int(const Int& obj); // explicit deep copy-constructor
	Int& operator=(const Int& obj);
	Int operator+(const Int& obj);
	Int operator-(const Int& obj);
	Int operator*(const Int& obj);
	Int operator/(const Int& obj);
	Int& operator*=(const Int& obj);
	friend std::ostream& operator<<(std::ostream& os, const Int& obj);
};