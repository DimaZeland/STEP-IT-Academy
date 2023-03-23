#pragma once

#include<ctime>
#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;

class MyClass {
public:
    MyClass() {}

    ~MyClass() {}

    // class methods
    void CharacterCount() const; // character count by type
    void EditingWord() const; // editing a sentence
    void SortArray() const; // division of the array into two (with the pair elements and unpaired ones)
private:
};

