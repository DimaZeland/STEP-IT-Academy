#pragma once

#include<iostream>
#include<string>

class Unit abstract {
private:
	int healthy = 0;
	int damage = 0;
public:
	Unit (int h = 0, int d = 0) : healthy(h), damage(d) {}
	virtual ~Unit() {}
	inline void Print()const { std::cout << typeid(*this).name() + 5 << "\nHealth: " << healthy << ", damage: " << damage << std::endl; }
	virtual std::string  GetName()const abstract;
};

class MarinePyhotsinets: public Unit {
public:
	MarinePyhotsinets(int h = 20, int d = 20): Unit(h, d){}
	inline std::string  GetName() const override final { return "\nMarine Pyhotsines\n"; }
};

class CrazyScientist : public Unit {
public:
	CrazyScientist(int h = 30, int d = 30) : Unit(h, d) {}
	inline std::string  GetName() const override final { return "\nCrazy Scientist\n"; }
};

class MilitaryDoctor : public Unit {
public:
	MilitaryDoctor(int h = 40, int d = 40) : Unit(h, d) {}
	inline std::string  GetName() const override final { return "\nMilitary Doctor\n"; }
};


class Barrack abstract{
protected:
	Unit* pUnit = nullptr;
public:
	virtual ~Barrack() { delete pUnit; pUnit = nullptr; }
	virtual void CreateUnit() abstract;
	void Print()const { pUnit->Print(); }
};

class MilitaryBarak : public Barrack {
public:
	void CreateUnit() override final { pUnit = new MarinePyhotsinets; }
};

class ScientificBarak : public Barrack {
public:
	void CreateUnit() override final { pUnit = new CrazyScientist; }
};

class MedicalBarak : public Barrack {
public:
	void CreateUnit() override final { pUnit = new MilitaryDoctor; }
};