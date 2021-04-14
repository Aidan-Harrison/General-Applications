#include "Stocks.h"
#include "StockSim.h"

// Prototypes
void Menu();

void Stocks::PrintStocks() const { // Unified printing function | Move to be available globally
    for (unsigned int i = 0; i < allStocks.size(); i++) // should not really start from 1 but leave for now
        std::cout << i + 1 << ") " << allStocks[i].companyName << '\n';
    std::cout << "Press enter to return: ";
}

int Stocks::profitCalc(std::vector<int>& company) { // Pass in via stock ID | Check!
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
    std::string companyName = "";
    std::string location = "";
    short stockValue = 0;
    std::cout << "Enter company name: "; std::cin >> companyName;
    for (unsigned int i = 0; i < continents.size(); i++)
        std::cout << i + 1 << ") " << continents[i] << '\n';
    std::cout << "Pick a location: "; std::cin >> StockSim::userInput;
    switch (StockSim::userInput) {
        case 1: location = "North America"; break;
        case 2: location = "South America"; break;
        case 3: location = "Europe";        break;
        case 4: location = "Asia";          break;
        case 5: location = "Ocenaia";       break;
        case 6: location = "Africa";        break;
    }
    std::cout << "Enter company value: "; std::cin >> stockValue;
    Stocks newStock{companyName, numberOfCompanies + 1, stockValue, location};
    allStocks.push_back(newStock);
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
        allStocks[i].m_StockID -= 1; // Adjust for overflow
    Menu();
}

void Stocks::GlobalMarket() {
    system("cls");
    std::cout << "====GLOBAL MARKET====\n";
    std::cout << "What would you like to do?\n" <<
                 "1) List of Companies\n" <<
                 "2) Remove Stocks\n" <<
                 "3) Add stocks\n" <<
                 "4) Back\n";
    std::cout << "Input: "; 
    std::cin >> StockSim::userInput; 
    switch (StockSim::userInput) {
        case 1: PrintStocks();  break;
        case 2: RemoveStocks(); break;
        case 3: AddStocks();    break;
        case 4: Menu();         break;
        default: return;
    }
    return;
}
