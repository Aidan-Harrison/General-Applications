#ifndef Account_h
#define Account_h

#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "Bank.h"

class Account {
private:
    int m_Accountbalance = 0;
    std::string m_AccountName;
public:
    int m_Pin = 0, cashOnHand = 100;
    bool loggedIn = false;
    Account() = default;
    ~Account() = default;
    Account(std::string name, short pin, int accountBalance)
        :m_AccountName(name), m_Pin(pin), m_Accountbalance(accountBalance)
    {
    }
    std::vector<Account> accounts{};

    inline int GetBalance() const { return m_Accountbalance; }
    std::string GetName() const { return m_AccountName; }
    void View(Account& account);
    void Deposit(Bank& bank, Account& account);
    void Withdraw(Bank& bank, Account& account);
    void Statement(Bank& bank, Account& account) const;
};

#endif