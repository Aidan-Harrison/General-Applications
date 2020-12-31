#ifndef StockSimulator_h
#define StockSimulator_h

#include <iostream>

// Global Variables
namespace StockSim {
    extern bool simulating, positiveEvent, negativeEvent;
    extern const int marketCap; // Stocks cannot go higher than this
    extern int fluctuation, trajectory, event, months, years, timeCounter; // Have chance of event happen in certain range, then lock to that range
    extern std::string currentStock;
    extern int userInput;
}

#endif