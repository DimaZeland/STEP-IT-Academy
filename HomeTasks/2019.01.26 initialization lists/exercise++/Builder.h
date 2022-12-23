#pragma once
#include<iostream>
#include<string>
#include<stack>

class Nabiu {
private:
	static unsigned int count;
	unsigned int ID;
public:
	Nabiu() {
		ID = --count;
	}
	inline int GetID() const { return ID; }
	bool ShotResult()const { return 70 > (rand() % 101) + 1; }
};

class Kalash;

class Magazz {
private:
	std::stack<Nabiu*> ff{};
public:
	Magazz() {
		for (int i = 0; i < 30; ++i)
			ff.push(new Nabiu);
	}
	~Magazz() {
		Nabiu* buf = nullptr;
		for (int i = 0; i < ff.size(); ++i) {
			buf = ff.top();
			ff.pop();
			delete buf;
		}
	}
	inline void PlusNabiu(){
		if (ff.size() < 30)
			ff.push(new Nabiu);
	}
	inline Nabiu* MinusNabiu() {
		if (!ff.empty()){
			return ff.top();
		}
	}
	friend class Kalash;
};

class Kalash {
private:
	Magazz * worker = new Magazz;

public:
	~Kalash() { delete worker; worker = nullptr; }
	inline void Change_worker(){
		if (worker->ff.empty()) {
			delete worker; 
			worker = new Magazz;
		}
	}
	void Shot() {
		std::cout << "\nThe machine shot a bullet " << worker->ff.top()->GetID() << ", and ";
		if (worker->ff.top()->ShotResult())
			std::cout << " hit.\n";
		else
			std::cout << " missed.\n";
		delete worker->MinusNabiu();
		worker->ff.pop();
		if (worker->ff.empty()) {
			delete worker; 
			worker = new Magazz;
		}
	}
};