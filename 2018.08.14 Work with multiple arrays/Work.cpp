#include "Work.h"

void
Work::FindDownElements(const ushort& itsFirst, const ushort& itsSecond)const { // search for all rows whose elements go down
																			   //Preconditions: passing function arguments as references to save memory
	std::vector<ushort> arr1;
	bool* flag = new bool(true);

	for (ushort i = 0; i < itsFirst; ++i) {
		*flag = true;
		for (ushort j = 0; j < itsSecond - 1; ++j)
			if (arr[i][j] <= arr[i][j + 1]) {
				*flag = false;
				break;
			}
		if (*flag)
			arr1.push_back(i);
	}

	delete flag;
	flag = NULL;

	if (arr1.empty())
		cout << "\nIn an array arr[" << itsFirst << "][" << itsSecond << "] there are no rows in which all the elements go down.\n";
	else {
		cout << "\nIn an array arr[" << itsFirst << "][" << itsSecond << "] on the decline all the elements of the following lines: ";
		for (int x : arr1) // pass through the values of the vector element
			cout << x << ", ";
		cout << "\b\b.\n"; // return two characters back to delete "," and replace with ".\n"
	}
}

ushort
Work::FindLastPairLine(const ushort& itsFirst, const ushort& itsSecond)const { // return the last line number only with paired elements
																			   // Preconditions: passing function arguments as references to save memory
																			   // Postconditions: return the line number on success or 0 in case of failure
	bool* pPair = new bool(true);
	ushort* pStroka = new ushort(0);
	for (ushort i = 0; i < itsFirst; ++i) {
		*pPair = true;
		for (ushort j = 0; j < itsSecond; ++j)
			if (arr[i][j] % 2 != 0) {
				*pPair = false;
				break;
			}
		if (*pPair)
			*pStroka = i;
	}
	delete pPair;
	pPair = NULL;
	return *pStroka;
}

void
Work::SetValue(const ushort& itsFirst, const ushort& itsSecond) { // determining the values of array elements arr [][] by random numbers from 0 to 9
																  // Preconditions: passing function arguments as references to save memory
	for (int i = 0; i < itsFirst; ++i)
		for (int j = 0; j < itsSecond; ++j)
			arr[i][j] = rand() % 10;
}

void
Work::ShowValue(const ushort& itsFirst, const ushort& itsSecond) const { // output of array elements arr [][] to the console
																		 // Preconditions: passing function arguments as references to save memory
	for (int i = 0; i < itsFirst; ++i) {
		for (int j = 0; j < itsSecond; ++j)
			cout << arr[i][j] << ' ';
		cout << '\n';
	}
}

void
Work::SwapStroka(const ushort& itsFirst, const ushort& itsSecond) { // reversal of rows with max and min elements
	ushort* pMax = new ushort(0);
	short* pMin = new short(10);
	ushort* pMaxStroka = new ushort(0);
	ushort* pMinStroka = new ushort(0);

	for (ushort i = 0; i < itsFirst; ++i)
		for (ushort j = 0; j < itsSecond; ++j) {
			if (arr[i][j] > *pMax) {
				*pMax = arr[i][j];
				*pMaxStroka = i;
			}
			if (arr[i][j] < *pMin) {
				*pMin = arr[i][j];
				*pMinStroka = i;
			}
		}

	if (*pMin != 10 && *pMax != 0)
		for (ushort i = 0; i < itsFirst; ++i)
			std::swap(arr[*pMaxStroka][i], arr[*pMinStroka][i]);

	delete pMax, pMin, pMaxStroka, pMinStroka;
	pMax = NULL, pMin = NULL, pMaxStroka = NULL, pMinStroka = NULL;
}