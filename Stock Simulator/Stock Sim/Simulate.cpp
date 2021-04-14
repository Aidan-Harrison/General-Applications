#include <iostream>
#include <thread>
#include <chrono>
#include "StockSim.h"

void CurrentStock() {
    system("cls");
    std::cout << "-------------" << StockSim::currentStock << "-------------\n"; 
    std::cout << "Years: " << StockSim::years << " Months: " << StockSim::months << '\n';
    std::cout << "Options: 1) Exit | 2) Display Account | 3) Market Interface\n"; // Process userInput somehow?
}

// Allows the user to input even when the sim is running
void SimInput() {
    
}

// Simulate all stocks at once. Multithread the program or indepently tick through them
// Heavily overview this
int Simulate(int GDP) {
    CurrentStock();
    while (StockSim::simulating == true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        srand(time(0));
        StockSim::event = rand() % 100; // Randomise events
        // Check events before processing
        if (StockSim::event != 74 && StockSim::event != 33) {
            StockSim::trajectory = rand() % 2; // Set increase or decrease
            if (StockSim::trajectory == 1) {
                srand(time(0)); // Avoid using this multiple times
                GDP += rand() % StockSim::fluctuation;
            }
            else if (StockSim::trajectory == 0) {
                srand(time(0));
                GDP -= rand() % StockSim::fluctuation;
            }
            // Bankrupcy
            if (GDP <= 3) {
                std::cout << "Bankrupt!\n";
                StockSim::simulating = false;
                return -1; // Failed, return out of simulation, alter objects and call class bankrupcy
            }
        }
        else if (StockSim::event == 74) {
            std::cout << "SURGE!";
            for (int i = 0; i <= 5; i++) {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                StockSim::trajectory = 1; // Force trajectory, remove randomness momentarily
                StockSim::fluctuation = 60;
                GDP += rand() % StockSim::fluctuation;
                std::cout << GDP << "---"; // Have to print again due to loop
            }
            std::cout << "END OF SURGE!\n";
            StockSim::fluctuation = 5; // Reset
            // Possibly alter seed in some way here
        }
        else if (StockSim::event == 33) {
            std::cout << "CRASH!";
            for (int i = 0; i <= 5; i++) {
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                StockSim::trajectory = 0;
                StockSim::fluctuation = 15; // Loss is not as severe as surge
                GDP -= rand() % StockSim::fluctuation;
                std::cout << GDP << "---";
            }
            std::cout << "END OF CRASH!\n";
            StockSim::fluctuation = 5;
        }
        StockSim::timeCounter++;
        if (StockSim::timeCounter == 31) {
            StockSim::months++;
            StockSim::timeCounter = 0; // Reset
            CurrentStock();
        }
        if (StockSim::months == 12) {
            StockSim::years++;
            StockSim::timeCounter = 0;
            CurrentStock();
        }
        std::cout << GDP << "---"; // Print current value
        // Change global stock here | Add all companies GDP's up
    }
    return GDP;
}