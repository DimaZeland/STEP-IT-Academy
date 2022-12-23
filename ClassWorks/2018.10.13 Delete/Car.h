#pragma once

#include<iostream>
#include<cstring>

enum Colors { Red, Blue, Green };
enum Brands { BMW, Mercedes, Audi };

class Car {
private:
	int Year;
	char* Model;
	Colors Color;
	Brands Brand;
public:
	Car() : Year(0) { // default constructor overload
		Model = new char[30];
	}
	Car(int _year, const char* _model, Colors _color, Brands _brand) : Year(_year), Color (_color), Brand(_brand) { // constructor with formal arguments 
		
		Model = new char[30];
		strcpy(Model, _model);
		Model[strlen(_model) + 1] = '\0';
	}
	~Car() { // default destructor overload
		delete[] Model;
	}
	void Fill() { // filling in the class object fields
	//cout << "Enter brand of the car: 1 - BMW, 2 - Mercedes, 3 - Audi: ";
		int brand = 0;
		std::cin >> brand;
		Brand = Brands(brand + 1);

	}
	friend std::ostream& operator<<(std::ostream& os, Car& avto) { // output statement overload
		char* brand[9]{ '\0' };
		switch (avto.Brand)
		{
		case BMW:
			strcpy(brand,"BMW");
			brand[3] = '\0';
			break;
		case Mercedes:
			strcpy(brand, "Mercedes");
			brand[8] = '\0';
			break;
		case Audi:
			strcpy(brand, "Audi")
				brand[4] = '\0';
				break;
		default:
			strcpy(brand, "BMW\0")
			break;
		}

		char* color[6] = ' ';
		switch (avto.Color)
		{
		case Red:
			strcpy(color, "Red")
				color[3] = '\0';
			break;
		case Blue:
			strcpy(color, "Blue")
				color[4] = '\0';
			break;
		case Green:
			strcpy(color, "Green")
				brand[5] = '\0';
			break;
		default:
			brand = "Red\0";
			break;
		}
		
		os << "\nBrand: " << brand << ", Model:" << avto.Model << ", Year: " << avto.Year << ", Color" << color << std::endl;
			return os;
	}
	friend class Market;
};

class Market{
private:
	Car* Array;
public:
	static int size;
	Market() {
		if (!size) { // if 0 == size
			size = 1;
		}
		else
			++size;
		Array = new Car [size];
	}
	~Market() {
		delete[] Array;
		Array = nullptr;
	}
}