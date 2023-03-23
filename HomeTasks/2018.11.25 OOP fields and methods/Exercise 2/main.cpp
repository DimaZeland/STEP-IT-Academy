#include <cstdlib>
#include<iostream>
#include"Int.h"

using std::cout;
using std::endl;


int main() {
    try { // To analyze the processing of a divide-by-zero error, initialize the variable <b> to zero.
        Int a = 8, b = 3, res = 0;
        res = a + b;
        cout << a << " + " << b << " = " << res << endl;
        cout << a << " / " << b << " = ";
        res = a / b;
        cout << res << endl;
        cout << a << " *= " << b << " = ";
        a *= b;
        cout << a << endl;
    }
    catch (int &exception) {
        if (!exception) // 0 == exception
            cout << "\nIt is impossible to divide by zero. Programm termination\n";
        system("pause");
        exit(EXIT_FAILURE);
    }
    catch (...) {
        cout << "\nAnother runtime runtime error. Shut down the application.";
        system("pause");
        exit(EXIT_FAILURE);
    }
    system("pause");
    return 0;
}