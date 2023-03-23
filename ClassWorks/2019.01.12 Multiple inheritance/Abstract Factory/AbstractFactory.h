#pragma once

// https://refactoring.guru/ru/design-patterns/abstract-factory
//++ singleTon for factory

#include<iostream>
#include<string>

class Button abstract;

class CheckBox abstract;

class WinButton : public Button;

class WinCheckBox : public CheckBox;

class MaxButton : public Button;

class MaxCheckBox : public CheckBox;


class GUIFactory abstract{
        public:
        virtual Button* CreateButton() abstract;
        virtual CheckBox* CreateCheckBox() abstract;
};

class WinFactory : public GUIFactory {
public:
    virtual Button *CreateButton() override final;

    virtual CheckBox *CreateCheckBox() override final;
};

class MacFactory : public GUIFactory {
public:
    virtual Button *CreateButton() override final;

    virtual CheckBox *CreateCheckBox() override final;
};

class Dog : public Animal {
public:
    Dog(std::string nick = "No Nick", unsigned int age = 1) : Animal(nick, age) {}

    std::string Sound(void) const override final;

    std::string Type(void) const override final;
};

