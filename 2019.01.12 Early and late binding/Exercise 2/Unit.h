#pragma once

#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#include<vector>

class Unit {
protected:
	int hp = 0, dmg = 0, dodge = 0;
public:
	Unit(int Hp = 0, int Dmg = 0, int Dodge = 0)
		: hp(Hp), dmg(Dmg), dodge(Dodge) {}
	virtual ~Unit() {}
	inline bool Avoid_Attacks() const { return rand() % 101 < dodge ? true : false; }
	inline bool Attack(Unit* defender);
	inline bool Alive() { return hp; }
	friend std::ostream& operator<<(std::ostream& os, const Unit*);
};

class Swordsman : public Unit {
public:
	Swordsman(int Hp = 5, int Dmg = 5, int Dodge = 60): Unit(Hp, Dmg, Dodge){}
};

class Archer : public Unit {
public:
	Archer(int Hp = 12, int Dmg = 4, int Dodge = 40) : Unit(Hp, Dmg, Dodge) {}
};

class Mage : public Unit {
public:
	Mage(int Hp = 8, int Dmg = 10, int Dodge = 30) : Unit(Hp, Dmg, Dodge) {}
};

class Team {
private:
	std::vector<Unit*> comando;
	std::string name = "Noname";
public:
	Team(std::string Name = "Noname", unsigned int members = 3);
	bool TeamAlive();
	void Team_line_up()const;
	friend class Game;
};

class Game {
private:
	Team* Good_boys = new Team("Good boys");
	Team* Bad_boys = new Team("Bad boys");
public:
	Unit* Sampling_rival(Team*, Unit*)const;
	void GameCourse();
};