#include<iostream>
#include "Int.h"

Int::Int(const Int& obj) { // explicit deep copy-constructor
	this->its_my_value = obj.its_my_value;
}

Int&
Int::operator=(const Int& obj) {
	if (this == &obj)
		return *this;
	this->its_my_value = obj.its_my_value;
	return *this;
}
Int
Int::operator+(const Int& obj) {
	Int sum;
	sum.its_my_value = this->its_my_value + obj.its_my_value;
	return sum;
}
Int
Int::operator-(const Int& obj) {
	Int dif;
	dif.its_my_value = this->its_my_value - obj.its_my_value;
	return dif;
}
Int
Int::operator*(const Int& obj) {
	Int mult;
	mult.its_my_value = this->its_my_value * obj.its_my_value;
	return mult;
}
Int
Int::operator/(const Int& obj) {
	Int div;
	div.its_my_value = obj.its_my_value ? this->its_my_value / obj.its_my_value : throw 0;
	return div;
}
Int&
Int::operator*=(const Int& obj) {
	*this = obj.its_my_value ? this->its_my_value * obj.its_my_value : 0;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Int& obj) {
	os << obj.its_my_value;
	return os;
}
