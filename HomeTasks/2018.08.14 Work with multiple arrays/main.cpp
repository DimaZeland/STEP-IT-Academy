#include "Work.h"

// macro error message to re-enable the file
#ifndef IOSTREAM
#define IOSTREAM
#include<iostream>
#endif

int main() {
    setlocale(LC_ALL, "RUS");
    srand(time(0));
    Work *pObject = new Work;

    pObject->SetValue(); // determining the values of array elements arr [] [] by random numbers from 0 to 9
    cout << "\narr[" << pObject->Get_itsFirst() << "][" << pObject->Get_itsSecond() << "]:\n";
    pObject->ShowValue(); // output of array elements arr [][] to the console
    cout << "\nThe last line, in which there are only paired elements (0 if not): " <<
         pObject->FindLastPairLine(); // return the last line number only with paired elements
    pObject->FindDownElements(); // search for all rows whose elements go down
    pObject->SwapStroka(); // reversal of rows with max and min elements
    cout << "\nAfter changing the rows with the maximum and minimum value, the array looks like this:\n";
    pObject->ShowValue();

    delete pObject;
    pObject = NULL;

    system("pause");
    return 0;
}