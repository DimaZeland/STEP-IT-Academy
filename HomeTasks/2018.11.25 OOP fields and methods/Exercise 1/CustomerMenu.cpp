#include<iostream>
#include<iomanip>
#include<string>
#include "BankAccount.h"

unsigned short int CustomerMenu::its_my_current_account = 0;
int CustomerMenu::its_my_accounts_value = 0;

CustomerMenu::CustomerMenu() {
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield); // left alignment
    std::cout.precision(2); // a number of simbols after comma
    std::cout.setf(std::ios_base::showpoint); // display decimal points
    std::cout.setf(std::ios_base::fixed); // display show a fixed number of decimal places
}

bool
CustomerMenu::Deposit_replenishment() {
    double sum = 0;
    do {
        std::cout << "\nAccount balance " << Clients[its_my_current_account - 1].its_my_deposit << ' '
                  << Clients[its_my_current_account - 1].its_my_currency_name << '\n';
        std::cout << "\nPlease enter the refill amount <" << Clients[its_my_current_account - 1].its_my_currency_name
                  << "> or press <0> to exit: ";
        std::cin >> sum;
        system("cls");
        if (0 == sum) { // exit
            return false;
        } else if (sum > 0) { // succesful deposit replenishment
            Clients[its_my_current_account - 1].Set_deposit(sum);
            std::cout << "\nThe deposit replenishment was successful. Account balance "
                      << Clients[its_my_current_account - 1].its_my_deposit <<
                      ' ' << Clients[its_my_current_account - 1].its_my_currency_name << '\n';
            return true;
        } else { // unseccusful deposit replenishment
            std::cout << "\nInvalid input.\n";
        }
    } while (true);
}

void
CustomerMenu::Input_current_account() {
    if (its_my_current_account)
        std::cout << "\nCurrent bank account information:\n" <<
                  "Account number: " << Clients[its_my_current_account - 1].its_my_account_number <<
                  "\nDeposit currency: " << Clients[its_my_current_account - 1].its_my_currency_name <<
                  "\nBalance: " << Clients[its_my_current_account - 1].its_my_deposit << ' ' <<
                  Clients[its_my_current_account - 1].its_my_currency_name << '\n';
    else {
        std::cout << "\nCurrently there are no open accounts.\n";
        return;
    }
    std::cout << "\nTo enter another account, select the desired account from the existing ones:\n";
    if (!Show_transfer_accounts()) // There are no accounts in the system to switch
        return;
    unsigned short int cur_acc = 0;
    bool flag_cur_acc = false; // check to enter a valid account number to transfer funds

    while (true) {
        std::cout << "\nPlease enter your account number for future work: ";
        std::cin >> cur_acc;

        if (cur_acc == its_my_current_account) {  // if your account number is selected
            std::cout << "\nAt the moment you are already working with the introduction of a bank account number. " <<
                      "Please select one of the listed bank accounts.\n";
            continue;
        }
        for (BankAccount x: Clients)
            if (x.its_my_account_number == cur_acc) { // if you selected your number that is in the system
                flag_cur_acc = true;
                break;
            }
        if (flag_cur_acc) { // exit from the loop in case of successful input of the account number for switch
            its_my_current_account = cur_acc;
            break;
        } else
            std::cout << "\nInvalid input.\n";
    }

    std::cout << "\nThe ability to manage the selected bank account has been successfully granted.\n"
                 "Account number: " << Clients[its_my_current_account - 1].its_my_account_number <<
              "\nDeposit currency: " << Clients[its_my_current_account - 1].its_my_currency_name <<
              "\nBalance: " << Clients[its_my_current_account - 1].its_my_deposit << ' ' <<
              Clients[its_my_current_account - 1].its_my_currency_name << '\n';
}

double &
CustomerMenu::Money_conversion(double &sum, const unsigned short int &cur1, const unsigned short int &cur2) {
    if (cur1 != BankAccount::USD) // Stage 2: currency1 conversion to US dollars
        switch (cur1) {
            case 1: // UAH
                sum /= CustomerMenu::USDUAH;
                break;
            case 3: // EUR
                sum *= CustomerMenu::EURUSD;
                break;
            case 4: // RUB
                sum /= CustomerMenu::USDRUB;
                break;
            default:
                break; // USD
        }

    if (cur2 != BankAccount::USD) // Stage 2: conversion cur1 into cur2
        switch (cur2) {
            case 1: // UAH
                sum *= CustomerMenu::USDUAH;
                break;
            case 3: // EUR
                sum /= CustomerMenu::EURUSD;
                break;
            case 4: // RUB
                sum *= CustomerMenu::USDRUB;
                break;
            default:
                break; // USD
        }

    return sum;
}

bool
CustomerMenu::Open_account() {
    unsigned short int currency = 0;
    double deposit = 0;

    do { // choice of deposit currency
        std::cout << "\nMenu\n<1> - UAH\n<2> - USD\n<3> - EUR\n<4> - RUB\nEnter the desired deposit currency: ";
        std::cin >> currency;
        system("cls");
        if (currency > 0 and currency <= 4)
            break;
        else
            std::cout << "\nInvalid input. Please continue to be attentive.\n";
    } while (true);

    std::string cur_name = "\0";
    switch (currency) {
        case 1:
            cur_name = "UAH";
            break;
        case 2:
            cur_name = "USD";
            break;
        case 3:
            cur_name = "EUR";
            break;
        case 4:
            cur_name = "RUB";
            break;
        default:
            break;
    }

    do { // selection of the initial deposit amount
        std::cout << "\nEnter the desired amount of the initial deposit replenishment<" << cur_name << ">: ";
        std::cin >> deposit;
        if (deposit >= 0)
            break;
        else
            std::cout << "\nInvalid input. Please continue to be attentive.\n";
    } while (true);
    Clients.push_back(BankAccount(currency, deposit));
    ++CustomerMenu::its_my_accounts_value;
    its_my_current_account = Clients.size();
    system("cls");
    std::cout << "\nBank account opened successfully.\n" <<
              "Account number: " << Clients[its_my_current_account - 1].its_my_account_number <<
              "\nDeposit currency: " << Clients[its_my_current_account - 1].its_my_currency_name <<
              "\nBalance: " << Clients[its_my_current_account - 1].its_my_deposit << ' ' <<
              Clients[its_my_current_account - 1].its_my_currency_name << '\n';
    return true;
}

void
CustomerMenu::Show_current_account_info() {
    std::cout << "\nCurrent account is " << Clients[its_my_current_account - 1].its_my_account_number << '\n' <<
              "Deposit: " << Clients[its_my_current_account - 1].its_my_deposit << ' '
              << Clients[its_my_current_account - 1].its_my_currency_name << '\n';
}

bool
CustomerMenu::Show_transfer_accounts() const { // show the list of valid bank account for next many transfer
    if (Clients.size() > 1) {
        std::cout << std::setw(10) << "ID" << std::setw(10) << "Currency" << std::setw(10) << "Deposit" << std::endl;
        for (BankAccount x: Clients)
            if (x.its_my_account_number != Clients[its_my_current_account - 1].its_my_account_number) {
                std::cout << std::setw(10) << x.its_my_account_number << std::setw(10) << x.its_my_currency_name
                          << std::setw(10) << x.its_my_deposit << '\n';
            }
        return true;
    } else {
        std::cout << "\nThere are no other accounts in the system to transfer your own funds\n";
        return false;
    }
}

void
CustomerMenu::Transfer_between_accounts() {
    if (0 == its_my_current_account) {
        std::cout << "\nCurrently there are no one bank account in the system." <<
                  "Please open minimum two bank accounts, and then repeat the operation of transferring funds between accounts.\n";
        return;
    }
    if (1 == its_my_current_account and 1 == Clients.size()) {
        std::cout << "\nCurrently there are no other bank accounts available for transferring funds." <<
                  "Please open another bank account first, and then repeat the operation of transferring funds between accounts.\n";
        return;
    }

    unsigned short int refunding = 0;
    bool flag_refunding = false; // check to enter a valid account number to transfer funds
    while (true) {
        std::cout << "\nList of accounts available for transferring funds:\n";
        if (!Show_transfer_accounts()) // There are no accounts in the system to transfer funds
            return;
        std::cout << "\nPlease enter the account number from this list to transfer your own funds to it: ";
        std::cin >> refunding;
        system("cls");

        if (refunding == its_my_current_account) {  // if your account number is selected
            std::cout << "\nYou cannot transfer funds from your own account to your own account" <<
                      "by making a money transfer between accounts.\n";
            continue;
        }
        for (BankAccount x: Clients)
            if (x.its_my_account_number == refunding) { // if you selected your number that is in the system
                flag_refunding = true;
                break;
            }
        if (flag_refunding) // exit from the loop in case of successful input of the account number for transfer
            break;
        else
            std::cout << "\nInvalid input.\n";
    }
    std::cout << "\nMaximum available for transfer amount: " << Clients[its_my_current_account - 1].its_my_deposit <<
              ' ' << Clients[its_my_current_account - 1].its_my_currency_name << '\n';
    std::cout << "Please enter the amount of funds to transfer<"
              << Clients[its_my_current_account - 1].its_my_currency_name << ">:";
    double sum = 0;
    std::cin >> sum;
    system("cls");
    if (sum > Clients[its_my_current_account - 1].its_my_deposit or 0 > sum)
        sum = Clients[its_my_current_account - 1].its_my_deposit;

    Clients[its_my_current_account - 1].its_my_deposit -= sum; // withdrawmoney
    sum = Money_conversion(sum, Clients[its_my_current_account - 1].its_my_currency,
                           Clients[refunding - 1].its_my_currency); // convert sum to currency recipient
    Clients[refunding - 1].its_my_deposit += sum; // transfer of funds to the recipient

    std::cout << "\nThe transfer of funds between accounts was successful.\n" <<
              "Current information about the bank account of the sender of funds:\n"
              "Account number: " << Clients[its_my_current_account - 1].its_my_account_number <<
              "\nDeposit currency: " << Clients[its_my_current_account - 1].its_my_currency_name <<
              "\nBalance: " << Clients[its_my_current_account - 1].its_my_deposit << ' ' <<
              Clients[its_my_current_account - 1].its_my_currency_name << '\n' <<

              "Current information about the bank account of the beneficiary:\n"
              "Account number: " << Clients[refunding - 1].its_my_account_number <<
              "\nDeposit currency: " << Clients[refunding - 1].its_my_currency_name <<
              "\nBalance: " << Clients[refunding - 1].its_my_deposit << ' ' <<
              Clients[refunding - 1].its_my_currency_name << '\n';
}

bool
CustomerMenu::Withdraw_money() {
    double sum = 0;
    if (0 > its_my_current_account) {
        std::cout << "\nThere are currently no open accounts. Please open an account\n";
        return false;
    } else
        do {
            std::cout << "\nAvailable for removal " << Clients[its_my_current_account - 1].its_my_deposit << ' '
                      << Clients[its_my_current_account - 1].its_my_currency_name << '\n';
            std::cout << "\nPlease enter the amount to withdraw <"
                      << Clients[its_my_current_account - 1].its_my_currency_name << "> or press <0> to exit: ";
            std::cin >> sum;
            system("cls");
            if (0 == sum) { // exit
                return false;
            } else if (Clients[its_my_current_account - 1].its_my_deposit >= sum and sum > 0) { // succesful withdraw
                Clients[its_my_current_account - 1].Set_deposit(-sum);
                std::cout << "\nThe withdrawal operation was successful. Account balance "
                          << Clients[its_my_current_account - 1].its_my_deposit << ' ' <<
                          Clients[its_my_current_account - 1].its_my_currency_name << '\n';
                return true;
            } else { // unseccusful input
                std::cout << "\nInsufficient funds in the account.\n";
            }
        } while (true);
}