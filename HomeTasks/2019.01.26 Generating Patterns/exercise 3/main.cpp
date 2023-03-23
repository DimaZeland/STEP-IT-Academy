#include<iostream>
#include<string>
#include"Builder.h"

int Proger::monthHour = 160;

int main() {

    std::cout << "\nEnter <1> to work fulltime or <2> to work freelance: ";
    int workType = 2;
    std::cin >> workType;
    std::cout << "\nEnter developer language: <1>  - Cpp, <2> - C#: ";
    int langType = 1;
    std::cin >> langType;
    Proger *pProger = nullptr;
    if (1 == workType && 1 == langType)
        pProger = new FullStack("Zeland", new Cpp);
    else if (1 == workType && 2 == langType)
        pProger = new FullStack("Zeland", new Csharp);
    else if (2 == workType && 1 == langType)
        pProger = new Freelance("Zeland", new Cpp);
    else if (1 == workType && 2 == langType)
        pProger = new Freelance("Zeland", new Csharp);

    if (pProger)
        std::cout << "\nMonth profit: " << pProger->CalcSallary() << " $" << std::endl;

    system("pause");
    return 0;
}