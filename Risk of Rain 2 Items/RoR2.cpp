#include <iostream>
#include "RoR2.h"

namespace RoR2 {
    int rarityCoeffcient = 10;
    int itemMod = 0;
    bool gameOver = false;
    int userInput = 0;
    std::string stringInput = "";

    void PrintCharacters() {
        std::cout << "Characters:\n";
        std::cout << "1) Solider " << "2) Huntress " << "3) Engineer\n";
        std::cout << "4) Mult-T " << "5) Artificer " << "6) Acrid\n";
    }

    void PrintOptions() {
        std::cout << "Enter Option:\n";
        std::cout << "1) Common Chest " << "2) Rare Chest " << "3) Lunar Pod\n";
        std::cout << "4) Equipment Chest " << "5) Scrapper\n";
        std::cout << "6) Print Items " << "7) Print Stats " << "8) Delete Items\n" << "9) End\n";
    }
}