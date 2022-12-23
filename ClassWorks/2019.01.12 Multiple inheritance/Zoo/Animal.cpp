#include "Animal.h"

void
Animal::Print(void) const{
	std::cout << "\nNick: " << Nick << ", Age: " << Age << "\nSound: " << this->Sound() << ", Type: " << Type() << std::endl;
}

std::string
Animal::Sound(void)const {
	return "no sound";
}

std::string
Animal::Type(void) const{
	return "No type";
}

std::string
Cat::Sound(void)const {
	return "May!";
}

std::string
Cat::Type(void) const {
	return "Cat";
}

std::string
Dog::Sound(void)const {
	return "Gaph!";
}

std::string
Dog::Type(void) const {
	return "Dog";
}