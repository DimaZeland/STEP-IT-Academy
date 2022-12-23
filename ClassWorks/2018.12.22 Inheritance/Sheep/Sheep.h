#pragma once
#include<iostream>
#include<string>

class Vehicle {
protected:
	std::string vendor = "Sea LTD";
	double speed = 10;
public:
	Vehicle(std::string name = "Sea LTD", double d = 10) : vendor(name), speed(d) { std::cout << "\n Vehicle Ctor called!\n"; }
	~Vehicle() { std::cout << "\n Vehicle Dtor called!\n"; }
	inline void Print() { std::cout << "\nvendor = " << vendor << ", speed = " << speed << std::endl; }
};

class Sheep: public virtual Vehicle{
protected:
	std::string its_my_name = "Noname";
	unsigned short its_my_year = 2000;
	unsigned int turbines = 2;
public:
	Sheep(std::string  Name = "Noname", unsigned short Year = 2000, unsigned int turb = 2);
	Sheep(unsigned int turb, std::string  Vendor = "Sea LTD", double Speed = 10, std::string  Name = "Noname", unsigned short Year = 2000);
	~Sheep();
	inline const std::string& Get_name() const { return its_my_name; }
	inline const unsigned short& Get_year() const { return its_my_year; }
	bool Set_name(std::string);
	bool Set_year(unsigned short);
	bool Input_year();
	bool Input_name();
	friend std::ostream& operator<<(std::ostream&, const Sheep&);
	void Print();
};

class Car: public virtual Vehicle{
protected:
	int power = 100;
public:
	Car(int Power) : Vehicle(), power(Power) { std::cout << "\n Car Ctor called!\n"; }
	Car(std::string cr = "Car", double d = 100, int i = 100) : Vehicle(cr, d), power(i) {}
	~Car(){ std::cout << "\n Car Dtor called!\n"; }
	void Print();
};

class Amphibia : public Sheep, private Car {
public:
	using Car::power;
	Amphibia(){ std::cout << "\n Amphibia Ctor called!\n"; }
	Amphibia(Car& cr, Sheep& sh);
	~Amphibia() { std::cout << "\n Amphibia Dtor called!\n"; };
	void Print();
};



