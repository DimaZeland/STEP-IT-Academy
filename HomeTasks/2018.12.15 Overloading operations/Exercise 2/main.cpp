#include<iostream>
#include"Tv.h"

int main() {
    Tv Sony;
    Remote Tele;

    Sony.Power();
    Sony.incVolume();
    Sony.nextChannel();
    Tele.goToChannel(Sony, 48);
    Tele.prevChannel(Sony);
    Tele.incVolume(Sony);
    Tele.power(Sony);

    system("pause");

    return 0;
}