#include <iostream>
#include <string>
#include "Bank.h"
#include "Account.h"
#include "Global.h"

using namespace BankGlobal;
Bank bank;
Account account;

void Choose();
void Setup();

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

// Remove goto statements
void Banking(Account &account) {
retry:
    std::cout << "WELCOME TO THE BANK\n";
    std::cout << "Enter option:\n";
    std::cout << "1) Login \t 2) Exit\n";
    if(!account.loggedIn && loginAttempts <= 3) {
        std::cin >> userInput;
        if(userInput == 1) {
            system("cls");
            std::cout << "Enter pin: "; std::cin >> userInput;
            if(userInput == account.m_Pin)
                Application(account);
            else {
                std::cout << "Try Again!\n";
                loginAttempts++;
                goto retry;
            }
        }
        else if(userInput == 2) 
            return;
        else {
            std::cout << "Invalid input";
            goto retry;
        }
    }
    else if (!account.loggedIn && loginAttempts > 3) {
        std::cout << "You have made to many attempts!\n EXITING....";
        // Terminate program here
    }
    return;
}

void CreateAccount() {
    std::string name = "";
    short pin = 0;
    int accountBalance = 0;
    system("cls");
    std::cout << "Create an account\n";
    std::cout << "Account Name: "; std::cin >> name;
    std::cout << "PIN: "; std::cin >> pin;
    std::cout << "Account Balance: "; std::cin >> accountBalance;
    if(std::to_string(pin).length() != 4) {
        std::cout << "Pin must consist of 4 numbers, you have entered an invalid amount!\n Try Again: ";
        std::cin >> pin; // Fix
    }
    Account account{ name, pin, accountBalance };
    account.accounts.push_back(account);
    Choose();
}

void Choose() {
    std::cout << "Choose an option:\n";
    std::cout << "1) Use existing account \t 2) Create account\n";
    std::cin >> userInput;
    if (userInput == 1) {
        system("cls");
        for (unsigned int i = 0; i < account.accounts.size(); i++)
            std::cout << i << " ) " << account.accounts[i].m_AccountName << '\n';
        std::cin >> userInput;
        Banking(account.accounts[userInput]);
    }
    else
        CreateAccount();
}

int main() {
    Setup();
    return 0;
}

void Setup() {
    Account eAccount1{ "Kaiba", 8567, 15000 };
    Account eAccount2{ "Yugi", 6650, 2000 };
    account.accounts.push_back(eAccount1);
    account.accounts.push_back(eAccount2);
    Choose();
}