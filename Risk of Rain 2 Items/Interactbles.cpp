#include <iostream>
#include <ctime>

#include "RoR2.h"
#include "ItemList.h"
#include "Characters.h"
#include "Items.h"

using namespace ItemList;
using namespace RoR2;

// Prototypes
void CalculateItem(Characters *character);

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
    if (character.playerInventory.empty() == true) {
        std::cout << "You have no items to scrap!\n";
    }
    std::cout << "Select item to delete:\n";
    for(unsigned int i = 0; i < character.playerInventory.size(); i++)
        if(character.playerInventory[i]->m_ItemName == input) {
            character.playerInventory.erase(character.playerInventory.begin() + i);
            i--; // Adjust for overflow
        }
}

void Scrapper(Characters &character, short input) { // Overload, ID based
    std::cout << "Selection item to delete:\n";
}

// Check pointer vs reference!
void LunarPod(Characters *character) {
    srand(time(0));
    itemMod = std::rand() % 3;
    character->playerInventory.push_back(CreateLunarItem(itemMod));
    character->StackItems();
}

void EquipmentChest(Characters &character) {
    srand(time(0));
    itemMod = std::rand() % 4;
    character.playerInventory.push_back(CreateEquipment(itemMod));
    character.StackItems();
}