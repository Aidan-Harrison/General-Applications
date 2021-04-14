#ifndef Stocks_h
#define Stocks_h

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

class Stocks {
private:
    int m_StockID = 0, m_StockValue = 0; // Total amount of money in circulation | Possibly make static
    std::string companyName = "";
public:
    std::vector<std::string> continents{ "North America", "South America", "Europe", "Asia", "Oceania", "Africa" }; // Antartica is invalid
    std::string m_Location = ""; // Makes easier but not needed
    // Used for indexing | Change to static and properly increment
    short numberOfCompanies = 0;

    std::vector<Stocks> allStocks{};

    Stocks() = default;
    Stocks(std::string name, short id, short value, std::string location)
        :companyName(name), m_StockID(id), m_StockValue(value), m_Location(location)
    {
    }
    ~Stocks() = default;

    std::string GetName() const { return companyName; }
    int GetID() const { return m_StockID; }
    int GetValue() const { return m_StockValue; }

    Stocks* IntitializeStocks();
    void RemoveStocks();
    void AddStocks();
    void PrintStocks() const;

    // Global Market
    void GlobalMarket(); // User interface

    // Extras
    int profitCalc(std::vector<int>& company); // Calculates what the best time to buy and sell WAS
};

#endif