#include<iostream>
#include<vector>
#include"Shape.h"

int main() {
	std::vector <Shape*> Forms{ new Point(), new Circle(2, 3), new Cylinder(5, 10) };
	for (Shape* x : Forms)
		x->print();
	
	system("pause");

	return 0;
}