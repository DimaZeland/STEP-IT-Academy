#include<iostream>
#include"Vector.h"

using std::cout;
using std::endl;

int main(){
	Vector<int> v;
	Vector<int> v1(2); // фактичний розмір = 2, елементи нулі, buffer -> [0][0], 
					   //buffer - може вказувати на більшу ділянку, якщо capacity більше(capcity = 4, то buffer -> [0][0][.][.])
	v1.pushBack(10);
	v1.pushBack(20);
	cout << "The size of v is " << v.getSize() << endl; // 4
	cout << "The capacity of v is " << v.getCapacity() << endl; // >=4, якась Ваша формула, н-д, якщо ємності не вистачає можна збільшувати ємність масиву з певним коефіціентом(1.5 чи 2)
	v1.print(); // 0 0 10 20
	cout << v1[2] << " " << v[3] << endl;// бачимо 10  20


	for (size_t i = 0; i < v1.getSize(); ++i)// вивели всі елементи вектора
		cout << v1[i] << "\t";
	if (!v1.empty())// якщо не пусто
		v1.popback(); // вилучили останній
	v1.print(); // 0 0 10
	cout << "The size of v is " << v.Size() << endl; // 3
	v1.reserve(20); // capacity = 20, size = яке було(3)
	v1.front() = 1234; // перший елемент замінили на 1234
	v1.clear();
	cout << "The size of v after clearing is " << v.Size() << endl; // 0


	system("pause");
	return 0;
}