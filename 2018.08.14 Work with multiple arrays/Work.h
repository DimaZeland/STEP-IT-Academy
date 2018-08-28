#pragma once

#define IOSTREAM
#include<iostream>

#define CTIME
#include<ctime>

#define VECTOR
#include <vector>

using std::cout;
using std::endl;

#define USHORT
typedef unsigned short ushort;

class Work {
public:
Work() {}
~Work() {}
inline const ushort& Get_itsFirst(void) const { return Work::itsFirst; }
inline const ushort Get_itsSecond(void) const { return Work::itsSecond; }
void FindDownElements(const ushort& = Work::itsFirst, const ushort& = Work::itsSecond)const; // search for all rows whose elements go down
ushort FindLastPairLine(const ushort& = Work::itsFirst, const ushort& = Work::itsSecond)const; // return the last line number only with paired elements
void SetValue(const ushort& = Work::itsFirst, const ushort& = Work::itsSecond); // determining the values of array elements arr [][] by random numbers from 0 to 9
void ShowValue(const ushort& = Work::itsFirst, const ushort& = Work::itsSecond) const; // output of array elements arr [][] to the console
void SwapStroka(const ushort& = Work::itsFirst, const ushort& = Work::itsSecond); // reversal of rows with max and min elements
private:
static const ushort itsFirst = 5;
static const ushort itsSecond = 5;
int arr[itsFirst][itsSecond];
};