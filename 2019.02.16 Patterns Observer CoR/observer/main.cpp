//#include<algorithm>
#include<ctime>
#include<iostream>
#include<string>
//#include<vector>
#include"Builder.h"

int main() {
	srand(time(0));

	MarketData EURUSD;
	Client David("David", 1.22), Alex ("Alex", 1.19) , Robert ("Robert", 1.1934);

	Broker MTrading(&EURUSD);
	MTrading.OpenAccount(&David);
	MTrading.OpenAccount(&Alex);
	MTrading.OpenAccount(&Robert);

	std::cout << "\nFirst trade our clients:\n";
	MTrading.DoTrading();
	std::cout << "\nList of our clients:\n";
	MTrading.GetTradersListNames();

	MTrading.DeleteAccount(&Alex);
	std::cout << "\nSecond Trade our clients:\n";
	MTrading.DoTrading();
	std::cout << "\nList of our clients:\n";
	MTrading.GetTradersListNames();

	system("pause");
	return 0;
}