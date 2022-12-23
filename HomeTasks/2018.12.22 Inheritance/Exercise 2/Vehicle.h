#pragma once
#include<string>

class Vehicle {
protected:
	std::string manufacturer;
	double max_speed;
public:
	virtual ~Vehicle() {}
};

class Car : virtual public Vehicle {
protected:
	std::string model;
	unsigned short doors_number;
public:
	virtual ~Car() {}
};

class Ship : virtual public Vehicle {
protected:
	std::string serial_number;
	unsigned short turbines_number;
public:
	virtual ~Ship(){}
};

class Amphibia : public Car, public Ship {
};