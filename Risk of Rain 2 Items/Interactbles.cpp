#include <iostream>
#include <ctime>

#include "RoR2.h"
#include "Characters.h"
#include "Items.h"

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

void Scrapper(Characters &character, Items &item, std::string input) { // Deletes specified item and adds scrap based on rarity, based on string
    std::cout << "Select item to delete:\n";
    for(int i = 0; i <= character.playerInventory.size(); i++)
        if(character.playerInventory[i] == input);
}

void Scrapper(Characters &character, Items &item, short input) { // Overload for item ID instead
    std::cout << "Selection item to delete:\n";
}

void LunarPod(Characters &character, Items &item) {
    srand(time(0));
    item.m_RandomItem = std::rand() & 3;
    character.playerInventory.push_back(item.lunarItems[item.m_RandomItem]);
    character.StackItems();
}

void EquipmentChest(Characters &character, Items &item) {
    srand(time(0));
    item.m_RandomItem = std::rand() % 4;
    character.playerInventory.push_back(item.equipment[item.m_RandomItem]);
    character.StackItems();
}