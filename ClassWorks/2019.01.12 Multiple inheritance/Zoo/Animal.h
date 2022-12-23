#pragma once

#include<iostream>
#include<string>

class Animal abstract{
protected:
	std::string Nick = "No Nick";
	unsigned int Age = 1;
public:
	Animal( std::string nick = "No Nick", unsigned int age = 1): Nick(nick), Age(age){}
	virtual ~Animal(){}
	inline void Set_Nick(std::string nick) { Nick = nick; }
	inline void Set_Age(unsigned int age) { Age = age; }
	inline std::string Get_Nick()const { return Nick; }
	inline unsigned int Get_Age()const { return Age; }
	void Print(void)const;
	virtual std::string Sound(void)const = 0;
	virtual std::string Type(void)const abstract;
};

class Cat : public Animal {
public:
	Cat(std::string nick = "No nick", unsigned int age = 1): Animal(nick, age){}
	std::string Sound(void)const override final;
	std::string Type (void)const override final;
};

class Dog : public Animal {
public:
	Dog(std::string nick = "No Nick", unsigned int age = 1) : Animal(nick, age) {}
	std::string Sound(void)const override final;
	std::string Type(void)const override final;
};

