#include "Builder.h"

inline bool
Unit::Attack(Unit * defender) {
	if (Alive() & defender->Alive())// if the attacker and defender are still alive
		if (defender->Avoid_Attacks()) { // successful attack bias 
			std::cout << "\nAttack failed!\n";
			return false;
		}
		else { // unsuccessful attack bias
			defender->hp = defender->hp >= this->dmg ? defender->hp - this->dmg : 0; // decrease in hit points
			std::cout << "\nAttack succeeded! The " << typeid(*defender).name() + 5 << " has " << defender->hp << " hp.\n";
			if (!defender->hp) // 
				std::cout << typeid(*defender).name() + 5 << " perished.\n";
			return true;
		}
	else
		return false;
}

std::ostream&
operator<<(std::ostream& os, const Unit* pUnit) {
	os << typeid(*pUnit).name() + 5 << " hp: " << pUnit->hp << ", dmg: " << pUnit->dmg << ", dodge: " << pUnit->dodge << std::endl;
	return os;
}

Team::Team(std::string Name, unsigned int members) : name(Name) {
	for (; members > 0; --members) // adding players to the team
		switch (rand() % 9) {
		case 0:
			comando.push_back(new ArmoredSwordsman(new Swordsman));
			break;
		case 1:
			comando.push_back(new AcceleratedSwordsman(new Swordsman));
			break;
		case 2:
			comando.push_back(new WellDirectedSwordsman(new Swordsman));
			break;
		case 3:
			comando.push_back(new ArmoredArcher(new Archer));
			break;
		case 4:
			comando.push_back(new AcceleratedArcher(new Archer));
			break;
		case 5:
			comando.push_back(new WellDirectedArcher(new Archer));
			break;
		case 6:
			comando.push_back(new ArmoredMage(new Mage));
			break;
		case 7:
			comando.push_back(new AcceleratedMage(new Mage));
			break;
		case 8:
			comando.push_back(new WellDirectedMage(new Mage));
			break;
		default:
			comando.push_back(new ArmoredSwordsman(new Swordsman));
			break;
		}
}

bool
Team::TeamAlive() {
	for (Unit* x : comando)
		if (x->Alive()) // if anybode is still alive
			return true;
	return false;
}

void
Team::Team_line_up() const {
	for (Unit* x : comando)
		if (x->Alive())
			std::cout << x;
}

Unit*
Game::Sampling_rival(Team* defender, Unit* attacker)const {
	for (Unit* x : defender->comando)
		if (typeid(*x).name() == typeid(*attacker).name() & x->Alive())
			return x; // same type opponent's return
	unsigned short index = 0;
	while (defender->comando.size() > index) { // selection of a specific player from the defending team
		if (defender->comando[index]->Alive())
			return defender->comando[index];
		else
			++index;
	}
}

void
Game::GameCourse() {
	std::cout << "\nThe game is start!\nComposition of team:\n";
	std::cout << Good_boys->name << std::endl;
	Good_boys->Team_line_up();
	std::cout << Bad_boys->name << std::endl;
	Bad_boys->Team_line_up();
	Unit* attacker;
	Unit* defender;
	Team* attack_team = rand() % 2 ? Good_boys : Bad_boys;
	Team* defend_team = attack_team == Good_boys ? Bad_boys : Good_boys;
	unsigned short* ind_0 = new unsigned short(0);
	unsigned short* ind_1 = new unsigned short(0);
	unsigned short* ind_buf = new unsigned short(0);
	while (Good_boys->TeamAlive() & Bad_boys->TeamAlive()) { // play till complete victory
		std::cout << "Press space bar+<Enter> to continue.\n";
		while (getchar() != 32); // 
		while (true) {
			//index = rand() % (Bad_boys->comando.size()); // selection of a specific player from the attacking team
			attacker = attack_team->comando[(*ind_buf)++];
			if (*ind_buf >= attack_team->comando.size()) // the start of the attack on the next circle
				*ind_buf = 0;
			if (attacker->Alive())
				break;
		}
		defender = Sampling_rival(defend_team, attacker);

		std::cout << "\nNow attacking " << typeid(*attacker).name() + 5 << " (" << attack_team->name << " team),\ndefending " <<
			typeid(*defender).name() + 5 << " (" << defend_team->name << " team).\n";

		attacker->Attack(defender);

		attack_team = attack_team == Good_boys ? Bad_boys : Good_boys; // opponent attack
		defend_team = defend_team == Good_boys ? Bad_boys : Good_boys;
		ind_buf = ind_buf = ind_0 ? ind_1 : ind_0; // change the queue of actions after changing the roles of commands
	}
	std::cout << "\nWon the team of ";
	if (Good_boys->TeamAlive())
		std::cout << Good_boys->name;
	else
		std::cout << Bad_boys->name;
	std::cout << "!\nComposition of the winning team:\n";
	Good_boys->TeamAlive() ? Good_boys->Team_line_up() : Bad_boys->Team_line_up();
}