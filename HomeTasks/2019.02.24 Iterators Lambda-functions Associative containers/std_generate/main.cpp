#include <algorithm>
#include <iterator>
#include<iostream>
#include<vector>
//#include"Builder.h"

int main() {
	std::vector<int> FiboNumbers(30);
	int i = 0;

	std::generate(
		FiboNumbers.begin()
		, FiboNumbers.end()
		, [&]() {
		int value = 0;
		if (i < 2)
			value = 1;
		else
			value = FiboNumbers.at(i-1) + FiboNumbers.at(i-2);
		++i;
		return value;
		}
	);

	i = 0;
	for (auto x : FiboNumbers)
		std::cout << i++ << ' ' << x << '\n';

	system("pause");
	return 0;
}