#include "Account.h"

void Application(Account &account);

void Account::View(Account &account) {
    std::cout << "Your account:\n";
    std::cout << "Balance: " << GetBalance() << '\n';
    std::cout << "Press a key to go back: "; std::cin.get();
    std::cin.get();
    Application(account);
}

void Account::Deposit(Bank& bank, Account &account) { // Possibly add amount as arugment, same for withdraw()
retry:
    std::cout << "How much would you like to deposit?\n";
    std::cin >> userInput;
    if (userInput <= 250 && userInput > 0 && cashOnHand > 0 && userInput < cashOnHand) {
        bank.bankAmount += userInput;
        account.m_Accountbalance -= userInput;
        std::cout << "Depositied " << userInput;
    }
    else {
        std::cout << "That number is invalid, try again\n";
        goto retry;
    }
    Application(account);
}

void Account::Withdraw(Bank& bank, Account &account) {
    std::cout << "How much would you like to withdraw?\n";
    std::cin >> userInput;
    if (account.m_Accountbalance - userInput <= 0) {
        std::cout << "That is too much to withdraw\n";
        std::cin >> userInput;
    }
    else
        bank.bankAmount -= userInput;
    Application(account);
}

// Randomize transactions
void Account::Statement(Bank& bank, Account &account) const {
    int transactionAmount = 0, totalTransaction = 0;
    int amount = 0, transSize = 0; // Random value associated with transaction
    srand(time(0));
    transSize = rand() % bank.companies.size();
    if (transSize == 0) { // Optimisation | avoid ever doing the loop if there is nothing to loop through
        std::cout << "You have not made any purchases\n Press any key to return";
        std::cin.get(); std::cin.get();
        Application(account);
    }
    std::cout << "Statement:\n";
    for (unsigned int i = 0; i < transSize; i++) {
        transactionAmount = rand() % 20;
        totalTransaction += transactionAmount;
        std::cout << bank.companies[i] << " | " << transactionAmount + 1 << '\n'; // '+1' prevents it from being 0, and sets max to 20
    }
    if (totalTransaction > account.m_Accountbalance)
        std::cout << "Overflow\n";
    std::cout << "Press any key to return: "; 
    std::cin.get(); std::cin.get();
    Application(account);
}