#include <iostream>

#include "Account.h"
#include "StockSim.h"

using namespace StockSim;
Account* account = new Account(250); // Construct with balance

// Prototypes
void AccountMenu(std::vector<Stocks> &stocks, Stocks &stock);

void Account::DeleteAccount() {
    delete account;
}

int Account::TakeLoan() {
    static int loanAmount = 1000; // Cannot take anymore than this
retry:
    std::cout << "How much would you like to take?"; std::cin >> userInput;
    if (userInput > 1000) {
        std::cout << "That is too large of an amount\n"; goto retry;
    }
    else if (userInput <= 0) {
        std::cout << "That is too little of an amount\n"; goto retry;
    }
    else {
        std::cout << "Your previous balance was: " << account->m_AccountBalance << '\n';
        std::cout << "You are taking a loan of: " << userInput << '\n';
        account->m_AccountBalance += userInput;
        std::cout << "Making your new balance: " << account->m_AccountBalance << '\n';
    }
    return account->m_AccountBalance;
}

void Account::Invest(std::vector<Stocks> &stocks, Stocks &stock) {
    std::cout << "What stocks would you like to invest in?\n";
    PrintStocks();
    std::cin >> userInput;
    if (userInput != stock.numberOfCompanies + 1)
        currentInvestmentsInt[userInput] = stocks[userInput].stockID; // Check!
    else if (userInput == stock.numberOfCompanies + 1)
        AccountMenu(stocks, stock);
}

void Account::CurInvestments(std::vector<Stocks> &stocks) {
    // Mark which stocks are being invested in before doing anything
    for (int i = 0; i < stocks.size(); i++)
        if (currentInvestmentsInt[i] == stocks[i].stockID)
            std::cout << stocks[i].companyName;
}

void AccountMenu(std::vector<Stocks> &stocks, Stocks &stock) {
    system("cls");
    std::cout << "Welcome to your account\n";
    std::cout << "1) Take loan\n";
    std::cout << "2) Delete account\n";
    std::cin >> userInput;
    switch (userInput)
    {
    case 1:
        account->TakeLoan(); break;
    case 2:
        account->DeleteAccount(); break;
    case 3:
        account->Invest(stocks, stock); break;
    default:
        return;
    }
}