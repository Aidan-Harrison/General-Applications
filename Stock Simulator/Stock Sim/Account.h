#ifndef Account_h
#define Account_h

#include <vector>
#include <iostream>

#include "Stocks.h"

class Account {
private:
    int m_AccountBalance = 0;
public:
    Account() = default;
    Account(short accountBalance)
        :m_AccountBalance(accountBalance)
    {
    }
    ~Account() = default;
    std::vector<bool> currentInvestments{}; // Company names, access member variables
    // Use bool and assign each element of index equal to stock vector. True if investing, false otherwise
    // Then when getting the names refer to current element and pass that to the stock vector
    std::vector<bool> currentInvestmentsInt{};

    int GetBalance() const { return m_AccountBalance; }
    void DeleteAccount();
    int TakeLoan();
    void Invest(std::vector<Stocks>& stocks, Stocks& stock);
    void CurInvestments(std::vector<Stocks>& stocks);
};

#endif