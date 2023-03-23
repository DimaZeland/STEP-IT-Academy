#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void PaintStolbec(int = 0); // drawing a vertical line from rows
void PaintStroka(int = 0); // drawing a horizontal line from rows
inline bool Result(double &); // return 1 if the argument is positive and 0 if the argument is negative.
int NumberToStepin(int &, int &); // product of degree

int main() {

    setlocale(LC_ALL, "RUS");

    // Task 1
    cout << "Task 1.\n";
    cout << "a. ";
    PaintStroka(10);
    cout << "b. ";
    PaintStroka(7);
    cout << "c. ";
    PaintStroka(4);
    cout << "d.\n";
    cout << "e. ";
    PaintStroka(8);
    cout << "f. ";
    PaintStroka(1);
    cout << "g. ";
    PaintStroka(1);
    cout << "h. ";
    PaintStroka(1);
    cout << "i. ";
    PaintStroka(13);
    cout << "j. ";
    PaintStroka(1);
    cout << "k. ";
    PaintStroka(1);
    cout << "l. ";
    PaintStroka(1);
    cout << "m. ";
    PaintStroka(19);
    cout << "a.\n";

    // Task 2
    cout << "Task 2.\n";
    cout << "\nEnter the number: ";
    double *number = new double(0);
    cin >> *number;
    cout << "Result: " << Result(*number) << endl;
    delete number;
    number = NULL;

    // Task 3
    cout << "Task 3.\n";
    cout << "\nEnter the number and stepin: ";
    int number1 = 0, stepin = 0;
    cin >> number1 >> stepin;
    cout << "\nResult: " << NumberToStepin(number1, stepin) << endl;

    system("pause");
    return 0;
}

void
PaintStroka(int stroka) {  // drawing a horizontal line from rows
    for (int i = 0; i < stroka; ++i)
        cout << "*";
    cout << endl;
}

void
PaintStolbec(int stolbets) {  // drawing a vertical line from rows
    for (int i = 0; i < stolbets; ++i)
        cout << "*\n";
}

inline bool
Result(double &number) { // return 1 if the argument is positive and 0 if the argument is negative.
    return number >= 0 ? 1 : 0;
}

int NumberToStepin(int &number, int &stepin) { // product of degree
    int result = number;
    if (!stepin) // product of number to zero degree
        return 1;
    else if (stepin == 1) // the product of a number to the first power
        return number;
    else
        for (int i = 2; i <= stepin; i += 1) // the product of a number to a power of 2 or more
            result *= number;
    return result;
}
