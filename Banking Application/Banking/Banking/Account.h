#ifndef Account_h
#define Account_h

#include <iostream>
#include <vector>
#include "Global.h"

class Account {
private:
    int m_Accountbalance, m_Pin;
public:
    bool loggedIn = false;
    int cashOnHand = 100;
    Account() = default;
    ~Account() = default;
    Account(int accountBalance, short pin)
        :m_Accountbalance(accountBalance), m_Pin(pin)
    {
    }

    void View();
    int Deposit(Bank &bank);
    void Withdraw(Bank &bank);
    std::vector<std::string> Statement();
};

int Account::Deposit(Bank &bank) { // Possibly add amount as arugment, same for withdraw()
retry:
    std::cout << "How much would you like to deposit?\n";
    std::cin >> userInput;
    if (userInput <= 250 && userInput > 0 && cashInHand > 0 && userInput < cashInHand) {
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
std::vector<std::string> Account::Statement() {
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