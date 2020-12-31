#include <iostream>
#include <vector>
#include <ctime>
#include <thread>
#include <chrono>
// Possibly add file stream to do loggin or import a bunch of data

#include "StockSimulator.h"
#include "Stocks.h"
#include "StockSetup.h"

using namespace StockSim;

// To-Do-List:
    // Check if close to event, redefine range, inform user
    // Account
    // Possibly incorporate std::cerr

// Prototypes
int SetupStock(int ID);
int Simulate(int GDP);
void CurrentStock(); // Prints header of program, add userInput without interupting simulation, seperate thread?
void Menu();
void AccountMenu(std::vector<Stocks>& stocks, Stocks& stock);

void printStocks() { // Unified printing function | Move to be available globally
    for (int i = 0; i < stock.allStocks.size(); i++) // should not really start from 1 but leave for now
        std::cout << i + 1 << ") " << stock.allStocks[i].companyName << '\n';
}

int Stocks::profitCalc(std::vector<int>& company) { // Pass in via stock ID
    int maxProfit = 0;
    int minPrice = INT_MAX;
    // Get current investments
    for (int i = 0; i < company.size(); i++)
        if (company[i] < minPrice)
            minPrice = company[i];
        else if (company[i] - minPrice > maxProfit)
            maxProfit = company[i] - minPrice;
    std::cout << "You would have made: " << maxProfit;
    return maxProfit;
}

void Stocks::AddStocks() { // Use seperate setup function? | Adds to vector but does not add all data. Hence why only companyName is partially working
    Stocks* newStock = new Stocks;
    std::cout << "Enter company name: "; std::cin >> newStock->companyName;
    for (int i = 0; i < continents.size(); i++)
        std::cout << i + 1 << ") " << continents[i] << '\n';
    std::cout << "Pick a location: "; std::cin >> userInput;
    switch (userInput) {
    case 1:
        newStock->location = continents[0]; break;
    case 2:
        newStock->location = continents[1]; break;
    case 3:
        newStock->location = continents[2]; break;
    case 4:
        newStock->location = continents[3]; break;
    case 5:
        newStock->location = continents[4]; break;
    case 6:
        newStock->location = continents[5]; break;
    }
    std::cout << "Enter company value: "; std::cin >> newStock->stockValue; // Not working!
    allStocks.push_back(*newStock); // Working
    numberOfCompanies++;
    Menu();
}

void Stocks::RemoveStocks() {
    std::string stock;
    std::cout << "Enter stock name: "; std::cin >> stock;
    for (int i = 0; i < allStocks.size(); i++) {
        if (stock == allStocks[i].companyName) {
            allStocks.erase(allStocks.begin() + i);
            numberOfCompanies--;
        }
    }
    for (int i = 0; i < allStocks.size(); i++) { // Adjust for erase
        allStocks[i].stockID -= 1;
    }
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
    case 1:
        printStocks(); std::this_thread::sleep_for(std::chrono::seconds(5)); goto menu;
    case 2:
        stock.RemoveStocks(); break;
    case 3:
        stock.AddStocks(); break;
    case 5:
        Menu(); break;
    default:
        return;
    }
    return;
}

void Menu() {
    system("cls");
    std::cout << "What stock would you like to check?\n";
    std::cout << "Options:\n";
    printStocks();
    std::cout << "OR\n";
    std::cout << stock.numberOfCompanies + 1 << " ) " << "Global Market\n"; // Always move one above total stock size
    std::cout << stock.numberOfCompanies + 2 << " ) " << "Account\n"; // Always move one above total stock size
    std::cin >> userInput;
    if (userInput != stock.numberOfCompanies + 1) {
        Simulate(SetupStock(userInput));
    }
    else if (userInput == stock.numberOfCompanies + 1)
        stock.GlobalMarket();
    else if (userInput == stock.numberOfCompanies + 2)
        AccountMenu(stock.allStocks, stock);
}

int SetupStock(int ID) {
    for (int i = 0; i < stock.allStocks.size(); i++)
        if (stock.allStocks[i].stockID == ID) {
            currentStock = stock.allStocks[i].companyName;
            return stock.allStocks[i].stockValue;
        }
    return -1; // Failed
}

void CurrentStock() {
    system("cls");
    std::cout << "-------------" << currentStock << "-------------\n";
    std::cout << "Years: " << years << "\n";
    std::cout << "Months: " << months << "\n";
    std::cout << "Options: 1) Exit | 2) Display Account | 3) Market Interface\n"; // Process userInput somehow, seperate function?
}

// Simulate all stocks at once. Multithread the program or indepently tick through them
// Move to seperate file
int Simulate(int GDP) {
    CurrentStock();
    while (simulating == true) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Delay | change to float
        srand(time(0));
        event = rand() % 100; // Randomise events
        // Check events before processing
        if (event != 74 && event != 33) {
            trajectory = rand() % 2; // Set increase or decrease
            if (trajectory == 1) {
                srand(time(0)); // Avoid using this multiple times
                GDP += rand() % fluctuation;
            }
            else if (trajectory == 0) {
                srand(time(0));
                GDP -= rand() % fluctuation;
            }
            // Bankrupcy
            if (GDP <= 3) {
                std::cout << "Bankrupt!\n";
                simulating = false;
                return -1; // Failed, return out of simulation, alter objects and call class bankrupcy
            }
        }
        else if (event == 74) {
            std::cout << "SURGE!";
            for (int i = 0; i <= 5; i++) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                trajectory = 1; // Force trajectory, remove randomness momentarily
                fluctuation = 60;
                GDP += rand() % fluctuation;
                std::cout << GDP << "---"; // Have to print again due to loop
            }
            std::cout << "END OF SURGE!\n";
            fluctuation = 5; // Reset
            // Possibly alter seed in some way here
        }
        else if (event == 33) {
            std::cout << "CRASH!";
            for (int i = 0; i <= 5; i++) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                trajectory = 0;
                fluctuation = 15; // Loss is not as severe as surge
                GDP -= rand() % fluctuation;
                std::cout << GDP << "---";
            }
            std::cout << "END OF CRASH!\n";
            fluctuation = 5;
        }
        timeCounter++;
        if (timeCounter == 31) {
            months++;
            timeCounter = 0; // Reset
            CurrentStock();
        }
        if (months == 12) {
            years++;
            timeCounter = 0;
            CurrentStock();
        }
        std::cout << GDP << "---"; // Print current value
        // Change global stock here | Add all companies GDP's up
    }
    return GDP;
}

int main() { // Move this to an entrypoint file??
    stock.IntitializeStocks();
    std::cout << "WAIT! Setting up...\n";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    Menu();

    return 0;
}