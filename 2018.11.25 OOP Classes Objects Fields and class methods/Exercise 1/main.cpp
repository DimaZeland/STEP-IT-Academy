#include<iostream>
#include"BankAccount.h"

int main() {
	CustomerMenu Obj;
	unsigned short int choise = 5;

	do{
		std::cout << "\nMenu:\n" <<
			"<0> - Exit\n" <<
			"<1> - Open an account and initially deposit money into the account\n" <<
			"<2> - Withdraw money from the account\n" <<
			"<3> - Put money on the bill\n" <<
			"<4> - Transfer money to another account\n" <<
			"<5> - Switch between bank accounts\n" <<
			"Enter the type of operation: ";
	std::cin >> choise;
	system("cls");
	switch (choise)
	{
	case 0:
		std::cout << "\nIt was nice to work with you. Goodbye!\n";
		break;
	case 1:
		Obj.Open_account();
		break;
	case 2:
		Obj.Withdraw_money();
		break;
	case 3:
		Obj.Deposit_replenishment();
		break;
	case 4:
		Obj.Transfer_between_accounts();
		break;
	case 5:
		Obj.Input_current_account();
		break;
	default:
		std::cout << "\nInvalid input.";
		break;
	}
	} while (0 != choise);

	system("pause");
	return 0;
}