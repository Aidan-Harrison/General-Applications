#include <iostream>

#include "Account.h"
#include "StockSim.h"

Account* account = new Account(250); // Construct with balance

void Menu();

int Account::TakeLoan() {
    while (1) {
        std::cout << "How much would you like to take?"; std::cin >> StockSim::userInput;
        if (StockSim::userInput > 1000) {
            std::cout << "That is too much of an amount\n";
        }
        if (StockSim::userInput <= 0) {
            std::cout << "That is too little of an amount\n";
        }
        else {
            std::cout << "Your previous balance was: " << account->m_AccountBalance << '\n';
            std::cout << "You are taking a loan of: " << StockSim::userInput << '\n';
            account->m_AccountBalance += StockSim::userInput;
            std::cout << "Making your new balance: " << account->m_AccountBalance << '\n';
            return account->m_AccountBalance;
        }
    }
}

void Account::Invest(Stocks &stock) {
    std::cout << "What stocks would you like to invest in?\n";
    stock.PrintStocks();
    std::cout << stock.numberOfCompanies + 1 << ") back";
    std::cin >> StockSim::userInput;
    if(StockSim::userInput != stock.numberOfCompanies + 1) {
        currentInvestmentsInt.push_back(stock.allStocks[StockSim::userInput].GetValue());
        currentInvestmentsBool.push_back(true);
        std::cout << "Enter amount to invest: "; std::cin >> StockSim::userInput; // Set true after
        account->m_AccountBalance -= StockSim::userInput;
        std::cout << "Your new balance is " << account->m_AccountBalance;
        AccountMenu(stock);
    }
    else if(StockSim::userInput == stock.numberOfCompanies + 1)
        AccountMenu(stock);
}

void Account::CurInvestments(Stocks &stock) {
    // Mark which stocks are being invested in before doing anything
    std::cout << "You are currently investing in:\n";
    for(unsigned int i = 0; i < currentInvestmentsInt.size(); i++)
        if(currentInvestmentsInt[i] == stock.allStocks[i].GetID())
            std::cout << stock.allStocks[i].GetName() << '\n';
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
    std::cin >> StockSim::userInput;
    switch(StockSim::userInput) {
        case 1: StockSim::amountToPayBack = account->TakeLoan(); break;
        case 2: account->Invest(stock);         break;
        case 3: account->CurInvestments(stock); break;
        case 4: account->DeleteAccount();       break;
        case 5: Menu();                         break;
    }
}

void Account::ProfitCalc(Stocks &s) {

}

void Account::DeleteAccount() { delete this; } // Check!