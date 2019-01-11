#include<iostream>
#include"Passport.h"

int main() {
	Passport Alex ("Alex", "AAS", 22457);
	std::cout << "Passport owner info:" << Alex;
	Alex.Set_Name("Mickle");
	Alex.Set_Series("AAX");
	Alex.Set_Passport_Number(5649894);
	std::cout << "Passport owner info after rewrite:\n";
	Alex.Print();

	Visa USA{ "USA", "01.01.2050" }, UK{ "United Kingdom", "01.01.2060" };
	std::vector<Visa> v {USA, UK};
	ForeignPassport Antony(v,"Antony", "DFR", 65487);
	std::cout << "Foreign Passport owner info:" << Antony;
	Visa Canada{ "Canada", "01.01.2055" };
	Antony.Visa_push_back(Canada);
	std::cout << "Foreign Passport owner info after rewrite:\n";
	Antony.Print();
	
	system("pause");

	return 0;
}