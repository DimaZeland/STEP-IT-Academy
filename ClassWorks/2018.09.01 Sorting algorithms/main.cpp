#include "MyClass.h"

int main() {

	srand(time(0));

	MyClass* pObject = new MyClass;
	const int size = 10;
	
	int Arr1[size]{};

	pObject->FillArray(size); // fill the value of Arr[]
	pObject->OutPutArray(size); // output the values of the Arr[]
	cout << "\nEnter the value to search the element's index: ";
	int value = 0;
	cin >> value;
	cout << "\nElement wiht value " << value << " has index " << pObject->FindIndex(pObject->GetArr(), value, size) << endl; // output of the index of the specified element of the array
	pObject->BubbleSortGrowth(size); // sorting the array by Bubble method to Grow
	cout << "\nArray[" << size << "] after BubbleSortGrowth():\n";
	pObject->OutPutArray(size);
	cout << "\nNumber of iterations: " << pObject->GetAteration() << endl;
	pObject->SetitsAteration();

	pObject->BubbleSortFall(size); // sorting the array by the method of Bubble Fall
	cout << "\nArray[" << size << "] after BubbleSortFall():\n";
	pObject->OutPutArray(size);
	cout << "\nNumber of iterations: " << pObject->GetAteration() << endl;
	pObject->SetitsAteration();

	pObject->SortInsertGrowth(size); // sorting the array by the method of Insert Growth
	cout << "\nArray[" << size << "] after SortInsertGrowth():\n";
	pObject->OutPutArray(size);
	cout << "\nNumber of iterations: " << pObject->GetAteration() << endl;
	pObject->SetitsAteration();

	pObject->SortInsertFall(size); // sorting the array by the method of Insert Fall 
	cout << "\nArray[" << size << "] after SortInsertFall():\n";
	pObject->OutPutArray(size);
	cout << "\nNumber of iterations: " << pObject->GetAteration() << endl;
	pObject->SetitsAteration();

	pObject->SortSelectionGrowth(size); // sorting the array by the method of Selection (Growth)
	cout << "\nArray[" << size << "] after SortSelectionGrowth():\n";
	pObject->OutPutArray(size);
	cout << "\nNumber of iterations: " << pObject->GetAteration() << endl;
	pObject->SetitsAteration();

	pObject->SortSelectionFall(size); // sorting the array by the method of Selection (Fall)
	cout << "\nArray[" << size << "] after SortSelectionFall():\n";
	pObject->OutPutArray(size);
	cout << "\nNumber of iterations: " << pObject->GetAteration() << endl;
	pObject->SetitsAteration();


	SortBubbleT(Arr1, size, true); // bubble sorting using a template function
	cout << "\nArray[" << size << "] after SortBubbleT():\n";
	pObject->OutPutArray(size);
	cout << "\nNumber of iterations: " << pObject->GetAteration() << endl;
	pObject->SetitsAteration();

	delete pObject;
	pObject = NULL;

	system("pause");
	return 0;
}