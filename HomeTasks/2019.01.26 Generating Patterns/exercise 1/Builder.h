#pragma once

#include<iostream>
#include<string>

class Weapon {
protected:
    std::string name = "Noname";
    int damage = 0;
    int kalibr = 1;
public:
    Weapon(std::string q = "Noname", int w = 0, int e = 1) : name(q), damage(w), kalibr(e) {}

    virtual Weapon *clone()

    abstract;

    friend std::ostream &operator<<(std::ostream &os, Weapon *wp);
};

class Pistolet : public Weapon {
public:
    Pistolet(std::string q = "pistolet", int w = 50, int e = 5) : Weapon(q, w, e) {}

    Pistolet(Pistolet &p) {
        this->name = p.name;
        damage = p.damage;
        kalibr = p.kalibr;
    }

    Pistolet *clone() { return new Pistolet(*this); }
};

class Avtomat : public Weapon {
public:
    Avtomat(std::string q = "avtomat", int w = 100, int e = 10) : Weapon(q, w, e) {}

    Avtomat(Avtomat &p) {
        this->name = p.name;
        damage = p.damage;
        kalibr = p.kalibr;
    }

    Avtomat *clone() { return new Avtomat(*this); }
};

std::ostream &operator<<(std::ostream &os, Weapon *wp) {
    os << "\nWeapon name: " << wp->name << ", kalibr:  " << wp->kalibr << ", damage: " << wp->damage << "\n";
    return os;
}