#pragma once

#include<algorithm>
#include<ctime>
#include<iostream>
#include<vector>
#include<string>

class MarketData {
private:
	float eurUsdPrice = 1.2;
public:
	MarketData(float price  = 1.2) :eurUsdPrice(price){}
	inline void SetPrice() { eurUsdPrice += (-100 + rand() % 200) * 0.0001; }
	inline float GetLastPrice()const { return eurUsdPrice; }
};

class Client {
private:
	std::string name;
	float lastPrice;
public:
	Client(std::string Name, float LastPrice = 0): name(Name), lastPrice(LastPrice){}
	inline void SetLastPrice(float newPrice) { lastPrice = newPrice; }
	inline void NewTrade(float LastPrice) {
		LastPrice > lastPrice ?
			std::cout << "\nClient " << name << " buy EURUSD.\n" :
			std::cout << "\nClient " << name << " sell EURUSD.\n";
		SetLastPrice(LastPrice);
	}
	inline std::string GetName()const { return name; }
};

class Broker {
private:
	MarketData * eurUsdBid;
	std::vector<Client*> Traders;
public:
	Broker(MarketData* symbol): eurUsdBid(symbol){}
	inline void OpenAccount(Client* newClient) { Traders.push_back(newClient); }
	inline void DeleteAccount(Client* currentClient) { auto Iterator = std::find(Traders.begin(), Traders.end(), currentClient); Traders.erase(Iterator); }
	inline void DoTrading() {
		eurUsdBid->SetPrice();
		std::for_each(
			Traders.begin(), Traders.end(),
			[&](Client* Cl) {Cl->NewTrade(eurUsdBid->GetLastPrice()); }
		);
	}
	inline void GetTradersListNames()const {
		std::for_each(
			Traders.begin(),Traders.end(),
			[&](Client* Cl) {std::cout << Cl->GetName() << '\n'; }
		);
	}
};