#include "VendingMachine.h"

Machine::Machine(unsigned int stock) 
    :stock(stock)
{
}

void Machine::Fill(const unsigned int quantity) {
    stock += quantity;
}

void Machine::Sell(const unsigned int quantity) {
    stock -= quantity;
}