#pragma once
#include<string>
#include<iostream>

class Lang abstract {
public:
	virtual double hourPay()abstract;
};

class Cpp : public Lang {
public:
	inline double hourPay()override final { return 100; };
};

class Csharp : public Lang {
public:
	inline double hourPay()override final { return 120; };
};


class Proger abstract {
protected:
	std::string name = "Senior Dev";
	static int monthHour;
	Lang* lang;
public:
	Proger(std::string Name = "Senior Dev", Lang* L = new Cpp) : name(Name), lang(L) {}
	virtual~Proger() { delete lang; lang = nullptr; }
	virtual double CalcSallary()abstract;
};

class FullStack : public Proger {
public:
	FullStack(std::string Name = "Senior Dev", Lang* L = new Cpp) : Proger(Name, L) {}
	double CalcSallary() { return Proger::monthHour * this->lang->hourPay() * 0.8; }
};

class Freelance : public Proger {
public:
	Freelance(std::string Name = "Senior Dev", Lang* L = new Cpp) : Proger(Name, L) {}
	double CalcSallary() { return Proger::monthHour * this->lang->hourPay(); }
};