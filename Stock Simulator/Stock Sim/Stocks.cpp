#include "Stocks.h"
#include "StockSim.h"

using namespace StockSim;

// Prototypes
void Menu();

void Stocks::PrintStocks() { // Unified printing function | Move to be available globally
    for (unsigned int i = 0; i < allStocks.size(); i++) // should not really start from 1 but leave for now
        std::cout << i + 1 << ") " << allStocks[i].companyName << '\n';
}

int Stocks::profitCalc(std::vector<int>& company) { // Pass in via stock ID
    int maxProfit = 0;
    int minPrice = INT_MAX;
    // Get current investments
    for (unsigned int i = 0; i < company.size(); i++)
        if (company[i] < minPrice)
            minPrice = company[i];
        else if (company[i] - minPrice > maxProfit)
            maxProfit = company[i] - minPrice;
    std::cout << "You would have made: " << maxProfit;
    return maxProfit;
}

void Stocks::AddStocks() {
    Stocks* newStock = new Stocks;
    std::cout << "Enter company name: "; std::cin >> newStock->companyName;
    for (unsigned int i = 0; i < continents.size(); i++)
        std::cout << i + 1 << ") " << continents[i] << '\n';
    std::cout << "Pick a location: "; std::cin >> userInput;
    switch (userInput) {
    case 1: newStock->location = continents[0]; break;
    case 2: newStock->location = continents[1]; break;
    case 3: newStock->location = continents[2]; break;
    case 4: newStock->location = continents[3]; break;
    case 5: newStock->location = continents[4]; break;
    case 6: newStock->location = continents[5]; break;
    }
    std::cout << "Enter company value: "; std::cin >> newStock->stockValue; // Check!
    allStocks.push_back(*newStock); // Working
    numberOfCompanies++;
    Menu();
}

void Stocks::RemoveStocks() {
    std::string stock;
    std::cout << "Enter stock name: "; std::cin >> stock;
    for (unsigned int i = 0; i < allStocks.size(); i++) {
        if (stock == allStocks[i].companyName) {
            allStocks.erase(allStocks.begin() + i);
            numberOfCompanies--;
        }
    }
    for (unsigned int i = 0; i < allStocks.size(); i++) // Check!
        allStocks[i].stockID -= 1; // Adjust for overflow
    Menu();
}

void Stocks::GlobalMarket() {
menu:
    system("cls");
    std::cout << "What would you like to do?\n";
    std::cout << "1) List of Companies\n";
    std::cout << "2) Remove Stocks\n";
    std::cout << "3) Add stocks\n";
    std::cout << "4) Profit Calculator\n";
    std::cout << "5) Back\n";
    std::cout << "Input: "; std::cin >> userInput;
    switch (userInput) {
    case 1: PrintStocks(); std::this_thread::sleep_for(std::chrono::seconds(5)); goto menu;
    case 2: RemoveStocks();       break;
    case 3: AddStocks();          break;
    case 5: Menu();               break;
    default:                      return;
    }
    return;
}
