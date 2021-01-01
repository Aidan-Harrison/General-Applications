#ifndef StockSim_h
#define StockSim_h

#include <iostream>
#include "StockSetup.h"

namespace StockSim {
    extern bool simulating, positiveEvent, negativeEvent;
    extern const int marketCap; // Stocks cannot go higher than this
    extern int fluctuation, trajectory, event, days, months, years, timeCounter; // Have chance of event happen in certain range, then lock to that range
    extern std::string currentStock;
    extern int userInput;

    extern void PrintStocks();
}

#endif