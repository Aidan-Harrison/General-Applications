#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>
// Possibly add file streaming

#include "Stocks.h"
#include "StockSetup.h"
#include "StockSim.h"

using namespace StockSim;

// To-Do-List:
    // Check if close to event, redefine range, inform user

// Prototypes
int SetupStock(int ID);
int Simulate(int GDP);
void CurrentStock();
void Menu();
void AccountMenu(std::vector<Stocks>& stocks, Stocks& stock);

void Menu() {
    system("cls");
    std::cout << "What stock would you like to check?\n";
    std::cout << "Options:\n";
    stock.PrintStocks();
    std::cout << "OR\n";
    std::cout << stock.numberOfCompanies + 1 << ") " << "Global Market\n"; // Always move one above total stock size
    std::cout << stock.numberOfCompanies + 2 << ") " << "Account\n";
    std::cin >> userInput;
    if (userInput != stock.numberOfCompanies + 1)
        Simulate(SetupStock(userInput));
    else if (userInput == stock.numberOfCompanies + 1)
        stock.GlobalMarket();
    else if (userInput == stock.numberOfCompanies + 2)
        AccountMenu(stock.allStocks, stock);
}

int SetupStock(int ID) {
    for (unsigned int i = 0; i < stock.allStocks.size(); i++)
        if (stock.allStocks[i].stockID == ID) {
            currentStock = stock.allStocks[i].companyName;
            return stock.allStocks[i].stockValue;
        }
    return -1; // Failed
}

int main() { // Move this to an entrypoint file?
    stock.IntitializeStocks();
    std::cout << "WAIT! Setting up...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Menu();

    return 0;
}