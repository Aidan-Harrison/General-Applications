#ifndef StockSetup_h
#define StockSetup_h

#include "Stocks.h"
#include "Account.h"

Stocks stock; // Instance of stocks for intialisation | Allows call to 'Stocks' functions
Account account;

// Comapanies
            // Name, ID, Value, Location
Stocks TSLA  {"Tesla", 1, 600, "North America"};
Stocks APPL  {"Apple.inc", 2, 300, "North America"};
Stocks AMD   {"AMD (Advanced Micro Devices)", 3, 80, "North America"};
Stocks Intel {"Intel", 4, 35, "North America"};
Stocks Nvidia{"Nvidia", 5, 500, "Nvidia"};
Stocks TSMC  {"Taiwan Semiconductor Manufacturing Company", 6, 1500, "Asia"};

Stocks* Stocks::IntitializeStocks() {
        // Push stocks to object vector | Automate this part
    allStocks.push_back(TSLA);
    allStocks.push_back(APPL);
    allStocks.push_back(AMD);
    allStocks.push_back(Intel);
    allStocks.push_back(Nvidia);
    allStocks.push_back(TSMC);

    // Finally update total companies
    numberOfCompanies = allStocks.size();

    return &stock; // Check!
}

#endif