#include<string>
#include<iostream>
#include<vector>

class Bank;
class Score {
protected:
	unsigned int numberScore = 0;
	std::string password = "Admin12345";
	float balance = 0;
public:
	Score(unsigned int num = 0, std::string pass = "Admin12345", float bal = 0) : numberScore(num), password(pass), balance(bal) {}
	float getBalance(std::string pass) const {
		if (pass == password)
			return balance;
		else
			return -1;
	}
	float WithDraw(std::string pass, float sum) {
		if (pass == password)
			return balance = balance - sum;
		else
			return -1;
	}
	friend class Bank;
	friend class Bankomat;
};

class Bank {
protected:
	std::vector <Score> Clients;
public:
	Bank(std::vector <Score> cl) : Clients(cl) {}
	float getBalance(unsigned int num, std::string pass)const {
		float res = -1;
		for (auto x : Clients)
			if (x.numberScore == num)
				res = x.getBalance(pass);
		return res;
	}
	
	float Withdraw(std::string pass, float sum, unsigned int num) {
		float res = -1;
		for (auto x : Clients)
			if (x.numberScore == num)
				res = x.WithDraw(pass, sum);
		return res;
	}
};

class Bankomat {
protected:
	std::vector <Score> ClientsBuf;
	Bank* bank = nullptr;
public:
	Bankomat(Bank* vank = nullptr) : bank(vank) {}
	float getBalance(unsigned int num, std::string pass) {
		float res = -1;
		if (!ClientsBuf.empty())
			for (auto x : ClientsBuf)
				if (x.numberScore == num) {
					res = x.getBalance(pass);
					return res;
				}
		res = bank->getBalance(num, pass);
		ClientsBuf.push_back(Score(num, pass, res));
		return res;
	}

	float Withdraw(std::string pass, float sum, unsigned int num) {
		float res = -1;
		res = bank->Withdraw(pass, sum, num);
		if (-1 != res) // is score is valid and pass is valid
			if (!ClientsBuf.empty()) {
				for (auto& x : ClientsBuf)
					if (x.numberScore == num)
						x.balance = res;
			}
			else
				ClientsBuf.push_back(Score(num, pass, res));
		return res;
	}
};

class Client {
private:
	std::string pass = "Admin12345";
	unsigned int number = 0;
public:
	Client(std::string p = "Admin12345", unsigned int n = 0) : pass(p), number(n) {}
	std::string GetPassword() const { return pass; }
	unsigned short GetNumber() const { return number; }
};