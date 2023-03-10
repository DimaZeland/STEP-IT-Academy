#include<iostream>
#include<string>
#include<vector>
#include"Grandpa.h"

int main() {
	std::vector<Grandpa*> family{ new Grandpa, new Daddy, new Son };
	for (Grandpa* x : family)
		x->print();


	system("pause");
	return 0;
}


