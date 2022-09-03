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

void StatCalculation(Character &character);
void RoR2Main(Character &character);

// Calculate rarity using Coeffcient, alter range size for rarity
// Add to player inventory
void CalculateItem(Character & character) {
    character.itemTotal++;
    if (rarityCoeffcient >= 0 && rarityCoeffcient <= 5)
        character.playerInventory.push_back(CreateWhiteItem(rand() % 6));
    else if (rarityCoeffcient > 5 && rarityCoeffcient <= 8)
        character.playerInventory.push_back(CreateGreenItem(rand() % 6));
    else 
        character.playerInventory.push_back(CreateRedItem(rand() % 6));
    StatCalculation(character);
    std::cout << "WAIT!"; 
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    RoR2Main(character);
}

void CommonChest(Character & character) {
    rarityCoeffcient = rand() % rarityCoeffcient + 1; // +1 to avoid 0 division
    // character.StackItems();
    return CalculateItem(character);
}

void RareChest(Character & character) {
    rarityCoeffcient = rand() % rarityCoeffcient + 2; // Higher chance to go into rarer item bounds | Ensure it does not go out of range | Check!
    // character.StackItems();
    return CalculateItem(character);
}

void Scrapper(Character &character) { // Deletes specified item and adds scrap based on rarity
    if(character.playerInventory.empty() == true) {
        std::cout << "You have no items to scrap!\n";
        return;
    }
    character.PrintItems();
    std::cout << "\nSelect item to delete:\n"; 
    std::cin >> userInput;
    if(character.playerInventory[userInput-1]->m_ItemType == Items::LUNAR || character.playerInventory[userInput-1]->m_ItemType == Items::EQUIPMENT) {
        std::cout << "You cannot scrap Lunar or Equipment!\n";
        RoR2Main(character);
    }
    else if (character.playerInventory[userInput-1]->m_ItemType == Items::WHITE)
        character.playerInventory.push_back(CreateScrap("white"));
    else if (character.playerInventory[userInput-1]->m_ItemType == Items::GREEN)
        character.playerInventory.push_back(CreateScrap("green"));
    else if (character.playerInventory[userInput-1]->m_ItemType == Items::UNIQUE)
        character.playerInventory.push_back(CreateScrap("red"));
    character.playerInventory.erase(character.playerInventory.begin() + userInput - 1);
    RoR2Main(character);
}

void LunarPod(Character &character) {
    itemMod = rand() % 3;
    character.playerInventory.push_back(CreateLunarItem(itemMod));
    // character.StackItems();
    RoR2Main(character);
}

void EquipmentChest(Character &character) {
    itemMod = rand() % 4;
    character.playerInventory.push_back(CreateEquipment(itemMod));
    // character.StackItems();
    RoR2Main(character);
}