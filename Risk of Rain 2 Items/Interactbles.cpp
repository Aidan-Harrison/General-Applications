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
void StatCalculation(Characters *character);
void RoR2Main(Characters &character);

// Calculate rarity using Coeffcient, alter range size for rarity
// Add to player inventory
void CalculateItem(Characters* character) {
    character->itemTotal++;
    if (rarityCoeffcient >= 0 && rarityCoeffcient <= 5) { // White Items
        srand(time(0));
        itemMod = std::rand() % 6;
        character->playerInventory.push_back(&CreateWhiteItem(itemMod));
    }
    else if (rarityCoeffcient > 5 && rarityCoeffcient <= 8) { // Green Items
        srand(time(0));
        itemMod = std::rand() % 6;
        character->playerInventory.push_back(&CreateGreenItem(itemMod));
    }
    else if (rarityCoeffcient > 8) { // Red items
        srand(time(0));
        itemMod = std::rand() % 6;
        character->playerInventory.push_back(&CreateRedItem(itemMod));
    }
    StatCalculation(character);
    std::cout << "WAIT!"; std::this_thread::sleep_for(std::chrono::milliseconds(500));
    RoR2Main(*character);
}

void CommonChest(Characters &character) {
    srand(time(0));
    rarityCoeffcient = std::rand() % rarityCoeffcient;
    character.StackItems();
    return CalculateItem(&character);
}

void RareChest(Characters &character) {
    srand(time(0));
    rarityCoeffcient = std::rand() % rarityCoeffcient + 2; // Higher chance to go into rarer item bounds
    character.StackItems();
    return CalculateItem(&character);
}

void Scrapper(Characters &character, std::string input) { // Deletes specified item and adds scrap based on rarity, string based
    if(character.playerInventory.empty() == true) { std::cout << "You have no items to scrap!\n"; }
    std::cout << "Select item to delete:\n";
    for(unsigned int i = 0; i < character.playerInventory.size(); i++) {
        if(character.playerInventory[i]->m_ItemName == input) {
            character.playerInventory.erase(character.playerInventory.begin() + i);
            i--; // Adjust for overflow
        }
    }
}

void Scrapper(Characters &character, short input) { // Overload, ID based
    std::cout << "Selection item to delete:\n";
}

void LunarPod(Characters *character) {
    srand(time(0));
    itemMod = std::rand() % 3;
    // character->playerInventory.push_back(&CreateLunarItem(itemMod));
    character->StackItems();
}

void EquipmentChest(Characters &character) {
    srand(time(0));
    itemMod = std::rand() % 4;
    // character.playerInventory.push_back(&CreateEquipment(itemMod));
    character.StackItems();
}