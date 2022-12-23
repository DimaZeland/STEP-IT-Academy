#include<iostream>
#include<vector>
#include"Animal.h"

int main() {
	Cat hurry("Hurry", 5);
	// рабoта type id
	std::cout << typeid(hurry).name() << std::endl;
	Cat cat("Meison", 7);
	Dog dog("Lord", 12);

	std::vector<Animal*> Zoo{ &hurry, &cat, &dog };
	std::cout << "\nOur Zoo members:\n";
	for (Animal* x : Zoo){
		x->Print();
		std::cout << typeid(*x).name() + 5 << std::endl;
	}

	system("pause");
	return 0;
}
