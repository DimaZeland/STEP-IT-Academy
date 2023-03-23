#include<iostream>
#include"Builder.h"

using std::cout;
using std::endl;

int main() {
    Application HouseApp;
    Builder *pBuilder = nullptr;
    unsigned int choice = 0;
    do {
        std::cout << "\nEnter <0> to exit, <1> - to build te house, <2> - to Cost the buildings: ";
        std::cin >> choice;
        switch (choice) {
            case 1:
                pBuilder = new HouseBuilder;
                break;
            case 2:
                pBuilder = new CostBuilder;
                break;
            default:
                pBuilder = new HouseBuilder;
                break;
        }
        if (choice) {
            AbstractHouse *house = HouseApp.MakeBuilding(pBuilder);
            std::cout << house;
        }
        delete pBuilder;
        pBuilder = nullptr;

    } while (choice);

    system("pause");
    return 0;
}