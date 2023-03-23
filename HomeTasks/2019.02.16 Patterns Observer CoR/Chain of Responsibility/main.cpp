//#include<algorithm>
//#include<ctime>
#include<iostream>
#include<string>
//#include<vector>
#include"Builder.h"

int main() {
    USD100 ATMKyivskaStreet(100, 200, 500, 2000);
    unsigned int sum = 0;

    do {
        std::cout << "\nPlease enter the amount to withdraw or <0> to exit: ";
        std::cin >> sum;
        if (0 == sum)
            break;
        ATMKyivskaStreet.MoneyPayment(sum);
    } while (true);

    system("pause");
    return 0;
}