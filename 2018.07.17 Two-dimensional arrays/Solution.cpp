#include<iostream>
#include<ctime>
#include <iomanip>

class Array {
public:
	Array() {} // The constructor of the class object
	~Array() {} // Destructor of the class object
	void RandompArr(); // populating an array with random numbers
	void OutputpArr() const;// array output
	void AnalyticspArr(); // search for the sum of elements, average arithmetic elements, minimum and maximum elements
	void RewritepArr(); // increase of all elements in the given column 10 times
	void ShowPairRowspArr(); // output of pair rows of an array
private:
	int pArr[5][5]; // two-dimensional array declaration
	int sum = 0, min_value = NULL, max_value = 0;
	double average = 0;
};

void Array::RandompArr() { // populating an array with random numbers
	for (int i = 0; i < 5; ++i)
		for (int k = 0; k < 5; ++k)
			pArr[i][k] = rand() % 11;
}

void Array::OutputpArr() const { // array output
	for (int i = 0; i < 5; ++i) {
		for (int k = 0; k < 5; ++k)
			std::cout << "\n[" << i <<"][" << k << "]\t"<< pArr[i][k];
		std::cout << std::endl;
	}
}

void Array::AnalyticspArr() { // search for the sum of elements, arithmetic mean, min and max element
	int j = 0; // variable for counting the number of array elements
	for (int i = 0; i < 5;++i)
		for (int k = 0; k < 5; ++k, ++j) {
			sum +=   pArr[i][k];
			if (pArr[i][k] < min_value)
				min_value = pArr[i][k];
			if (pArr[i][k] > max_value)
				max_value = pArr[i][k];
		}
	average = sum / j;
	std::cout << "\nSum of all array elements: " << this->sum << ", arithmetic mean of all elements: " << this->average
		<< ", minimum element: " << this->min_value << ", maximum element: " << this->max_value << std::endl;
}

void Array::RewritepArr() { // increase of all elements in the given column 10 times
	int * column = new int(0);
	std::cout << "\nEnter the column number: ";
	std::cin >> *column;
	for (int i = 0; i < 5; ++i)
		for (int k = 0; k < 5; ++k)
			if (k == *column) {
				pArr[i][k] = pArr[i][k] * 10;
				break;
			}
	delete column;
	column = NULL;
}

void Array::ShowPairRowspArr() { // output of pair rows of an array
	for (int i = 0; i < 5; i += 2) {
		for (int k = 0; k < 5; ++k)
			std::cout << "\n[" << i << "][" << k << "]\t" << std::setw(4) << pArr[i][k] << "   ";
		std::cout << std::endl;
	}

}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "RUS");
	srand(time(0));

	Array * Object = new Array;
	Object->RandompArr(); // populating an array with random values
	std::cout << "\nМассив pArr[5][5], заполненный случайными значениями:\n";
	Object->OutputpArr(); // output of array element values
	Object->AnalyticspArr(); // output of the sum of elements, average arithmetic elements, minimum and maximum element
	std::cout << "\nВывод марных строк массива pArr[5][5]:\n";
	Object->ShowPairRowspArr(); // output of pair rows of an array
	Object->RewritepArr(); // increase of all elements in the given column 10 times
	std::cout << "\nВывод значений елементов массива pArr[5][5] после увеличения в заданном столбце:\n";
	Object->OutputpArr(); // output of array element values
	
	delete Object; // clearing the heap memory area from storing the value of an Array object
	Object = NULL; // zeroing the address of a pointer to an Array object

	system("pause");
	return 0;
}