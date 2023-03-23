#include<iostream>
#include"Builder.h"

int main() {
    Auto car("AA1111AA", 350, 60);
    try {
        car.SetNumber("AA111AX");
    }
    catch (Auto::InvalidNumber &e) {
        e.what();
    }
    try {
        car.SetCurrentSpeed(351);
    }
    catch (Auto::WrongSpeed &e) {
        e.what();
    }
    try {
        car.SetMaxSpeed(361);
    }
    catch (Auto::WrongMaxSpeed &e) {
        e.what();
    }
    try {
        car.CurrentSpeedIncrease(301);
    }
    catch (Auto::WrongSpeed &e) {
        e.what();
    }

    system("pause");
    return 0;
}