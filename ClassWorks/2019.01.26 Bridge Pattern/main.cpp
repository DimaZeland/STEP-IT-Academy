#include<iostream>
#include<string>
#include"Header.h"

int Proger::monthHour = 160;

int main() {


	Proger* pProger = new Freelance("Zeland", new Cpp);
	std::cout << "\nMonth profit: " << pProger->CalcSallary() << " $" << std::endl;


	system("pause");
	return 0;
}