#include"MyClass.h"

int main() {
	
	MyClass* pObj = new MyClass;
	////Task 1
	//int number = 0;
	//cout << "Enter the number: ";
	//cin >> number;
	//cout << '\n' << number  << "!: " << pObj->Factorial(number) << endl;
	//// Task 2
	//pObj->GetNumbersFall(5);
	//// Task 3
	//pObj->GetNumbersGrowth(1, 10);
	// Task 4
	cout << pObj->GetSumDigits(125) << endl;
	
	delete pObj;
	pObj = NULL;

	system("pause");
	return 0;
}
