#include "StockSim.h"

namespace StockSim {
    bool simulating = true, positiveEvent = false, negativeEvent = false;
    const int marketCap = 2000; // Stocks cannot go higher than this
    int fluctuation = 5, trajectory = 1, event = 0, days = 0, months = 0, years = 0, timeCounter = 0; // Have chance of event happen in certain range, then lock to that range
    std::string currentStock = ""; // Change to object?
    int userInput, amountToPayBack = 0;
}