#include<iostream>
#include"MyClass.h"

unsigned int Menu::count = 0;

int main() {
    //Menu menu1;

    Menu *menu = Menu::CreateMenu();
    menu->SelectFunction();
    //delete menu;
    //menu = nullptr;

    system("pause");
    return 0;
}