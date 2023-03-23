#include"Builder.h"
#include<iostream>

int main() {

    Driver taxi;
    int ch = 0;
    std::cout << "\nEnter <1> to start, <2> - stop, <3> - turn left, <4> - turn right, <0> - exit: ";
    std::cin >> ch;
    while (ch) {
        switch (ch) {
            case 1:
                taxi.Start();
                break;
            case 2:
                taxi.Stop();
                break;
            case 3:
                taxi.Rotate(-90);
                break;
            case 4:
                taxi.Rotate(90);
                break;
            default:
                break;
        }
        std::cout << "\nEnter <1> to start, <2> - stop, <3> - turn left, <4> - turn right, <0> - exit: ";
        std::cin >> ch;
    }

    system("pause");
    return 0;
}