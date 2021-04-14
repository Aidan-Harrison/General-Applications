#ifndef Account_h
#define Account_h

#include <vector>
#include <iostream>

#include "Stocks.h"

class Account {
private:
    int m_AccountBalance = 0, m_Loss = 0; // Amount of profit which could have been made
public:
    Account() = default;
    Account(short accountBalance)
        :m_AccountBalance(accountBalance)
    {
    }
    ~Account() = default;
    std::vector<bool> currentInvestmentsBool{}; // Company names, access member variables
    // Use bool and assign each element of index equal to stock vector. True if investing, false otherwise
    // Then when getting the names refer to current element and pass that to the stock vector
    std::vector<int> currentInvestmentsInt{};

    int GetBalance() const { return m_AccountBalance; }
    int GetLoss() const { return m_Loss; }
    void AccountMenu(Stocks &stock);
    void DeleteAccount();
    int TakeLoan();
    void Invest(Stocks& stock);
    void CurInvestments(Stocks &stock);
    void ProfitCalc(Stocks &s);
};

#endif