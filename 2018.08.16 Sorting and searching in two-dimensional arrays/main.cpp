#include "MyClass.h"

#ifndef USING
#define USING
using std::cout;
using std::endl;
#endif

int main() {
	setlocale(LC_ALL, "RUS");
	srand(time(0));
	MyClass *pObject = new MyClass;
	
	pObject->SetArr(); // determining the values of array elements Arr [] [] by random numbers from 0 to 9
	cout << "\nArr[" << pObject->Get_itsFirst() << "][" << pObject->Get_itsSecond() << "]:\n";
	pObject->ShowArr(); // outputting array elements Arr [][] to the console
	
	// Task ¹1
	pObject->SortGrowArr(); // Sorting the elements of each row of the array Arr [][] ascending
	cout << "\nArr[" << pObject->Get_itsFirst() << "][" << pObject->Get_itsSecond() << "] after MyClass::SortGrawArr():\n";
	pObject->ShowArr();
	
	// Task ¹ 2
	pObject->ArgDiagonal(); // output to the console of the arithmetic mean of the diagonals of the array element array Arr [][]

	// Task ¹ 3
	// search for the value of the element of the array, which is repeated the largest number of times
	cout << "\nIn an array Arr[][] the largest number of times a value " << pObject->FindNumber() << ".\n"; 

	// re-populate an array with random values
	pObject->SetArr(); // determining the values of array elements Arr [][] by random numbers from 0 to 9
	cout << "\nRe-fill the values of array elements Arr[][] random numbers from 0 to 9.\n";
	cout << "\nArr[" << pObject->Get_itsFirst() << "][" << pObject->Get_itsSecond() << "]:\n";
	pObject->ShowArr(); // outputting array elements Arr [][] to the console
	
	// Task ¹4
	pObject->FindSumTwoMax(); // output to the console of the sum of the two largest elements
	
	// Task ¹5
	pObject->FindLastMax(); // output to the console of the last local extremum
	
	delete pObject;
	pObject = NULL;
	
	system("pause");
	return 0;
}