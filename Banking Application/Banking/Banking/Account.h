#ifndef Account_h
#define Account_h

#include <iostream>
#include <vector>
#include "Global.h"

using namespace BankGlobal;

class Account {
private:
    std::string m_AccountName;
    int m_Accountbalance = 0;
public:
    int m_Pin = 0, cashOnHand = 100;
    bool loggedIn = false;
    Account() = default;
    ~Account() = default;
    Account(std::string name, short pin, int accountBalance)
        :m_AccountName(name), m_Pin(pin), m_Accountbalance(accountBalance)
    {
    }

    int GetBalance() const { return m_Accountbalance; }
    void View(Account &account);
    int Deposit(Bank &bank);
    void Withdraw(Bank &bank);
    std::vector<std::string> Statement(Bank &bank);
};

void Account::View(Account &account) {
    std::cout << "Your account:\n";
    std::cout << "Balance: " << GetBalance();
}

int Account::Deposit(Bank &bank) { // Possibly add amount as arugment, same for withdraw()
retry:
    std::cout << "How much would you like to deposit?\n";
    std::cin >> userInput;
    if (userInput <= 250 && userInput > 0 && cashOnHand > 0 && userInput < cashOnHand) {
        bank.bankAmount += userInput;
        std::cout << "Depositied " << userInput;
    }
    else {
        std::cout << "That number is invalid, try again\n";
        goto retry;
    }
    return bank.bankAmount;
}

void Account::Withdraw(Bank &bank) {
    std::cout << "How much would you like to withdraw?\n";
    std::cin >> userInput;
    if (bank.bankAmount - userInput <= 0) {// Add actual loop
        std::cout << "That is too much to withdraw";
        std::cin >> userInput;
    }
    else
        bank.bankAmount - userInput;
}

// Randomize transactions
std::vector<std::string> Account::Statement(Bank &bank) {
    std::vector<std::string> transactions{};
    int amount = 0; // Random value associated with transaction
    int transSize = 0;
    srand(time(0));
    transSize = rand() % bank.companies.size();
    for (int i = 0; i < transSize; i++)
        transactions.push_back(bank.companies[i]);
    std::cout << "Statement:\n";
    for (int i = 0; i < transactions.size(); i++)
        std::cout << transactions[i] << '\n';
    return transactions;
}

#endif