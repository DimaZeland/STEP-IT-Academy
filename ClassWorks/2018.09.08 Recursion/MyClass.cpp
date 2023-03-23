#include "MyClass.h"

MyClass::MyClass() {
}

MyClass::~MyClass() {
}

int
MyClass::Factorial(int num) {// return the factorial of the number

    if (1 > num)
        return 0;
    else if (1 == num)
        return 1;
    else
        return num * Factorial(num - 1);
}

int
MyClass::GetNumbersFall(int num) { // get the numbers from numbers to 

    if (1 == num) {
        cout << num << endl;
        return 1;
    } else {
        cout << num << endl;
        return this->GetNumbersFall(num - 1);
    }
}

int
MyClass::GetNumbersGrowth(int num, int size) { // get the numbers

    if (num <= size) {
        cout << num << endl;
        return this->GetNumbersGrowth(num + 1, size);
    } else
        return 0;
}

int
MyClass::GetSumDigits(int num) { // return the sum of the digits of the number

    if (0 == num)
        return 0;
    else
        return num % 10 + this->GetSumDigits(num / 10);
}
