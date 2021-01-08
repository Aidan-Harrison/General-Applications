#ifndef Account_h
#define Account_h

#include <iostream>
#include <vector>
#include "Bank.h"
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

    inline int GetBalance() const { return m_Accountbalance; }
    void View(Account &account);
    void Deposit(Bank &bank, Account &account);
    void Withdraw(Bank &bank, Account &account);
    void Statement(Bank &bank, Account &account) const;
};

#endif