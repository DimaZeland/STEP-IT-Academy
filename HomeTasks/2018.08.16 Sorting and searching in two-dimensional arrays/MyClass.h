#pragma once

#include<ctime>
#include <iostream>


#ifndef USING
#define USING
using std::cout;
using std::endl;
#endif

typedef unsigned short ushort;

class MyClass
{
public:
	//constructor and destructor of the class object
	MyClass() {}
	~MyClass() {}

	// functions that output private class data
	inline const ushort& Get_itsFirst()const { return MyClass::itsFirst; };
	inline const ushort& Get_itsSecond()const { return MyClass::itsSecond; };
	void ShowArr(const ushort& = MyClass::itsFirst, const ushort& = MyClass::itsSecond)const; // show the value of Arr[][]

	//class methods	
	void ArgDiagonal(const ushort& = MyClass::itsFirst, const ushort& = MyClass::itsSecond)const; // Average of Diagonal of Arr[][]
	void FindLastMax(const ushort& = MyClass::itsFirst, const ushort& = MyClass::itsSecond)const; // Find Last Local Max Value
	ushort FindNumber(const ushort& = MyClass::itsFirst, const ushort& = MyClass::itsSecond)const; // Find Most Popular Number
	void FindSumTwoMax(const ushort& = MyClass::itsFirst, const ushort& = MyClass::itsSecond)const; // Find Sum 2 Max Number
	void SetArr(const ushort& = MyClass::itsFirst, const ushort& = MyClass::itsSecond); // set the value of Arr[][]
	void SortGrowArr(const ushort& = MyClass::itsFirst, const ushort& = MyClass::itsSecond); // grow sort element of stroka Arr[][]

private:
	static const ushort itsFirst = 5;
	static const ushort itsSecond = 5;
	ushort Arr[itsFirst][itsSecond];
};

