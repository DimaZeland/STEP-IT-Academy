#include"MyClass.h"

int main() {

    MyClass *pObj = new MyClass;

    // Task 1: output of all numbers from A to B inclusive, in ascending order, if A <B, or in descending order otherwise
    cout << "\nTask 1\n";
    int a = 0, b = 0;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    pObj->OutputNumber(a, b);
    // Task 2: get the inverted digits of the number
    cout << "\nTask 2\n";
    cout << "Enter number: ";
    cin >> a;
    pObj->GetInvertedDigits(a);
    // Task 3: get the digits of the number
    cout << "\nTask 3\n";
    cout << "Enter number: ";
    cin >> a;
    pObj->GetDigits(a);
    // Task 4: output 10 first numbers of the Fibonacci series
    cout << "\nTask 4\n";
    cout << "Output 10 first numbers of the Fibonacci series: ";
    pObj->GetFiboNumbers();
    cout << endl;

    delete pObj;
    pObj = NULL;

    system("pause");
    return 0;
}
