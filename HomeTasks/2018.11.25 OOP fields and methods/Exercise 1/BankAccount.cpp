#include<iostream>
#include "BankAccount.h"

BankAccount::BankAccount(unsigned short int currency, double deposit) {
	Set_account_number();
	Set_currency(currency); // set its_my_currency and its_my_currency_name
	Set_deposit(deposit);
}

bool
BankAccount::Set_currency(int currency) {
	if (currency > 0 and currency <= 4) {
		its_my_currency = currency;
		switch (currency){
		case 1:
			its_my_currency_name = "UAH";
			break;
		case 2:
			its_my_currency_name = "USD";
			break;
		case 3:
			its_my_currency_name = "EUR";
			break;
		case 4:
			its_my_currency_name = "RUB";
			break;
		default:
			its_my_currency_name = "UAH";
			break;
		}
		return true;
	}
	else {
		its_my_currency = UAH;
		its_my_currency_name = "UAH";
		return false;
	}
}

bool
BankAccount::Set_deposit(double deposit) {
	if (its_my_deposit + deposit >= 0) {
		its_my_deposit += deposit;
		return true;
	}
	else
		return false;
}
