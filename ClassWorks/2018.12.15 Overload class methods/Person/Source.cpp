#include<iostream>
#include<vector>
#include<string>
#include"Person.h"

int main() {
    Person first{1980, "Bill\0", "Basketball\0"}, second{1985, "John\0", "Swimming\0"}, leader{1990, "Bobby",
                                                                                               "Bussiness"};
    std::vector <Person> Arr{first, second};
    Group MyGroup(leader, Arr, 2, "MyBestGroup");
    std::cout << "\nShow info about group:\n";
    std::cout << MyGroup << std::endl;

    std::cout << "\nmembers of the group, which are old then 35 years:\n";
    MyGroup.Show_Year(35);
    std::cout << "\The average age of group member are " << MyGroup.AverageYears() << " years\n";
    std::cout << "\nChange info about group member:\n";
    MyGroup.Set_member();
    std::cout << "\nChange info about group leader:\n";
    MyGroup.Set_leader();
    Person third{1967, "Ann\n", "Bussiness\0"};
    MyGroup.Person_push_back(third);
    //std::cout << "\ndelete one memeber of the group:";
    //MyGroup.Person_pop();

    system("pause");

    return 0;
}