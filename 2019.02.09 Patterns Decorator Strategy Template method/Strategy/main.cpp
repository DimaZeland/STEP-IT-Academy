#include<iostream>
#include<vector>
#include"Builder.h"

int main() {
	std::vector<std::string> buf{ "Football", "Hockey", "Chess29", "Voleyball", "American Fooball", "Chess21", "Snooker" };
	AlphabetSort alphabetList(buf);
	alphabetList.Sorting();
	std::cout << "\nAlphabet Sorting:\n";
	for (auto& x : alphabetList.GetContainer())
		std::cout << x << '\n';
	
	SizeSort sizeList(buf);
	sizeList.Sorting();
	std::cout << "\nSize Sorting:\n";
	for (auto& x : sizeList.GetContainer())
		std::cout << x << '\n';

	system("pause");
	return 0;
}