#include<iostream>
#include<ctime>
#include <iomanip>
#include<string>

using std::cout;
using std::endl;
using std::setw;

class Array {
public:
	Array() {} // Constructor of a class object
	~Array() {} // Destroyer of a class object
	void RandompArr(bool); // populating an array with random numbers
	void OutputpArr(bool) const; // array output
	void Find2Elements()const; // Output max and before the max element of each line
	void FindGrowStroka()const; // search for the number of rows where all numbers go in ascending order
	void FindFallingColumns()const; // Search for all columns where all numbers go down
	inline int Get_size() const { return size; } // return value of private member variable size1
	void ChangeMaxMin(); // Change the maximum and minimum elements in each column
	void MatrixSide(); // changing the values of the sides

private:
	int pArr[5][5]; // two-dimensional array declaration
	const int size = 5, size1 = 5;
};

void Array::RandompArr(bool method = 0) { // filling the array with random numbers (method == true) or manually (method == false)
	int *value = new int(0);

	if (method) { // function execution depending on the value of the argument (if method == true), then fill the array manually
		cout << "\nEnter the values of the elements of the array pArr[5][5]: ";
		for (int i = 0; i < 5; ++i)
			for (int k = 0; k < 5; ++k) {
				std::cin >> *value;
				pArr[i][k] = *value;
			}
	}

	else // if the argument is not set or false, then fill the array with random values
		for (int i = 0; i < 5; ++i)
			for (int k = 0; k < 5; ++k)
				pArr[i][k] = rand() % 11;

	delete value;
	value = NULL;
	return;
}

void Array::OutputpArr(bool type = 0) const { // array output
	//Preconditions: type? output of string elements by one line through a space: output of string elements, - each with a new line indicating the index
	for (int i = 0; i < 5; ++i) {
		if (type)
			cout << "[" << i << "]";
		for (int k = 0; k < 5; ++k)
			type ? cout << setw(3) << pArr[i][k] : cout << "\n[" << i << "][" << k << "]\t" << pArr[i][k];
		cout << endl;
	}
	return;
}

void Array::Find2Elements()const { // Output max and before the max element of each line
	int arr[5][2] = {};
	int * buffer = new int(0);
	for (int i = 0; i < 5; ++i)
		for (int k = 0; k < 5; ++k) {
			if (pArr[i][k] >= arr[i][0]) { // The condition for finding the maximum value taking into account the displacement of the previous maximum by the maximum value
				*buffer = arr[i][0];
				arr[i][0] = pArr[i][k];
				if (*buffer > arr[i][1])
					arr[i][1] = *buffer;
			}
			else if (pArr[i][k] > arr[i][1]) // condition for searching before the maximum value
				arr[i][1] = pArr[i][k];
		}
	delete buffer;
	buffer = NULL;
	for (int i = 0; i < 5; ++i)
		cout << "[" << i << "]: max " << arr[i][0] << ", before the maximum value " << arr[i][1] << endl;
	return;
}

void Array::FindGrowStroka()const { // search for the number of rows where all numbers go in ascending order
	int * score = new int(0);
	for (int i = 0; i < 5; ++i)
		for (int k = 0; k < 4; ++k) {
			if (pArr[i][k + 1] <= pArr[i][k])
				break;
			if (k == 3)
				++ * score;
		}
	cout << "\nIn an array pArr[5][5] " << *score << " line, where the values of all the elements go in ascending order\n";
	delete score;
	score = NULL;
	return;
}

void Array::FindFallingColumns()const { // Search for all columns where all numbers go down
	std::string * score = new std::string("");
	for (int k = 0; k < 5; ++k)
		for (int i = this->Get_size() - 1; i > 0; --i) {
			if (pArr[i][k] > pArr[i - 1][k])
				break;
			if (i == 1) {
				*score += ' ';
				*score += (k + 48); // in the string, the values are written with symbols on the indexes of the ANSI table,
									//so the symbol of the number 0 has an index of 48, 1, - 49, and so on
			}
		}
	score->size() > 1 ? cout << "\nIn an array pArr[5][5] the elements of the following columns go down: " << *score << endl
		: cout << "\nIn an array pArr[5][5] there are no columns whose elements go down\n";
	delete score;
	score = NULL;
}

void Array::ChangeMaxMin() { // Change the maximum and minimum elements in each column
	int * max = new int(-1);
	int * min = new int(11);
	int * max_index = new int(0);
	int * min_index = new int(0);

	for (int k = 0; k < 5; ++k) { // browse columns
		for (int i = this->Get_size() - 1; i > 0; --i) { // перебор строк одного столбца
			if (pArr[i][k] > *max) { // search for the maximum value of a column
				*max = pArr[i][k];
				*max_index = i;
			}
			if (pArr[i][k] < *min) { // search for the minimum value of a column
				*min = pArr[i][k];
				*min_index = i;
			}
		}
		std::swap(pArr[*max_index][k], pArr[*min_index][k]); // replacement of elements with values
		*max = -1, *min = 11; // nulling the values of dereferenced pointers
	}

	delete max, min, max_index, min_index;
	max = NULL, min = NULL, max_index = NULL, min_index = NULL;
	return;
}

void Array::MatrixSide() {// changing the values of the sides

	for (int i = 0; i < 5; ++i) // search of a line
		for (int first = 0, last = this->Get_size() - 1; first < last; ++first, --last) // enumeration of values of elements of one line
			std::swap(pArr[i][first], pArr[i][last]); // changing places of values of elements of one row of an array

	return;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));

	Array * Object = new Array;

	Object->RandompArr(0); // filling the array with random values (0) or manually (1). Default is 0.
	std::cout << "\nAn array pArr[5][5] after the creation:\n";
	Object->OutputpArr(1); // output of array element values
	Object->Find2Elements(); // Output max and before the max element of each line
	Object->FindGrowStroka(); // search for the number of rows where all numbers go in ascending order
	Object->ChangeMaxMin(); // Search for all columns where all numbers go down
	std::cout << "\nAn array pArr[5][5] after changes in the max and min of each column:\n";
	Object->OutputpArr(1);
	Object->MatrixSide(); // Search for all columns where all numbers go down
	std::cout << "\nAn array pArr[5][5] after changes in the sides of the matrix:\n";
	Object->OutputpArr(1);


	delete Object; // оclearing the heap memory area from storing the value of an Array object
	Object = NULL; // zeroing the address of a pointer to an Array object 

	system("pause");
	return 0;
}