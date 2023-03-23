#include "MyClass.h"
#include<iostream>
//#include<cstring>


int main() {
    srand(time(0));
    MyClass *pObj = new MyClass;

    //pObj->SortArray(); // division of the array into two (with the pair elements and unpaired ones)
    //pObj->CharacterCount(); // character count by type
    pObj->EditingWord(); // // editing a sentence
    system("pause");
    return 0;
}