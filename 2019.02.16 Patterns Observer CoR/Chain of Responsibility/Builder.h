#pragma once

//#include<algorithm>
//#include<ctime>
#include<iostream>
//#include<vector>
#include<string>

class USD100;
class USD50;
class USD20;
class USD5;

struct Banknotes {
	int US100 = 0;
	int US50 = 0;
	int US20 = 0;
	int US5 = 0;
	inline int CashBanknotesSum() const {	return US100 * 100 + US50 * 50 + US20 * 20 + US5 * 5;}
	inline void GetCashBanknotesCount() const {
		std::cout << '\n' << US100 << " banknotes of 100$, " << US50 << " banknotes of 50$, " << US20 <<
			" banknotes of 20$, " << US5 << " banknotes of 5$.\n";
	}
};

class Bankomat {
protected:
	Banknotes withdraw;
	Banknotes ATMBalance;
public:
	Bankomat(int us100, int us50, int us20, int us5): ATMBalance{us100, us50, us20, us5} {}
	virtual inline void MoneyPayment(int Sum) abstract;
	inline int CashInATM()const { return ATMBalance.US100 * 100 + ATMBalance.US50 * 50 + ATMBalance.US20 * 20 + ATMBalance.US5 * 5; }
	inline void ATMBalanceReduction(){
		ATMBalance.US100 -= withdraw.US100;
		ATMBalance.US50 -= withdraw.US50;
		ATMBalance.US20 -= withdraw.US20;
		ATMBalance.US5 -= withdraw.US5;

		withdraw.US100 = withdraw.US50 = withdraw.US20 = withdraw.US5 = 0;
	}
};

class USD5: public Bankomat{
public:
	USD5(int us100, int us50, int us20, int us5) : Bankomat{ us100, us50, us20, us5 } {}
	inline void MoneyPayment(int Sum) override {
		if (ATMBalance.US5 * 5 >= Sum)
			withdraw.US5 = Sum / 5;
		else
			withdraw.US5 = ATMBalance.US5;
		
			std::cout << "\nIssued $" << withdraw.CashBanknotesSum() << ", bills of the following denomination:";
			withdraw.GetCashBanknotesCount();
			ATMBalanceReduction();
	}
};

class USD20 : public USD5 {
public:
	USD20(int us100, int us50, int us20, int us5) : USD5{ us100, us50, us20, us5 } {}
	inline void MoneyPayment(int Sum) override {
		if (ATMBalance.US20 * 20 >= Sum) {
			withdraw.US20 = Sum / 20;
			Sum = Sum % 20;
		}
		else {
			withdraw.US20 = ATMBalance.US20;
			Sum = (Sum - withdraw.US20 * 20);
		}

		if (Sum != 0)
			USD5::MoneyPayment(Sum);
		else {
			std::cout << "\nIssued $" << withdraw.CashBanknotesSum() << ", bills of the following denomination:";
			withdraw.GetCashBanknotesCount();
			ATMBalanceReduction();
		}
	}
};

class USD50 : public USD20 {
public:
	USD50(int us100, int us50, int us20, int us5) : USD20{ us100, us50, us20, us5 } {}
	inline void MoneyPayment(int Sum) override {
		if (ATMBalance.US50 * 50 >= Sum) {
			withdraw.US50 = Sum / 50;
			Sum = Sum % 50;
		}
		else {
			withdraw.US50 = ATMBalance.US50;
			Sum = (Sum - withdraw.US50 * 50);
		}

		if (Sum != 0)
			USD20::MoneyPayment(Sum);
		else {
			std::cout << "\nIssued $" << withdraw.CashBanknotesSum() << ", bills of the following denomination:";
			withdraw.GetCashBanknotesCount();
			ATMBalanceReduction();
		}
	}
};

class USD100 : public USD50 {
public:
	USD100(int us100, int us50, int us20, int us5) : USD50{ us100, us50, us20, us5 } {}
	inline void MoneyPayment(int Sum) override final{
		if (Sum > ATMBalance.CashBanknotesSum()) {
			std::cout << "\nThere are insufficient funds in the ATM to issue the specified amount of cash.\n" <<
				"Maximum withdrawal amount " << ATMBalance.CashBanknotesSum() << '\n';
			return;
		}
		else if (Sum % 5) {
			std::cout << "\nDesired funds in total " << Sum << " cannot be issued.\n" <<
				"\nEnter the amount of funds to withdraw multiple 5, 20, 50 or 100.\n";
			return;
		}

		if (ATMBalance.US100 * 100 >= Sum){
		withdraw.US100 = Sum / 100;
		Sum = Sum % 100;
		}
		else {
			withdraw.US100 = ATMBalance.US100;
			Sum = (Sum - withdraw.US100 * 100);
		}

		if (Sum != 0)
			USD50::MoneyPayment(Sum);
		else {
			std::cout << "\nIssued $" << withdraw.CashBanknotesSum() << ", bills of the following denomination:";
				withdraw.GetCashBanknotesCount();
			ATMBalanceReduction();
		}
	}
};