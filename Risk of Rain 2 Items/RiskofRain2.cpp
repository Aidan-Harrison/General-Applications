#include <iostream>
#include <ctime>
#include <thread>
#include <chrono>

#include "RoR2.h"
#include "Items.h"
#include "Characters.h"
#include "ItemList.h"

// Use move semantics heavily!
using namespace RoR2;
using namespace ItemList;
WhiteItems white;
GreenItems green;
RedItems red;
LunarItems lunar;
Equipment equipment;

// Prototypes
void RoR2Main(Characters &character);
void CommonChest(Characters &character);
void RareChest(Characters &character);
void LunarPod(Characters &character);
void EquipmentChest(Characters &character);
void Scrapper(Characters &character, std::string input);
void Scrapper(Characters &character, short input);

// Calculate rarity using Coeffcient, alter range size for rarity
// Add to player inventory
void CalculateItem(Characters *character) {
    character->itemTotal++;
    if(rarityCoeffcient >= 0 && rarityCoeffcient <= 5) { // White Items
        srand(time(0));
        itemMod = std::rand() % 6;
    }
    else if(rarityCoeffcient > 5 && rarityCoeffcient <= 8) { // Green Items
        srand(time(0));
        itemMod = std::rand() % 6;
    }
    else if(rarityCoeffcient > 8) { // Red items
        srand(time(0));
        itemMod = std::rand() % 6;
    }
    std::cout << "WAIT!"; std::this_thread::sleep_for(std::chrono::milliseconds(500));
    RoR2Main(*character);
}

// Requires a lot of work
void StatCalculation(Characters *character) { // | Too slow | Use Map
    for(int i = 0; i < character->playerInventory.size(); i++) {
        if(character->playerInventory[i].m_ItemName == "Soldiers Syringe")
            character->m_AttackSpeed += 10;
        else if(character->playerInventory[i].m_ItemName == "Tougher Times")
            character->m_HitChance -= 10;
        else if(character->playerInventory[i].m_ItemName == "Lens Maker Glasses")
            character->m_CritChance += 10;
    }
}

void RoR2Main(Characters &character) {
    system("cls");
    PrintOptions();
    while(!gameOver) {
        std::cin >> userInput;
        switch (userInput) {
        case 1:
            CommonChest(character); break;
        case 2:
            RareChest(character); break;
        case 3:
            LunarPod(character); break;
        case 4:
            EquipmentChest(character);  break;
        case 5:
            Scrapper(character, userInput); break;
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