#pragma once

#ifndef CAR_H_
#define CAR_H_

#include<iostream>
#include<cstring>

class Car {
private:
	enum Colors { Red, Blue, Green };
	enum Brands { BMW, Mercedes, Audi };
	int Year;
	char* Model;
	Colors Color;
	Brands Brand;
public:
	Car(); // overload default constructor
	Car(int _year, const char* _model, Colors _color, Brands _brand); // constructor with formal arguments 
	Car(const Car&); // overloaded deep copy constructor
	~Car(); // default destructor overload
	Car& operator=(const Car&); // overloaded assignment operator (deep)
	inline bool operator>(const Car& s) const{
		return Year > s.Year;
	}
	inline bool operator>=(const Car& s) const {
		return Year >= s.Year;
	}
	inline bool operator<(const Car& s) const {
		return Year < s.Year;
	}
	inline bool operator<=(const Car& s) const {
		return Year <= s.Year;
	}
	inline bool operator==(const Car& s) const {
		return Year == s.Year;
	}
	inline bool operator!=(const Car& s) const {
		return Year != s.Year;
	}
	void Fill(); // filling in the class object fields
	void Edit(); // edit the class object
	friend std::ostream& operator<<(std::ostream& os, Car& avto);
};
#endif