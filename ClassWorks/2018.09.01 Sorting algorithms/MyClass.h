#pragma once

#include<ctime>
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

template <typename T> 
void SortBubbleT(T Arr[], int size, bool flag) { // sorting by a bubble method of an array of a given type
	if (flag) { // Sort Growth
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size - 1; ++j)
				if (Arr[j] < Arr[j + 1]) {
					std::swap(Arr[j], Arr[j + 1]);
					//	++itsAteration;
				}
	}
	else { // Sort Fall
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size - 1; ++j)
				if (Arr[j] > Arr[j + 1]) {
					std::swap(Arr[j], Arr[j + 1]);
					//++::itsAteration;
				}
	}
}

class MyClass
{
public:
	// constructor & destructor
	MyClass() : size(10), itsAteration (0) {}
	~MyClass() {}
	// class methods
	void BubbleSortFall(int); // sort an array in ascending order
	void BubbleSortGrowth(int); // sort an array in ascending order 
	inline const int GetSize()const { return this->size; } // return private data "size"
	inline auto GetArr()const { return Arr; } // return the pointer of Arr[0] 
	inline int GetAteration(void) const { return this->itsAteration;  } 
	void FillArray(int); // fill an array
	int FindIndex(const int*, int&, int) const; // array element index search
	void MixFunction();  // several functions in one (min, max element (index)
	void SetitsAteration(void) { itsAteration = 0; } // resetting the value of the private variable
	void OutPutArray(int) const; // output the array 
	void SortInsertFall(int); // sorting the array by inserting growth
	void SortInsertGrowth(int); // sorting the array by inserting fall
	void SortSelectionFall(int); // sorting the array by selection it (Fall)
	void SortSelectionGrowth(int); // sorting the array by selection it (Growth)
	int Arr1[100];
private:
	static const int b = 10;
	const int size;
	int Arr[b];
	int Arr2[b];
	int Arr3[b];
	int itsAteration;

};

