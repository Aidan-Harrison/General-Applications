#ifndef StockSetup_h
#define StockSetup_h

#include "Stocks.h"

Stocks stock; // Instance of stocks for intialisation | Allows call to 'Stocks' functions | Heap allocate

// Comapanies
Stocks TSLA;
Stocks APPL;
Stocks AMD;
Stocks Intel;
Stocks Nvidia;
Stocks TSMC;

Stocks* Stocks::IntitializeStocks() {
    // Names
    TSLA.companyName = "Tesla";
    APPL.companyName = "Apple.inc";
    AMD.companyName = "AMD (Advanced Micro Devices)";
    Intel.companyName = "Intel";
    Nvidia.companyName = "Nvidia";
    TSMC.companyName = "Taiwan Semiconductor Manufacturing Company";
    // ID | Could automate this one?
    TSLA.stockID = 1;
    APPL.stockID = 2;
    AMD.stockID = 3;
    Intel.stockID = 4;
    Nvidia.stockID = 5;
    TSMC.stockID = 6;
    // Market
    TSLA.stockValue = 600;
    APPL.stockValue = 300;
    AMD.stockValue = 80;
    Intel.stockValue = 35;
    Nvidia.stockValue = 500;
    TSMC.stockValue = 1500;
    // Location (NA)
    TSLA.location = stock.continents[0];
    APPL.location = stock.continents[0];
    AMD.location = stock.continents[0];
    Intel.location = stock.continents[0];
    Nvidia.location = stock.continents[0];
    // Location (Asia)
    TSMC.location = stock.continents[3];

    // Push stocks to object vector | Automate this part
    allStocks.push_back(TSLA);
    allStocks.push_back(APPL);
    allStocks.push_back(AMD);
    allStocks.push_back(Intel);
    allStocks.push_back(Nvidia);
    allStocks.push_back(TSMC);

    // Finally update total companies
    numberOfCompanies = allStocks.size();

    return &stock;
}

#endif