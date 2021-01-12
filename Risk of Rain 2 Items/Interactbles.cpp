#include <iostream>
#include <ctime>
#include <thread>
#include <ctime>

#include "RoR2.h"
#include "ItemList.h"
#include "Characters.h"
#include "Items.h"

using namespace ItemList;
using namespace RoR2;

// Prototypes
void StatCalculation(Characters &character);
void RoR2Main(Characters &character);

// Calculate rarity using Coeffcient, alter range size for rarity
// Add to player inventory
void CalculateItem(Characters &character) {
    character.itemTotal++;
    if (rarityCoeffcient >= 0 && rarityCoeffcient <= 5) { // White Items
        srand(time(0));
        itemMod = std::rand() % 6;
        character.playerInventory.push_back(CreateWhiteItem(itemMod));
    }
    else if (rarityCoeffcient > 5 && rarityCoeffcient <= 8) { // Green Items
        srand(time(0));
        itemMod = std::rand() % 6;
        character.playerInventory.push_back(CreateGreenItem(itemMod));
    }
    else if (rarityCoeffcient > 8) { // Red items
        srand(time(0));
        itemMod = std::rand() % 6;
        character.playerInventory.push_back(CreateRedItem(itemMod));
    }
    StatCalculation(character);
    std::cout << "WAIT!"; std::this_thread::sleep_for(std::chrono::milliseconds(500));
    RoR2Main(character);
}

void CommonChest(Characters &character) {
    srand(time(0));
    rarityCoeffcient = std::rand() % rarityCoeffcient + 1; // +1 to avoid 0 division
    // character.StackItems();
    return CalculateItem(character);
}

void RareChest(Characters &character) {
    srand(time(0));
    rarityCoeffcient = std::rand() % rarityCoeffcient + 2; // Higher chance to go into rarer item bounds | Ensure it does not go out of range | Check!
    // character.StackItems();
    return CalculateItem(character);
}

void Scrapper(Characters &character) { // Deletes specified item and adds scrap based on rarity
    if(character.playerInventory.empty() == true) { std::cout << "You have no items to scrap!\n"; }
    character.PrintItems();
    std::cout << "Select item to delete:\n"; std::cin >> userInput;
    character.playerInventory.erase(character.playerInventory.begin() + userInput);
    RoR2Main(character);
}

void LunarPod(Characters &character) {
    srand(time(0));
    itemMod = std::rand() % 3;
    character.playerInventory.push_back(CreateLunarItem(itemMod));
    character.StackItems();
    RoR2Main(character);
}

void EquipmentChest(Characters &character) {
    srand(time(0));
    itemMod = std::rand() % 4;
    character.playerInventory.push_back(CreateEquipment(itemMod));
    character.StackItems();
    RoR2Main(character);
}