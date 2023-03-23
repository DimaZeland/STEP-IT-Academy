#include<iostream>
#include<memory>
#include<string>
#include"Person.h"

//void Func(Person);
//
//Person Global;

int main() {
    /*{
        std::shared_ptr<Person> Smart(new Person);
    }

    std::cout << "Person: " << Person::Get_count() << '\n';
    std::cout << "\nPerson school: " << Person::Get_school() << '\n';
    Person::Input_school();
    std::cout << "\nNew Person school: " << Person::Get_school() << '\n';

    std::shared_ptr<int> itsMyName2(new int);

    Func(22);

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
    pDynamic = nullptr;*/

    Person first{1980, "Bill\0", "Basketball\0"}, second{1985, "John\0", "Swimming\0"}, leader{1990, "Bobby",
                                                                                               "Bussiness"};
    Person Arr[2]{first, second};
    Group MyGroup(leader, Arr, 2, "MyBestGroup");
    std::cout << MyGroup << std::endl;

    system("pause");
    return 0;
}

//void Func(Person obj) {
//
//	std::cout << "\nFunc: " << obj.Get_Name() << std::endl;
//}
