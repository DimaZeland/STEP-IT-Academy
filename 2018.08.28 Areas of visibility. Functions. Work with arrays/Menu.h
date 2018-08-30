#pragma once

#include<vector>
#include<string>
#include<iostream>


using namespace std;

class Menu
{
public:
	Menu() {}
	~Menu() {}
	void Calculator(void)const; // calculator
	void Converter(void)const; // currency converter
	void ConverterWeight(void)const; // weight converter
	inline float CostTrip(float& distance, float& litersPer100km, float& oilPrice)const { // determine the cost of the trip
		return distance * 0.02f * litersPer100km * oilPrice;
	}
	void ProgramInterface()const; // program interface
private:
};