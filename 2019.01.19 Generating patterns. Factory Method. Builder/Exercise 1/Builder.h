#pragma once
#include<iostream>
#include<string>

class AbstractHouse abstract {
public:
	inline virtual void Print() abstract;
	friend std::ostream& operator<<(std::ostream& os, AbstractHouse* pHouse);
};

class House : public AbstractHouse {
public:
	std::string basement = "No iron concrete";
	std::string wall = "No concrete";
	std::string roof = "No tile";
	std::string windows = "No plastic";
	std::string doors = "No wooden";
	inline void Print() override final { std::cout << "\nHouse!\n"; }
	friend std::ostream& operator<<(std::ostream& os, const House* pHouse);
};

class Cost : public AbstractHouse {
public:
	double basement = 0;
	double wall = 0;
	double roof = 0;
	double windows = 0;
	double doors = 0;
	inline void Print() override final { std::cout << "\nCost!\n"; }
	friend std::ostream& operator<<(std::ostream& os, const Cost* pCost);
};


class Builder abstract {
public:
	virtual void Reset() abstract;
	virtual void SetBasement() abstract;
	virtual void SetWall() abstract;
	virtual void SetRoof() abstract;
	virtual void SetWindows() abstract;
	virtual void SetDoors() abstract;
	virtual AbstractHouse* GetResult() const abstract;
	virtual ~Builder() {}
};

class HouseBuilder : public Builder {
protected:
	House * pHouse = nullptr;
public:
	~HouseBuilder() { delete pHouse; pHouse = nullptr; }
	inline void Reset() { pHouse =  new House; }
	inline void SetBasement() override final { pHouse->basement = "Iron Concrete"; }
	inline void SetWall() override final { pHouse->wall = " Concrete"; }
	inline void SetRoof() override final { pHouse->roof = "Tile"; }
	inline void SetWindows() override final { pHouse->windows = "Plastic"; }
	inline void SetDoors() override final { pHouse->doors = "Wooden"; }
	AbstractHouse* GetResult()const { return pHouse; }
};

class CostBuilder : public Builder {
protected:
	Cost * pCost = nullptr;
public:
	~CostBuilder() { delete pCost; pCost = nullptr; }
	inline void Reset() { pCost =  new Cost; }
	inline void SetBasement() override final { pCost->basement = 1111; }
	inline void SetWall() override final { pCost->wall = 2222; }
	inline void SetRoof() override final { pCost->roof = 3333; }
	inline void SetWindows() override final { pCost->windows = 4444; }
	inline void SetDoors() override final { pCost->doors = 5555; }
	AbstractHouse* GetResult()const { return pCost; };
};

class Director {
public:
	void ConstructBuilding(Builder* builder);
};

class Application {
protected:
	Director * director = nullptr;
	Builder* pBuilder = nullptr;
public:
	AbstractHouse* MakeBuilding(Builder*);
	~Application() { delete director; director = nullptr; }
};