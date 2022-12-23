#include<iostream>
#include<ctime>

using namespace std;

int main() {

	srand(time(0));

	int size = 10;
	int* pArr = new int[size];

	for (int i = 0; i < size; ++i) // initialization pArr[]
		*(pArr + i) = rand() % 11;

	cout << "pArr[10]:\n"; // show the value of pArr[]
	for (int i = 0; i < size; ++i)
		cout << *(pArr + i);

	int number = 0;
	cout << "\nEnter number:";
	cin >> number;
	cout << "Enter 1 to delete or enter 2 to pushback new element:";
	int choise;
	cin >> choise;
	switch (choise) {
	case 1: {
		--size;
		for (int i = number; i < size; ++i) // redefinition the value of the pArr's[] elements
			*(pArr + i) = *(pArr + i + 1);

		int* pArr1 = new int[size]; // 
		for (int i = 0; i < size; ++i)
			*(pArr1 + i) = *(pArr + i);

		delete[] pArr;
		pArr = NULL;

		cout << "pArr[9]:\n"; // show the value of the pArr1[]
		for (int i = 0; i < size; ++i)
			cout << *(pArr1 + i);
		cout << '\n';

		delete[] pArr1;
		pArr1 = NULL;
		break;
	}
	case 2: {
		++size;
		int* pArr1 = new int[size]; // 
		for (int i = 0; i < size - 1; ++i)
			*(pArr1 + i) = *(pArr + i);
		*(pArr1 + size-1) = number;
		cout << "*(pArr1 + size-1) " << *(pArr1 + size-1) << endl;
		delete[] pArr;
		pArr = NULL;

		cout << "pArr[11]:\n"; // show the value of the pArr1[]
		for (int i = 0; i < size; ++i)
			cout << *(pArr1 + i);
		cout << '\n';

		delete[] pArr1;
		pArr1 = NULL;
		break;
	}
	default:
		cout << "\nWrong choise!\n";
		break;
	}

	// Testing capabilities of pointers
	int* a = new int;
	*a = 4;
	int* b = a;
	++(*b);
	cout << *a << endl;
	delete[]a;
	cout << *b << endl;

	//Testing two-dimensional array in dynamic memory
	int** arr = new int*[5]; // allocate memory for an array of rows
	for (int i = 0; i < 5; ++i) // allocation of memory for cells of each individual line
		arr[i] = new int[20];
	// garbage collection
	for (int i = 0; i < 5; ++i) // clearing the memory for cells of each individual line
		delete arr[i];
	delete[]  arr; // clearing the memory for an array of rows

	system("pause");
	return 0;
}
