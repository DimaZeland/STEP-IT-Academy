#pragma once

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

class MyClass {
public:
    MyClass();

    ~MyClass();

    int Factorial(int); // return the factorial of the number
    int GetNumbersFall(int); // get the numbers from number to 1
    int GetNumbersGrowth(int, int); // get the numbers from 1 to number
    int GetSumDigits(int); // return the sum of the digits of the number
};

