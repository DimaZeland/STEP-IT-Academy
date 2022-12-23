#include<iostream>
#include"Factory.h"

int main() {
	std::cout << "\nEnter <0> to create Marine Pyhotsinets or <1> to create Crazy Scientist or <2> to create Military Doctor:\n";
	int ch = 0;
	std::cin >> ch;
	Barrack* factory = nullptr;
	switch (ch) {
	case 0:
		factory = new MilitaryBarak;
		break;
	case 1:
		factory = new ScientificBarak;
		break;
	case 2: 
		factory = new MedicalBarak;
		break;
	default:
		factory = new MilitaryBarak;
		break;
	}
	factory->CreateUnit();
	factory->Print();

	system("pause");

	return 0;
}