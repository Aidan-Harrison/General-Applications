#ifndef Bank_h
#define Bank_h

#include <iostream>
#include <vector>
// #include "Account.h"

// Make singleton
class Bank {
private:
public:
    int pin = 0, tries = 0, bankAmount = 0, inputAmount = 0; // Move to private
    Bank() = default;
    ~Bank() = default;
    std::vector<std::string> companies{ "Amazon", "Steam", "GOG", "Epic", "Apple", "Subway" };
    inline int GetBankAmount() const { return bankAmount; }
};

#endif