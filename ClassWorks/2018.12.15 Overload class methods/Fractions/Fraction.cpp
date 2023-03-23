#include <iostream>

using namespace std;

#include "Fraction.h"
#include <cmath>

Fraction::Fraction(int num, int denom)// 
{
    setNum(num);
    setDenom(denom);
}

void Fraction::print() const {
    cout << num << "/" << denom << endl;
}

Fraction Fraction::operator+(const Fraction &two) const {
    int num = this->num * two.denom + this->denom * two.num;
    int denom = this->denom * two.denom;
    Fraction result(num, denom);
    result.reduce();
    return result;
}

bool Fraction::operator==(const Fraction &two) const {
    return this->num * two.denom == this->denom * two.num;
}


Fraction &Fraction::operator++() // *this
{
    this->num += denom;
    this->reduce();
    return *this;
}

Fraction Fraction::operator++(int) // postfix
{
    //Fraction old ( *this); // ctor copy
    Fraction old(num, denom);
    ++(*this);
    //num += denom;
    old.reduce();
    return old;
}

Fraction &Fraction::operator--() // *this
{
    this->num -= denom;
    this->reduce();
    return *this;
}

Fraction Fraction::operator--(int) {
    //Fraction old ( *this); // ctor copy
    Fraction old(num, denom);
    --(*this);
    this->reduce();
    //num += denom;
    old.reduce();
    return old;
}

Fraction
Fraction::operator-(const Fraction &two) const {
    Fraction result(*this);
    result.num *= two.denom;
    result.denom *= two.denom;
    result.num -= (two.num * denom);
    result.reduce();
    return result;
}

Fraction
Fraction::operator*(const Fraction &two) const {
    Fraction one(num * two.num, denom * two.denom);
    one.reduce();
    return one;
}

Fraction
Fraction::operator/(const Fraction &two) const {
    Fraction one(num * two.denom, denom * two.num);
    one.reduce();
    return one;
}

Fraction &
Fraction::operator-() {
    num *= -1;
    this->reduce();
    return *this;
}

bool
Fraction::operator>(const Fraction &two) const {
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
Fraction::operator<(const Fraction &two) const {
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

bool
Fraction::operator!=(const Fraction &two) const {
    if (operator==(two))
        return false;
    return true;
}

void
Fraction::reduce() {

    int max = abs(num) < abs(denom) ? abs(num) : abs(denom);
    for (; max; --max)
        if (0 == num % max and 0 == denom % max) {
            num /= max;
            denom /= max;
        }
    setNum(num);
    setDenom(denom);
}

Fraction
Fraction::operator+(const int number) const {
    Fraction one(num + (denom * number), denom);
    one.reduce();
    return one;
}

Fraction
Fraction::operator*(const int number) const {
    Fraction one(num * number, denom);
    one.reduce();
    return one;
}

std::ostream &operator<<(std::ostream &os, const Fraction &obj) {
    return os << obj.num << '/' << obj.denom;
}

int
Fraction::operator[](int ind) {
    switch (ind) {
        case 1:
            return num;
            break;
        case 2:
            return denom;
            break;
        default:
            cerr << std::endl << ind << " Error index!\n";
            return INT_MIN;
            break;
    }
}

int
Fraction::operator[](const std::string &str) {
    if ("num" == str)
        return num;
    else if ("denom" == str)
        return denom;
    else
        return INT_MIN;
}

void
Fraction::operator()(int Num, int Denom) {
    num = Num;
    denom = Denom ? Denom : 1;
}
