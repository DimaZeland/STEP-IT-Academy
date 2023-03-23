//#pragma warning(disable :4996)
#include<string>
#include<memory>
#include "Person.h"

int Person::its_my_count;

std::string Person::its_my_school = "IT Step";

Person::Person(int birth, const char *name, const char *hobby) : itsMyBirth(birth) {
    ++its_my_count;
    Set_itsMyBirth(birth);
    Set_itsMyName(name);
    Set_itsMyHobby(hobby);
    std::cout << "\nConstructor called!\n";
    std::cout << "\nPersons: " << its_my_count << '\n';
}

Person::Person(const Person &obj) {
    Set_itsMyBirth(obj.itsMyBirth);
    Set_itsMyName(obj.itsMyName);
    Set_itsMyHobby(obj.itsMyHobby);
}

Person::~Person() {
    --its_my_count;
    delete[] itsMyName, itsMyHobby;
    itsMyName = itsMyHobby = nullptr;
    std::cout << "\nDestructor called!\n";
    std::cout << "\nPersons: " << its_my_count << '\n';
}

bool
Person::Set_Data() {
    std::cout << "\nEnter Birth: ";
    std::cin >> itsMyBirth;
    std::cout << "\nEnter Name: ";
    std::cin >> itsMyName;
    std::cout << "\nEnter hobby: ";
    std::cin >> itsMyHobby;
    return true;
}

void
Person::Show_Data() const {
    std::cout << "\nBirth: " << itsMyBirth << ", Name: " << itsMyName << ", Hobby: " << itsMyHobby << '\n';
}

bool
Person::Input_Name() {
    std::cout << "\nEnter Name: ";
    std::cin >> itsMyName;
    return true;
}

const char *
Person::Get_Name() const {
    return itsMyName;
}

bool
Person::Input_Hobby() {
    std::cout << "\nEnter hobby: ";
    std::cin >> itsMyHobby;
    return true;
}

const char *
Person::Get_Hobby() const {
    return itsMyHobby;
}

bool
Person::Input_Birth() {
    std::cout << "\nEnter Birth: ";
    std::cin >> itsMyBirth;
    if (2018 < itsMyBirth or 0 > itsMyBirth)
        itsMyBirth = 0;
    return true;
}

unsigned int
Person::Get_Birth() const {
    return itsMyBirth;
}

void
Person::Set_itsMyBirth(unsigned int a) {
    itsMyBirth = (2018 < itsMyBirth or 0 > itsMyBirth) ? 0 : a;
}

void
Person::Set_itsMyHobby(const char *a) {
    if (itsMyHobby != nullptr) {
        delete[] itsMyHobby;
        itsMyHobby = nullptr;
    }
    int len = strlen(a);
    itsMyHobby = new char[len + 1];
    strcpy_s(itsMyHobby, len + 1, a);
}

void
Person::Set_itsMyName(const char *a) {
    if (itsMyName != nullptr) {
        delete[] itsMyName;
        itsMyName = nullptr;
    }
    int len = strlen(a);
    itsMyName = new char[len + 1];
    strcpy_s(itsMyName, len + 1, a);
}

void
Person::Input_school() {
    std::cout << "\nPlease enter new name of persons school: ";
    std::getline(std::cin, Person::its_my_school);
}