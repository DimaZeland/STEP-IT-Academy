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
	inline void UpgradeHp(int Hp) { hp += Hp; }
	inline void UpgradeDmg(int Dmg) { dmg += Dmg; }
	inline void UpgradeDodge(int Dodge) { dodge += Dodge; }
	friend std::ostream& operator<<(std::ostream& os, const Unit*);
};

class Swordsman : public Unit {
public:
	Swordsman(int Hp = 5, int Dmg = 5, int Dodge = 60) : Unit(Hp, Dmg, Dodge) {}
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
	Team * Good_boys = new Team("Good boys");
	Team* Bad_boys = new Team("Bad boys");
public:
	Unit * Sampling_rival(Team*, Unit*)const;
	void GameCourse();
};

class BaseSwordsmanDecorator: public Swordsman {
protected:
	Unit * unit;
public:
	BaseSwordsmanDecorator(Unit* Unit): unit(Unit){}
};

class ArmoredSwordsman : public BaseSwordsmanDecorator {
public:
	ArmoredSwordsman(Unit* Unit) : BaseSwordsmanDecorator(Unit) {UpgradeHp(15);}
};

class AcceleratedSwordsman : public BaseSwordsmanDecorator {
public:
	AcceleratedSwordsman(Unit* Unit) : BaseSwordsmanDecorator(Unit) {UpgradeDmg(20);}
};

class WellDirectedSwordsman : public BaseSwordsmanDecorator {
public:
	WellDirectedSwordsman(Unit* Unit) : BaseSwordsmanDecorator(Unit) {UpgradeDodge(25); }
};

class BaseArcherDecorator : public Archer {
protected:
	Unit * unit;
public:
	BaseArcherDecorator(Unit* Unit) : unit(Unit) {}
};

class ArmoredArcher : public BaseArcherDecorator {
public:
	ArmoredArcher(Unit* Unit) : BaseArcherDecorator(Unit) {UpgradeHp(15); }
};

class AcceleratedArcher : public BaseArcherDecorator {
public:
	AcceleratedArcher(Unit* Unit) : BaseArcherDecorator(Unit) {UpgradeDmg(20); }
};

class WellDirectedArcher : public BaseArcherDecorator {
public:
	WellDirectedArcher(Unit* Unit) : BaseArcherDecorator(Unit) {UpgradeDodge(25); }
};

class BaseMageDecorator : public Mage {
protected:
	Unit * unit;
public:
	BaseMageDecorator(Unit* Unit) : unit(Unit) {}
};

class ArmoredMage : public BaseMageDecorator {
public:
	ArmoredMage(Unit* Unit) : BaseMageDecorator(Unit) {UpgradeHp(15); }
};

class AcceleratedMage : public BaseMageDecorator {
public:
	AcceleratedMage(Unit* Unit) : BaseMageDecorator(Unit) {UpgradeDmg(20); }
};

class WellDirectedMage : public BaseMageDecorator {
public:
	WellDirectedMage(Unit* Unit) : BaseMageDecorator(Unit) {UpgradeDodge(25); }
};