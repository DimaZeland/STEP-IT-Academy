#include"Builder.h"
#include<iostream>

int main(){
	
	Pistolet* pistol = new Pistolet;
	Pistolet* pistol2 = pistol->clone();
	Avtomat* avtomat = new Avtomat;
	Avtomat* avtomat2 = avtomat->clone();
	std::initializer_list<Weapon*> weapon{ pistol, pistol2, avtomat, avtomat2 };
	for (Weapon* x : weapon)
		std::cout << x;



	system("pause");
	return 0;
}