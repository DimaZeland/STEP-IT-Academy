#include "Menu.h"


int main() {
	// Task 1
	Menu Object;
	void (Menu::*pFunc) (void)const; // a pointer to a function with a given signature and the type of the return value
	pFunc = & Menu::ProgramInterface; // binding function with a pointer to a function
	(Object.*pFunc)(); // call method Object.ProgramInterface() through function pointer
	// Task 2

	system("pause");
	return 0;
}

