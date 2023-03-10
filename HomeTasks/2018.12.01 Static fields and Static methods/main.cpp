#include<iostream>
#include"Student.h"
#include"Waters.h"

int main() {
	// Exercise 1
	std::cout << "\nExercise 1:\n";
	Student one("Dima");
	one.Get_surname();
	one.Set_surname("Alex");
	one.Get_surname();
	one.Push_rating(12);
	one.Push_rating(10);
	one.Push_rating(8);
	one.Push_rating(5);
	std::cout << one;
	Student two(one);
	two.Change_rating();
	std::cout << two;

	// Exercise 2
	std::cout << "\nExercise 2:\n";
	Waters first("Mirror", Waters::Water_type::rates, 100, 50, 15);
	Waters second("Black Sea", Waters::Water_type::sea, 1000000, 50000, 1500);
	Waters third("White lake", Waters::Water_type::lake, 10000, 5000, 150);
	std::cout << "\nMirror depth is " << first.Get_depth();
	first.Set_depth(25);
	std::cout << "\nNow Mirror depth is " << first.Get_depth();

	std::cout << "\nBlack Sea lenght is " << second.Get_length();
	second.Set_length(995000);
	std::cout << "\nNow Black Sea lenght is " << second.Get_length();

	std::cout << "\nWhite lake wighth is " << third.Get_width();
	third.Set_width(5500);
	std::cout << "\nNow White lake lenght is " << third.Get_width();

	std::cout << "\nMirror volume is " << first.Get_volume();
	std::cout << "\nBlack Sea  square is " << second.Get_square();

	std::cout << "\nBlack sea and White lake are relate to one type of reservoir: " << std::boolalpha << Waters::Same_type(second, third);

	std::cout << "/nThe Black Sea is larger than the white lake? " << std::boolalpha << Waters::Comparison_of_areas(second, third);

	Waters four("Red Sea", Waters::Water_type::sea, 50000, 10000, 2000);
	std::vector<Waters> Arr{ first,second, third, four };
	std::cout << "\nThe largest area of the reservoir is " << Waters::Get_biggest_waters(Arr, Waters::Water_type::sea);

	system("pause");
	return 0;
}