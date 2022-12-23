#pragma once

#include<vector>

class CustomerMenu; // proactive announcement

class BankAccount {
protected:
	enum { UAH = 1, USD, EUR, RUB };
	//static int its_my_accounts_value;
	unsigned short int its_my_currency = UAH;
	int its_my_account_number = 0;
	double its_my_deposit = 0;
	std::string its_my_currency_name = "UAH";
	
public:
	BankAccount(unsigned short int currency = UAH, double deposit = 0);
	~BankAccount() {}
	void Set_account_number(); // { its_my_account_number = CustomerMenu::its_my_accounts_value; }
	bool Set_currency(int currency = UAH); // set its_my_currency and its_my_currency_name
	bool Set_deposit(double deposit);
	friend class CustomerMenu;
};

class CustomerMenu {
private:
	std::vector<BankAccount> Clients;
	const double USDUAH = 28;
	const double EURUSD = 1.15;
	const double USDRUB = 67;
	static unsigned short int its_my_current_account;
	static int its_my_accounts_value;
public:
	CustomerMenu();
	bool Deposit_replenishment();
	void Input_current_account();
	double& Money_conversion(double&, const unsigned short int&, const unsigned short int&);
	bool Open_account();
	void Show_current_account_info();
	bool Show_transfer_accounts()const; // show the list of valid bank account for next many transfer
	void Transfer_between_accounts();
	bool Withdraw_money();
	friend void BankAccount::Set_account_number();
};

inline void
BankAccount::Set_account_number() { its_my_account_number = CustomerMenu::its_my_accounts_value + 1; }