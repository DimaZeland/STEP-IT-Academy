#pragma once
#include<iostream>

class Person
{
private:
	static constexpr int SIZE = 20;
	unsigned int itsMyBirth;
	char itsMyName[SIZE];
	char itsMyHobby[SIZE];
public:
	Person(int = 1, const char* = "\nNoName", const char* = "\nNoHobby");
	~Person() { std::cout << "\nDestructor called!\n"; }
	bool Set_Data();
	void Set_itsMyBirth(unsigned int);
	void Set_itsMyHobby(const char*);
	void Set_itsMyName(const char*);
	void Show_Data() const;
	bool Input_Name();
	const char* Get_Name()const;
	bool Input_Hobby();
	const char* Get_Hobby()const;
	bool Input_Birth();
	unsigned int Get_Birth()const;
};

