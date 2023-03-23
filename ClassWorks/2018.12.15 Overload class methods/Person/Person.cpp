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
    Set_SecondName(hobby);
    //std::cout << "\nConstructor called!\n";
    //std::cout << "\nPersons: " << its_my_count << '\n';
}

Person::Person(const Person &obj) {
    Set_itsMyBirth(obj.itsMyBirth);
    Set_itsMyName(obj.itsMyName);
    Set_SecondName(obj.itsMySecondName);
}

Person::~Person() {
    --its_my_count;
    delete[] itsMyName, itsMySecondName;
    itsMyName = itsMySecondName = nullptr;
    //std::cout << "\nDestructor called!\n";
    //std::cout << "\nPersons: " << its_my_count << '\n';
}

bool
Person::Set_Data() {
    std::cout << "\nEnter Birth: ";
    std::cin >> itsMyBirth;
    std::cout << "\nEnter Name: ";
    std::cin >> itsMyName;
    std::cout << "\nEnter SecondName: ";
    std::cin >> itsMySecondName;
    return true;
}

void
Person::Show_Data() const {
    std::cout << "\nBirth: " << itsMyBirth << ", Name: " << itsMyName << ", SecondName: " << itsMySecondName << '\n';
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
Person::Input_SecondName() {
    std::cout << "\nEnter SecondName: ";
    std::cin >> itsMySecondName;
    return true;
}

const char *
Person::Get_SecondName() const {
    return itsMySecondName;
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
    itsMyBirth = (2018 < a or 0 > a) ? 0 : a;
}

void
Person::Set_SecondName(const char *a) {
    if (itsMySecondName != nullptr) {
        delete[] itsMySecondName;
        itsMySecondName = nullptr;
    }
    int len = strlen(a);
    itsMySecondName = new char[len + 1];
    strcpy_s(itsMySecondName, len + 1, a);
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

Person &
Person::operator=(const Person &other) {
    if (this != &other) {
        Set_itsMyBirth(other.itsMyBirth);
        Set_itsMyName(other.itsMyName);
        Set_SecondName(other.itsMySecondName);
    }
    return *this;
}

std::ostream &
operator<<(std::ostream &os, const Person &one) {
    os << "\nBirth: " << one.itsMyBirth << ", first name: " << one.itsMyName << ", second name: " << one.itsMySecondName
       << std::endl;
    return os;
}

std::istream &
operator>>(std::istream &is, Person &one) {
    int Birth = 0;
    char f_name[50] = "\0", s_name[50] = "\0";
    std::cout << "\nEnter date of birth: ";
    is >> Birth;
    one.Set_itsMyBirth(Birth);
    std::cout << "\nEnter first name: ";
    is >> f_name;
    one.Set_itsMyName(f_name);
    std::cout << "\nEnter first name: ";
    is >> s_name;
    one.Set_SecondName(s_name);
    return is;
}
