#include <iostream>
#include <thread>
#include <chrono>
#include "StockSim.h"

using namespace StockSim;

void CurrentStock() {
    system("cls");
    std::cout << "-------------" << currentStock << "-------------\n";
    std::cout << "Years: " << years << " Months: " << months << '\n';
    std::cout << "Options: 1) Exit | 2) Display Account | 3) Market Interface\n"; // Process userInput somehow?
}

// Simulate all stocks at once. Multithread the program or indepently tick through them
// Heavily overview this
int Simulate(int GDP) {
    CurrentStock();
    while (simulating == true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
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
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
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
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
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