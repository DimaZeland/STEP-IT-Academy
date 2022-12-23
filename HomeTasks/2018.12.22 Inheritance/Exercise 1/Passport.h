#pragma once
#include<iostream>
#include<string>
#include<vector>

class Passport {
protected:
	std::string its_my_Name = "Noname";
	std::string its_my_Series = "AA";
	unsigned int its_my_Passport_Number = 1;
public:
	Passport(std::string name = "Noname", std::string series = "AA", unsigned int num = 1)
		: its_my_Name(name), its_my_Series(series), its_my_Passport_Number(num) {}
	inline void Set_Name(std::string name) { its_my_Name = name; }
	inline void Set_Series(std::string series) { its_my_Series = series; }
	inline void Set_Passport_Number(unsigned int num) { its_my_Passport_Number = num ? num : 1; }
	inline std::string Get_Name(void)const { return its_my_Name; }
	inline std::string Get_Series(void)const { return its_my_Series; }
	inline unsigned int Get_Passport_Number(void)const { return its_my_Passport_Number; }
	inline void Print(void)const { std::cout << "\nName: " << its_my_Name << ", Passport: " << its_my_Series << its_my_Passport_Number << std::endl;}
	friend std::ostream& operator<< (std::ostream&, Passport&);
};

struct Visa {
	std::string Country = "USA";
	std::string Expiration = "01.01.2100";
};

class ForeignPassport : public Passport {
protected:
	std::vector<Visa> visas{};
public:
	ForeignPassport(std::vector<Visa> vi, std::string name = "Noname", std::string series = "AA", unsigned int num = 1)
		:Passport(name, series, num), visas{vi} {}
	void Print(void)const;
	inline void Visa_push_back(Visa v) { visas.push_back(v); }
	friend std::ostream& operator<< (std::ostream&, ForeignPassport&);
};

std::ostream&
operator<< (std::ostream& os, Passport& pass) {
	os << "\nName: " << pass.its_my_Name << ", Passport: " << pass.its_my_Series << pass.its_my_Passport_Number << std::endl;
	return os;
}

void
ForeignPassport::Print(void)const {
	std::cout << "\nName: " << its_my_Name << ", Interior Passport: " << its_my_Series << its_my_Passport_Number
		<< "Visas:\n";
	int i = 0;
	for (Visa x : visas)
		std::cout << ++i << " country: " << x.Country << ", expiration: " << x.Expiration << std::endl;
}

std::ostream&
operator<< (std::ostream& os, ForeignPassport& pass) {
	os << "\nName: " << pass.its_my_Name << ", Passport: " << pass.its_my_Series << pass.its_my_Passport_Number << std::endl;
	int i = 0;
	for (Visa x : pass.visas)
		os << ++i << " country: " << x.Country << ", expiration: " << x.Expiration << std::endl;
	return os;
}