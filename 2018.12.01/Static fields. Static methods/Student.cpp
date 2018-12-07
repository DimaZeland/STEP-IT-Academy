#include<iostream>
#include<string>
#include"Student.h"

Student::Student(std::string surname) : its_my_surname(surname) {}

Student::Student(const Student& obj)
	: its_my_surname(obj.its_my_surname), its_my_rating(obj.its_my_rating), its_my_number_of_ratings(obj.its_my_rating.size()){}

Student::~Student() {}

std::ostream& operator<<(std::ostream& os, Student& obj) {
	os << "\nSurname: " << obj.its_my_surname << "\nRatings:\n";
	int i = 0;
	for (unsigned int x : obj.its_my_rating)
		os << ++i << ' ' << x << '\n';
	return os;
}

void
Student::Set_surname(std::string surname) {
	its_my_surname = surname;
}

void
Student::Change_rating() {
	std::cout << "\ncurrent rating\n";
	std::cout << *this;
	unsigned int number = 0, value = 1;

	while(true){ // selection of the evaluation number
	std::cout << "\nEnter the number of the grade you wish to edit:";
	std::cin >> number;
	if (number-- > its_my_rating.size()) {
		std::cout << "Array out of the vector.";
		continue;
	}
	else
		break;
	}

	while (true) { // entering a new evaluation value
		std::cout << "\nEnter a new evaluation value:";
		std::cin >> value;
		if (value < its_my_min_rating or value > its_my_max_rating) {
			std::cout << "Entering invalid evaluation value.";
			continue;
		}
		else
			break;
	}

	its_my_rating.at(number) = value;
}