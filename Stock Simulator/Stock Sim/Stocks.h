#ifndef Stocks_h
#define Stocks_h

#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>

class Stocks {
private:

public:
    std::vector<std::string> continents{ "North America", "South America", "Europe", "Asia", "Oceania", "Africa" }; // Antartica is invalid
    std::string companyName = "";
    std::string location = ""; // Makes easier but not needed
    int stockID; // Used for indexing | Change to static and properly increment
    int stockValue = 0; // Total amount of money in circulation | Possibly make static
    int numberOfCompanies = 0;

    std::vector<Stocks> allStocks{};

    Stocks() = default;
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