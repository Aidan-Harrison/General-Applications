#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "Bank.h"
#include "Account.h"
#include "Global.h"

using namespace BankGlobal;
Bank bank;
Account account;

void Choose();

void Setup() {
                      // Name | PIN | Balance
    Account eAccount1{ "Kaiba", 8567, 15000 };
    Account eAccount2{ "Yugi", 6650, 2000 };
    account.accounts.push_back(eAccount1);
    account.accounts.push_back(eAccount2);
}

void Application(Account &account) {
    system("cls");
    std::cout << "====WELCOME TO THE BANK====\n" <<
                 "Select an option:\n" <<
                 "1) View Balance  2) Deposit\n"   <<
                 "3) Withdraw      4) Statement\n" <<
                 "5) Exit\n";
    std::cout << "Option: "; std::cin >> userInput;
    switch(userInput) {
        case 1: account.View(account);         
        case 2: account.Deposit(bank, account); 
        case 3: account.Withdraw(bank, account); 
        case 4: account.Statement(bank, account);
        case 5: Choose();
    }
}

void Login(Account& account) {
    if (!account.loggedIn && loginAttempts <= 3) {
        system("cls");
        while (1) {
            std::cout << "Enter pin: "; std::cin >> userInput;
            if (userInput == account.m_Pin) {
                account.loggedIn = true;
                Application(account);
            }
            else {
                std::cout << "Try Again!\n";
                loginAttempts++;
            }
            if (!account.loggedIn && loginAttempts > 3) {
                std::cout << "You have made to many attempts!\n EXITING....";
                std::this_thread::sleep_for(std::chrono::seconds(2));
                Choose();
            }
        }
    }
}

// Remove goto statements
void Banking(Account &account) {
    std::cout << "WELCOME TO THE BANK\n" <<
                 "Enter option:\n";
    std::cout << "1) Login \t 2) Back\n";
    std::cin >> userInput;
    if (userInput == 1)
        Login(account);
    else if(userInput == 2)
        Choose();
}

void CreateAccount() {
    system("cls");
    std::string name = "";
    short pin = 0;
    long accountBalance = 0;
    std::cout << "Create an account\n";
    std::cout << "Account Name: "; std::cin >> name;
    std::cout << "PIN: "; std::cin >> pin;
    std::cout << "Account Balance: "; std::cin >> accountBalance;
    if(std::to_string(pin).length() != 4) {
        while (1) {
            std::cout << "Pin must consist of 4 numbers, you have entered an invalid amount!\n Try Again: ";
            std::cin >> pin;
            if(std::to_string(pin).length() == 4)
                break;
        }
    }
    Account account{ name, pin, accountBalance };
    account.accounts.push_back(account); // Fix
    Choose();
}

void Choose() {
    system("cls");
    std::cout << "Choose an option:\n" <<
                 "1) Use existing account \t 2) Create account\n";
    std::cin >> userInput;
    if (userInput == 1) {
        system("cls");
        for (unsigned int i = 0; i < account.accounts.size(); i++)
            std::cout << i << ") " << account.accounts[i].GetName() << '\n';
        std::cin >> userInput;
        Login(account.accounts[userInput]);
        // Banking(account.accounts[userInput]);
    }
    else
        CreateAccount();
}

int main() {
    Setup();
    Choose();
    return 0;
}
