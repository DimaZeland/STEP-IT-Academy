#include <iostream>
#include "Car.h"

int main(){
	using std::cin;
	using std::cout;
	using std::endl;
	cout << "Enter the number of cars: ";
	int carSize, index = 0;
	cin >> carSize;
	Car* pCars = new Car[carSize];

	for (int i = 0; i < carSize; ++i) { // filling the array with data
		cout << "\nCar # " << i + 1 << ":\n";
		pCars[i].Fill();
		++index;
	}

	cout << "\nOutput cars:\n";
	for (int i = 0; i < carSize; ++i) { // output elements
		cout << i + 1 << ":" << pCars[i];
	}

	cout << "\nSort cars ascending year:\n";
	for (int i = 0; i < carSize; ++i) // sorting by bubble method in ascending order
		for (int m = 0; m < carSize - i - 1; ++m)
			if (pCars[m] > pCars[m + 1])
				std::swap(pCars[m], pCars[m+1]);
	
	cout << "\nOutput cars:\n";
	for (int i = 0; i < carSize; ++i) { // output elements
		cout << i + 1 << ":" << pCars[i];
	}

	cout << "\nDo you want to edit the car? Enter <Y,N>: ";
	char ch = 'N';
	cin >> ch;
	if('Y' == ch or 'y' == ch){
	cout << "\nSelect the index of car<1-" << index << "> to edit the parameters: ";
	int editIndex;
	cin >> editIndex;
	pCars[editIndex - 1].Edit(); // edit the parameters of car
	
	cout << "\nOutput cars:\n";
	for (int i = 0; i < carSize; ++i) // output elements
		cout << i + 1 << ":" << pCars[i];
	}

	cout << "\nDo you want to add the car? Enter <Y,N>: ";
	cin >> ch;
	if ('Y' == ch or 'y' == ch) {
		Car oneElse;
		oneElse.Fill();
		++index; // new size of the array of cars
		Car* pCars2 = new Car[index]; // copy the elements of old array
		for (int i = 0; i < carSize; ++i)
			pCars2[i] = pCars[i];
		pCars2[index-1] = oneElse; // push new element
		std::swap(pCars, pCars2); // swap arrays pointers
		++carSize; // new size of Array pCars 
		delete[] pCars2; // delete old array
		pCars2 = nullptr;

		cout << "\nOutput cars:\n";
		for (int i = 0; i < carSize; ++i) { // output elements
			cout << i + 1 << ":" << pCars[i];
		}
	}

	cout << "\nDo you want to delete the car? Enter <Y,N>: ";
	cin >> ch;
	if ('Y' == ch or 'y' == ch) {
		cout << "\nOutput cars:\n";
		for (int i = 0; i < carSize; ++i) // output elements
			cout << i + 1 << ":" << pCars[i];
		
		cout << "\nSelect the index of car<1-" << carSize << "> to delete the element: ";
			int editIndex;
			cin >> editIndex;
			--editIndex; // edit the index to array element index interface
		--index; // new size of the array of cars
		Car* pCars3 = new Car[index]; // copy the elements of old array
		for (int i = 0, j = 0; i < carSize; ++i){
			if (editIndex == i) // skip item to delete
				continue;
			pCars3[j] = pCars[i];
			++j;
		}
		std::swap(pCars, pCars3); // swap arrays pointers
		--carSize; // new size of Array pCars 
		delete[] pCars3; // delete old array
		pCars3 = nullptr;

		cout << "\nOutput cars:\n";
		for (int i = 0; i < carSize; ++i) // output elements
			cout << i + 1 << ":" << pCars[i];
	}
	
	delete[] pCars;
	pCars = nullptr;

	system("pause");
	return 0;
}