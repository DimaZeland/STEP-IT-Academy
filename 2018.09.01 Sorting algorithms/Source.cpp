#include<ctime>
#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void
FillArray(T itsArr[], const int size) { // fill an array
	for (int i = 0; i < size; ++i)
		itsArr[i] = rand() % 10;
}

template<typename T>
void
OutPutArray(T itsArr[], const int size) { // output the array
	for (int i = 0; i < size; ++i)
		cout << i << ' ' << itsArr[i] << '\n';
}

template<typename T>
void
SelectingSort(bool type, int method, const int size, T itsArr[]) { // selection of the sorting method
	void(*pTypeSort)(T[], const int, bool); //create a pointer to a function of the template class
	switch (method) {
	case 1:
		pTypeSort = SortBubble;
		break;
	case 2:
		pTypeSort = SortInsert;
		break;
	case 3:
		pTypeSort = SortSelection;
		break;
	default:
		cout << "\nInvalid sorting type specified!\n";
		return;
	}
	pTypeSort(itsArr, size, type); // call the sorting method through a pointer to a function of the template class
}

template<typename T>
void
SortBubble(T itsArr[], const int size, bool flag) { // sorting by a bubble method of an array of a given type
	if (flag) { // Sort Growth
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size - 1; ++j)
				if (itsArr[j] < itsArr[j + 1])
					std::swap(itsArr[j], itsArr[j + 1]);
	}
	else // Sort Fall
		for (int i = 0; i < size; ++i)
			for (int j = 0; j < size - 1; ++j)
				if (itsArr[j] > itsArr[j + 1])
					std::swap(itsArr[j], itsArr[j + 1]);
}

template<typename T>
void
SortInsert(T itsArr[], const int size, bool flag) { // sorting by an insert method of an array of a given type
	if (flag) // Sort Growth
		for (int i = 0; i < size; ++i)
			for (int j = i; j > 0 && itsArr[j - 1] < itsArr[j]; --j)
				std::swap(itsArr[j - 1], itsArr[j]);
	else // Sort Fall
		for (int i = 0; i < size; ++i)
			for (int j = i; j > 0 && itsArr[j - 1] > itsArr[j]; --j)
				std::swap(itsArr[j - 1], itsArr[j]);
}

template<typename T>
void
SortSelection(T itsArr[], const int size, bool flag) { // sorting by a selection method of an array of a given type
	if (flag) { // Sort Growth
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (itsArr[i] > itsArr[j])
					std::swap(itsArr[i], itsArr[j]);
	}
	else // Sort Fall
		for (int i = 0; i < size; ++i)
			for (int j = i + 1; j < size; ++j)
				if (itsArr[i] < itsArr[j])
					std::swap(itsArr[i], itsArr[j]);
}

template<typename T>
void
SetRating(T itsArr[], const int size) { // sorting by a selection method of an array of a given type
	cout << "\nEnter 10 scholl's ratings: \n";
	for (int i = 0; i < size; ++i)
		cin >> itsArr[i];
}

void DiscoverScholarship(int Arr[], int size) {
	float average = 0;
	for (int i = 0; i < size; ++i)
		average += Arr[i];
	average /= size;
	average >= 10.7 ? cout << "The scholarship comes out, because the average score is higher than 10.7" :
		cout << "The scholarship does not come out, since the average score is less than 10.7";
}

void RandomArr(int Arr1[], int size) {
	for (int i = 0; i < size; ++i)
		for (int j = 0; j < size - 1; ++j)
			if (rand() % 2)
				std::swap(Arr1[j], Arr1[j + 1]);
	}

template<typename T>
void
SortTask3(T itsArr[], const int size1, int size2) { // Task 3
	for (int i = 0; i < size1; ++i)// Sort Fall
		for (int j = i; j > 0 && itsArr[j - 1] < itsArr[j]; --j)
			std::swap(itsArr[j - 1], itsArr[j]);
	for (int i = size1+1; i < size2; ++i)	//Sort Growth
			for (int j = i; j > size1+1 && itsArr[j - 1] > itsArr[j]; --j)
				std::swap(itsArr[j - 1], itsArr[j]);
}


int main() {
	int sortMethod = 0;
	bool sortType = true;
	const int size = 10;
	int Arr[size] = {};
	srand(time(0));

	//FillArray<int>(Arr, size);
	//cout << "\nArray[" << size << "] after filling the values of the elements:\n";
	//OutPutArray<int>(Arr, size);
	//cout << "Task 1\nPlease, select a sort method: 1 - Bubble, 2 - Insert, 3 - Select: ";
	//cin >> sortMethod;
	//cout << "Please, select a sort type : 0 - descending, 1 - ascending: ";
	//cin >> sortType;
	//SelectingSort<int>(sortType, sortMethod, size, Arr);
	//cout << "\nArray[" << 10 << "] after Sort:\n";
	//OutPutArray<int>(Arr, size);

	//// Task 2
	//cout << "\nTask 2\n";
	//SetRating(Arr, size);
	//cout << "\nSelect the desired command :\n1 - evaluation output\n2 - retake of the exam\n3 - does the scholarship go out\nq - quit\n";
	//int choise = 0;
	//int index = 0, value = 0;
	//while (cin >> choise) {
	//	switch (choise) {
	//	case 1:
	//		cout << "\nArray[" << size << "] of school's ratings:\n";
	//		OutPutArray<int>(Arr, size);
	//		break;
	//	case 2:
	//		cout << "To retake the exam, enter the element index and the new value of the evaluation";
	//		cin >> index >> value;
	//		Arr[index] = value;
	//		break;
	//	case 3:
	//		DiscoverScholarship(Arr, size);
	//		break;
	//	default:
	//		cout << "\nBad input!\n";
	//		break;
	//	}
	//	cout << "\nSelect the desired command :\n1 - evaluation output\n2 - retake of the exam\n3 - does the scholarship go out\nq - quit\n";
	//}
	// Task 3
	cout << "\nTask 3\n";
	int Arr1[20] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 };
	RandomArr(Arr1, 20);
	cout << "\nArray[" << 20 << "] after RandomSort:\n";
	OutPutArray<int>(Arr1, 20);
	int random = rand() % 21;
	cout << "\nnew random number is: " << random << endl;
	for (int i = 0; i < 20; ++i)
		if (random == Arr1[i]) {
			cout << "\nPositions of random number is " << i << endl;
			SortTask3(Arr1, i, 20);
			break;
		}
	cout << "\nArray[" << 20 << "] after Sort:\n";
	OutPutArray<int>(Arr1, 20);



	//создать случайное число из того же диапазона и найти
	//	позицию этого случайного числа в массиве;
	system("pause");
}


