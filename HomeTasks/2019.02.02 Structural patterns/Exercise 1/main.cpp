#include<iostream>
#include"Builder.h"

using namespace std;

int main() {
    std::vector <Score> Clients{Score(1, "Admin", 100), Score(2, "user", 200), Score(3, "Worker", 300)};

    Bank bank(Clients);
    Bankomat KyivskaStreet(&bank);

    Client Alex("Worker", 3);
    std::cout << "\nAlex bank score balance is " << KyivskaStreet.getBalance(Alex.GetNumber(), Alex.GetPassword())
              << " $\n";
    std::cout << "\nAlex bank score new balance after withdraw 100$ is: "
              << KyivskaStreet.Withdraw(Alex.GetPassword(), 100, Alex.GetNumber()) << " $\n";

    Client AlexJunior("user", 2);
    std::cout << "\nAlexJunior bank score balance is "
              << KyivskaStreet.getBalance(AlexJunior.GetNumber(), AlexJunior.GetPassword()) << " $\n";
    std::cout << "\nAlexJunior bank score new balance after withdraw 50$ is: "
              << KyivskaStreet.Withdraw(AlexJunior.GetPassword(), 50, AlexJunior.GetNumber()) << " $\n";

    system("pause");
    return 0;
}