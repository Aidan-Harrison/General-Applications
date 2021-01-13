#ifndef Stocks_h
#define Stocks_h

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

struct Stocks {
public:
    std::vector<std::string> continents{ "North America", "South America", "Europe", "Asia", "Oceania", "Africa" }; // Antartica is invalid
    std::string companyName = "";
    std::string m_Location = ""; // Makes easier but not needed
    int m_StockID = 0; // Used for indexing | Change to static and properly increment
    int m_StockValue = 0; // Total amount of money in circulation | Possibly make static
    short numberOfCompanies = 0;

    std::vector<Stocks> allStocks{};

    Stocks() = default;
    Stocks(std::string name, short id, short value, std::string location)
        :companyName(name), m_StockID(id), m_StockValue(value), m_Location(location)
    {
    }
    ~Stocks() = default;

    Stocks* IntitializeStocks();
    void RemoveStocks(); // Possibly combine with add into one function
    void AddStocks();
    void PrintStocks();

    // Global Market
    void GlobalMarket(); // User interface

    // Extras
    int profitCalc(std::vector<int>& company); // Calculates what the best time to buy and sell WAS
};

#endif