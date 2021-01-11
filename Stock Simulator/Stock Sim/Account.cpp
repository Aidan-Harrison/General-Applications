#include <iostream>

#include "Account.h"
#include "StockSim.h"

using namespace StockSim;
Account* account = new Account(250); // Construct with balance

void Menu();

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

void Account::Invest(Stocks &stock) {
    std::cout << "What stocks would you like to invest in?\n";
    stock.PrintStocks();
    std::cout << stock.numberOfCompanies + 1 << ") back";
    std::cin >> userInput;
    if(userInput != stock.numberOfCompanies + 1) {
        currentInvestmentsInt.push_back(stock.allStocks[userInput].m_StockID);
        currentInvestmentsBool.push_back(true);
        std::cout << "Enter amount to invest: "; std::cin >> userInput; // Set true after
        account->m_AccountBalance -= userInput;
        std::cout << "Your new balance is " << account->m_AccountBalance;
        AccountMenu(stock);
    }
    else if(userInput == stock.numberOfCompanies + 1)
        AccountMenu(stock);
}

void Account::CurInvestments(Stocks &stock) {
    // Mark which stocks are being invested in before doing anything
    std::cout << "You are currently investing in:\n";
    for(unsigned int i = 0; i < currentInvestmentsInt.size(); i++)
        if(currentInvestmentsInt[i] == stock.allStocks[i].m_StockID)
            std::cout << stock.allStocks[i].companyName << '\n';
    std::cout << "Press a key to return: "; 
    std::cin.get();
    std::cin.get();
    AccountMenu(stock);
}

void Account::AccountMenu(Stocks &stock) {
    system("cls");
    std::cout << "Welcome to your account\n";
    std::cout << "1) Take loan\n";
    std::cout << "2) Invest\n";
    std::cout << "3) Current Investments\n";
    std::cout << "4) Delete account\n";
    std::cout << "5) Back\n";
    std::cin >> userInput;
    switch(userInput) {
    case 1: account->TakeLoan();            break;
    case 2: account->Invest(stock);         break;
    case 3: account->CurInvestments(stock); break;
    case 4: account->DeleteAccount();       break;
    case 5: Menu();                         break;
    default: return;
    }
}

void Account::DeleteAccount() { delete account; }