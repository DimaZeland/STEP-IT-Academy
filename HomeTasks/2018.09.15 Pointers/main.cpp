#include <iostream>

using namespace std;

int& Task1(int[], int);
bool Task2(int&, int&, float&);
void Task3(int[], int);
void Task4(int[], int, int[], int, int[], int);

void ShowArray(int[], int);

int main() {
	constexpr int size = 10;
	int arr[size]{ 1, 2, 5, 4, 5, 6, 7, 8, 9, 8 };
	
	// Task 1
	cout << "Task1\n";
	ShowArray(arr, size);
	Task1(arr, size);
	
	// Task 2
	cout << "\nTask1\n";
	int a = 15, b = 2;
	float c = 0;
	Task2(a, b, c) ? cout << "oparation " << a << '/' << b << " is valid\n" << a << '/' << b << '=' << c << '\n' :
		cout << "oparation " << a << '/' << b << " is invalid.To zero can not be divided.\n";
	
	// Task 3
	cout << "\nTask3\n";
	ShowArray(arr, size);
	Task3(arr, size);
	ShowArray(arr, size);
	
	//Task4
	cout << "\nTask4\n";
	const int size1 = 10, size2 = 15, size3 = size1 + size2;
	int Arr1[size1]{ 1, 3, 5, 7, 9, 11, 13, 15, 17, 19 };
	int Arr2[size2]{ 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 21, 22, 23, 24, 25 };
	int Arr3[size3] = {};

	ShowArray(Arr1, size1);
	ShowArray(Arr2, size2);
	ShowArray(Arr3, size3);

	Task4(Arr1, size1, Arr2, size2, Arr3, size3);
	ShowArray(Arr3, size3);

	system("pause");
	return 0;
}


int& Task1(int arr[], int size) {
	int* min = &arr[0];
	for (int i = 1; i < size; ++i)
		if (arr[i] < *min)
			min = &arr[i];
	cout << "\nmin element is " << *min << '\n';
	*min *= 2;
	return *min;
}

bool Task2(int& divided, int& divider, float& result) {
	if (0 == divider)
		return false;
	result = divided / float(divider);
	return true;
}

void Task3(int arr[], int size) {
	for (int i = 0; i < size; i += 2)
		swap(*(arr + i), *(arr + i + 1));
}

void Task4(int arr1[], int size1, int arr2[], int size2, int arr3[], int size3) {
	for (int i = 0; i < size1; ++i) // fill the array arr3[0-size1-1] with the elements of arr1[]
		arr3[i] = arr1[i];

	for (int i = 0, k = size1; i < size3; ++i, ++k) // fill the array arr3[size1-size3] with the elements of arr2[]
		arr3[k] = arr2[i];

	for (int i = 0; i < size3; ++i) // sorting arr3[] by bubble method in ascending order
		for (int m = 0; m < size3 - i - 1; ++m)
			if (arr3[m] > arr3[m + 1])
				std::swap(arr3[m], arr3[m + 1]);
}

void ShowArray(int arr[], int size) {
	cout << "\nArr[" << size << "]:\n";
	for (int i = 0; i < size; ++i)
		cout << arr[i] << ' ';
	cout << '\n';
}