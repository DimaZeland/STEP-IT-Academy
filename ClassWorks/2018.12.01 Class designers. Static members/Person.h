#pragma once
#include<iostream>
#include<memory>

class Person
{
private:
	unsigned int itsMyBirth;
	char* itsMyName = nullptr;
	char* itsMyHobby = nullptr;
	static int its_my_count;
	static std::string its_my_school;
public:
	/*explicit*/ Person(int = 1, const char* = "\nNoName", const char* = "\nNoHobby");
	Person(const Person&);
	~Person();
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
	inline static int Get_count() { return its_my_count; }
	inline static std::string Get_school() { return its_my_school; }
	static void Input_school();
};

