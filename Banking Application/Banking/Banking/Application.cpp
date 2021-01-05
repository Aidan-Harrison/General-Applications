#include <iostream>
#include "Bank.h"
#include "Account.h"
#include "Global.h"

using namespace BankGlobal;
Bank bank;
Account account;

void Application() {
    account.loggedIn = true;
    std::cout << "Select an option:\n";
    std::cout << "1) View 2) Deposit\n";
    std::cout << "3) Withdraw 4) Statement\n";
    std::cout << "5) Exit\n";
    std::cout << "Option: "; std::cin >> userInput;
    switch(userInput) {
    case 1: account.View();          break;
    case 2: account.Deposit(bank);   break;
    case 3: account.Withdraw(bank);  break;
    case 4: account.Statement();     break;
    case 5:                          return;
    }
}

void Banking() {
    std::cout << "WELCOME TO THE BANK\n";
    std::cout << "Enter option:\n";
    std::cout << "1) Login 2) Exit\n";
    if(!account.loggedIn && loginAttempts <= 3) {
retry:
        std::cin >> userInput;
        if(userInput == 1) {
            system("cls");
            std::cout << "Enter pin: "; std::cin >> userInput;
        attempt:
            if(userInput == 4357) // Make equal to pin
                Application();
            else {
                std::cout << "Try Again!\n";
                loginAttempts++;
                goto attempt;
            }
        }
        else if(userInput == 2) return;
        else {
            std::cout << "Invalid input";
            goto retry;
        }
    }
    return;
}

int main() {
    Banking();
    return 0;
}