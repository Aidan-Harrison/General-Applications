#ifndef Bank_h
#define Bank_h

#include <iostream>
#include <vector>

class Bank {
private:
public:
    int pin = 0, tries = 0, bankAmount = 0, inputAmount = 0;
    Bank() = default;
    ~Bank() = default;
    std::vector<std::string> companies{ "Amazon", "Steam", "GOG", "Epic", "Apple", "Subway" };
};

#endif