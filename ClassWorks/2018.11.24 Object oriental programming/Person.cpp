//#pragma warning(disable :4996)
#include "Person.h"

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
    strcpy_s(itsMyHobby, Person::SIZE, a);
}

void
Person::Set_itsMyName(const char *a) {
    strcpy_s(itsMyName, Person::SIZE, a);
}

Person::Person(int birth, const char *name, const char *hobby) : itsMyBirth(birth) {
    Set_itsMyBirth(birth);
    Set_itsMyName(name);
    Set_itsMyHobby(hobby);
    std::cout << "\nConstructor called!\n";
}
