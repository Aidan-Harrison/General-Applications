#include <iostream>
#include <string>
#include "Bank.h"
#include "Account.h"
#include "Global.h"

using namespace BankGlobal;
Bank bank;
Account account;
Account eAccount1{"Kaiba", 8567, 15000};

void Application(Account &account) {
    system("cls");
    account.loggedIn = true;
    std::cout << "Select an option:\n";
    std::cout << "1) View 2) Deposit\n";
    std::cout << "3) Withdraw 4) Statement\n";
    std::cout << "5) Exit\n";
    std::cout << "Option: "; std::cin >> userInput;
    switch(userInput) {
    case 1: account.View(account);            break;
    case 2: account.Deposit(bank, account);   break;
    case 3: account.Withdraw(bank, account);  break;
    case 4: account.Statement(bank, account); break;
    case 5:                                   return;
    }
}

void Banking(Account &account) {
    std::cout << "WELCOME TO THE BANK\n";
    std::cout << "Enter option:\n";
    std::cout << "1) Login \t 2) Exit\n";
    if(!account.loggedIn && loginAttempts <= 3) {
retry:
        std::cin >> userInput;
        if(userInput == 1) {
            system("cls");
            std::cout << "Enter pin: "; std::cin >> userInput;
        attempt:
            if(userInput == account.m_Pin) // Make equal to pin
                Application(account);
            else {
                std::cout << "Try Again!\n";
                loginAttempts++;
                goto attempt;
            }
        }
        else if(userInput == 2) 
            return;
        else {
            std::cout << "Invalid input";
            goto retry;
        }
    }
    return;
}

void CreateAccount(std::string name = "", short pin = 1111, int accountBalance = 1000) {
    std::cout << "Create an account\n";
retry:
    std::cout << "Account Name: "; std::cin >> name;
    std::cout << "PIN: "; std::cin >> pin;
    std::cout << "Account Balance: "; std::cin >> accountBalance;
    if(std::to_string(pin).length() != 4) { // See how this works with default parameters
        std::cout << "Pin must consist of 4 numbers, you have entered an invalid amount!\n";
        goto retry; // Seperate inputs like life sim
    }
    Account account{name, pin, accountBalance};
        // bank.accounts.push_back(account);
    Banking(account);
}

int main() {
    std::cout << "Choose an option:\n";
    std::cout << "1) Use existing account 2) Create account"; // Possibly have user made accounts appear here
    std::cin >> userInput;
    if (userInput == 1)
        Application(eAccount1);
    else
        CreateAccount();
    return 0;
}