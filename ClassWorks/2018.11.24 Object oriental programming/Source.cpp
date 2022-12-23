#include<iostream>
#include<memory>
#include"Person.h"



Person Global;

int main() {
	{
	std::shared_ptr<Person> Smart(new Person);
	}


	Person* pDynamic = new Person;
	{
		Person Dima;
		Dima.Set_Data();
		Dima.Show_Data();
		Dima.Input_Birth();
		std::cout << "\nBirth: " << Dima.Get_Birth() << '\n';
		Dima.Input_Name();
		std::cout << "\nName: " << Dima.Get_Name() << '\n';
		Dima.Input_Hobby();
		std::cout << "\nHobby: " << Dima.Get_Hobby() << '\n';
	}

	delete pDynamic;
	pDynamic = nullptr;
	system("pause");
	return 0;
}
