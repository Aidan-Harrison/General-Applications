#include "VendingMachine.h"

Machine::Machine(unsigned short stock) 
    :stock(stock)
{
}

Machine::~Machine() {};

void Machine::Fill(const unsigned int quantity) {
    stock += quantity;
}

void Machine::Sell(const unsigned int quantity) {
    stock -= quantity;
}