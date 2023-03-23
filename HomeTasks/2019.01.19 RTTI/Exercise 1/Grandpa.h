#pragma once

#include<string>
#include<iostream>


class Grandpa {
private:
    std::string name = "Grandpa";
public:
    Grandpa(std::string Name = "Grandpa") : name(Name) {};

    virtual ~Grandpa() {}

    inline virtual void sleep() const { std::cout << typeid(*this).name() + 5 << " sleep.\n"; }

    inline virtual void print() const { this->sleep(); }
};

class Daddy : public Grandpa {
public:
    Daddy(std::string Name = "Daddy") : Grandpa(Name) {}

    inline virtual void walk() const { std::cout << typeid(*this).name() + 5 << " walk.\n"; }

    inline virtual void print() const {
        this->sleep();
        this->walk();
    }
};

class Son : public Daddy {
public:
    Son(std::string Name = "Son") : Daddy(Name) {}

    inline virtual void play() const { std::cout << typeid(*this).name() + 5 << " play.\n"; }

    inline virtual void print() const {
        this->sleep();
        this->walk();
        this->play();
    }
};