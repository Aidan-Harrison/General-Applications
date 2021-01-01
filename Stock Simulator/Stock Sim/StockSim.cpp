#include "StockSim.h"

namespace StockSim {
    bool simulating = true, positiveEvent = false, negativeEvent = false;
    const int marketCap = 2000; // Stocks cannot go higher than this
    int fluctuation = 5, trajectory = 1, event = 0, days = 0, months = 0, years = 0, timeCounter = 0; // Have chance of event happen in certain range, then lock to that range
    std::string currentStock = "";
    int userInput;

    void PrintStocks() { // Unified printing function | Move to be available globally
        for (unsigned int i = 0; i < stock.allStocks.size(); i++) // should not really start from 1 but leave for now
            std::cout << i + 1 << ") " << stock.allStocks[i].companyName << '\n';
    }
}