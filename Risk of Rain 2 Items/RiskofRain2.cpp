#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

#include "RoR2.h"
#include "Items.h"
#include "Characters.h"

// Use move semantics heavily!
using namespace RoR2;
Items testItem;

// Prototypes
void CommonChest(Characters &character);
void RareChest(Characters &character);
void LunarPod(Characters &character, Items &item);
void EquipmentChest(Characters &character, Items &item);
void Scrapper(Characters &character, Items &item, std::string input); // Figure out effective way to call
void Scrapper(Characters &character, Items &item, short input);

// Calculate rarity using Coeffcient, alter range size for rarity
void CalculateItem(Characters *character) {
    character->itemTotal++;
    if(rarityCoeffcient >= 0 && rarityCoeffcient <= 5) { // White Items
        srand(time(0));
        testItem.m_RandomItem = std::rand() % 6;
        character->playerInventory.push_back(testItem.whiteItems[testItem.m_RandomItem]);
    }
    else if(rarityCoeffcient > 5 && rarityCoeffcient <= 8) { // Green Items
        srand(time(0));
        testItem.m_RandomItem = std::rand() % 6;
        character->playerInventory.push_back(testItem.greenItems[testItem.m_RandomItem]);
    }
    else if(rarityCoeffcient > 8) { // Red items
        srand(time(0));
        testItem.m_RandomItem = std::rand() % 6;
        character->playerInventory.push_back(testItem.redItems[testItem.m_RandomItem]);
    }
    std::cout << "WAIT!"; std::this_thread::sleep_for(std::chrono::milliseconds(500));
    system("cls");
    PrintOptions();
}

// Requires a lot of work
void StatCalculation(Characters *character) { // | Too slow | Use Map
    for(int i = 0; i < character->playerInventory.size(); i++) {
        if(character->playerInventory[i] == "Soldiers Syringe")
            character->attackSpeed + 10;
        else if(character->playerInventory[i] == "Tougher Times")
            character->hitChance - 10;
        else if(character->playerInventory[i] == "Lens Maker Glasses")
            character->critChance + 10;
    }
}

void RoR2Main(Characters &character) {
    PrintOptions();
    while(!gameOver) {
        std::cin >> userInput;
        switch (userInput) {
        case 1:
            CommonChest(character); break;
        case 2:
            RareChest(character); break;
        case 3:
            LunarPod(character, testItem); break;
        case 4:
            EquipmentChest(character, testItem);  break;
        case 5:
            Scrapper(character, testItem, userInput); break;
        case 6:
            character.PrintItems(); break;
        case 7:
            character.PrintStats(); break;
        case 8:
            gameOver = false; return;
        }
    }
    std::cout << "Ended!"; std::this_thread::sleep_for(std::chrono::milliseconds(500));
    return;
}