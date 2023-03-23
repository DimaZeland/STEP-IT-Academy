#include<iostream>
#include<ctime>
#include <cstdlib>
#include"Builder.h"


unsigned int Nabiu::count = rand() % 1000 + 300;


int main() {
    std::srand(time(NULL));
    Kalash avtomat;
    std::cout << "\nPress 0 to <exit>: ";
    char ch;
    std::cin >> ch;
    while (ch != '0') {
        avtomat.Shot();
        std::cout << "\nPress 0 to <exit>: ";
        std::cin >> ch;
    }

    system("pause");
    return 0;
}