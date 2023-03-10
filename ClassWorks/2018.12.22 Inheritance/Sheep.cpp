#include "Sheep.h"



Sheep::Sheep(std::string  Name, unsigned short Year, unsigned int turb): Vehicle(), turbines(turb){
	Set_name(Name);
	Set_year(Year);
	std::cout << "\n Sheep Ctor called!\n";
}

Sheep::Sheep(unsigned int turb, std::string Vendor, double Speed, std::string Name, unsigned short Year)
	: Vehicle(Vendor, Speed){
	Set_name(Name);
	Set_year(Year);
	std::cout << "\n Sheep Ctor called!\n";
}


Sheep::~Sheep() {
	std::cout << "\nSheep Dtor called!\n";
}

bool
Sheep::Set_name(std::string str) {
	if (!str.empty()) {
		its_my_name = str;
		return true;
	}
	else{
		its_my_name = "Noname";
		return false;
	}
}

bool
Sheep::Set_year(unsigned short year){
	if (!year and year < 2019) {
		its_my_year = year;
		return true;
	}
	else {
		its_my_year = 2000;
		return false;
	}
}

bool Sheep::Input_year(){
	std::cout << "Enter year: ";
	unsigned short year = 0;
	std::cin >> year;
	return Set_year(year);
}

bool
Sheep::Input_name(){
	std::cout << "Enter name: ";
	std::string name = "";
	std::cin >> name;
	return Set_name(name);
}

void
Sheep::Print(){
	this->Vehicle::Print();
	std::cout << "\nName: " << Get_name() << ", year: " << Get_year() << std::endl;
}

std::ostream &
operator<<(std::ostream & os, const Sheep & sheep){
	os << "\nName: " << sheep.Get_name() << ", year: " << sheep.Get_year() << std::endl;
	return os;
}

void
Car::Print(){
	this->Vehicle::Print();
	std::cout << "\nPower: " << power << std::endl;
}

void Amphibia::Print(){
	Vehicle::Print();
	std::cout << "\nName: " << Get_name() << ", year: " << Get_year() << std::endl;
	std::cout << "\nPower: " << power << std::endl;
}
