#include<iostream>
#include"GUIFactory.h"

int main() {
	std::cout << "\nEnter <0> to create Windows GUI or <1> to create Mac GUI:\n";
	int ch = 0;
	std::cin >> ch;
	GUIFactory* factory = nullptr;
	switch (ch){
	case 0:
		factory = new WinFactory;
		break;
	case 1:
		factory = new MacFactory;
		break;
	default:
		factory = new WinFactory;
		break;
	}
	Application* qapp = new Application(factory);
	qapp->CreateUI();
	qapp->paint();

	system("pause");

	return 0;
}