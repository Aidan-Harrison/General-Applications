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

// Internal Prototypes
void RoR2Main(Characters &character);
void StatCalculation(Characters *character);
// External Prototypes
void CommonChest(Characters &character);
void RareChest(Characters &character);
void LunarPod(Characters *character);
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
        character->playerInventory.push_back(CreateWhiteItem(itemMod));
    }
    else if(rarityCoeffcient > 5 && rarityCoeffcient <= 8) { // Green Items
        srand(time(0));
        itemMod = std::rand() % 6;
        character->playerInventory.push_back(CreateGreenItem(itemMod));
    }
    else if(rarityCoeffcient > 8) { // Red items
        srand(time(0));
        itemMod = std::rand() % 6;
        character->playerInventory.push_back(CreateRedItem(itemMod));
    }
    StatCalculation(character);
    std::cout << "WAIT!"; std::this_thread::sleep_for(std::chrono::milliseconds(500));
    RoR2Main(*character);
}

void StatCalculation(Characters *character) { // Too slow | Use Map
    for(unsigned int i = 0; i < character->playerInventory.size(); i++) {
        if (character->playerInventory[i]->m_ItemName == "Soldiers Syringe")
            character->m_AttackSpeed += 10;
        else if (character->playerInventory[i]->m_ItemName == "Tougher Times")
            character->m_HitChance -= 10;
        else if (character->playerInventory[i]->m_ItemName == "Lens Maker Glasses")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "Topaz Brooch")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "Crowbar")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "Bustling Fungus")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "ATG Missle MK.2")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "Ukele")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "Predators Instinct")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "Red Whip")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "Infusion")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "Will-O-Wisp")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "Brilliant Behemoth")
            character->m_Damage += 50;
        else if (character->playerInventory[i]->m_ItemName == "Soulbound Catalyst")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "Aegis")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "57 Leaf Clover") {
            character->m_Luck = 2;
            character->m_CritChance *= character->m_Luck;
            character->m_HitChance /= character->m_Luck;
        }
        else if (character->playerInventory[i]->m_ItemName == "Rejuvanation Rack")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "Resonance Disc")
            character->m_CritChance += 10;
        else if (character->playerInventory[i]->m_ItemName == "Shaped Glass") {
            character->m_Damage *= 2;
            character->m_Health /= 2;
        }
        else if (character->playerInventory[i]->m_ItemName == "Beads of Fealty")
            character->toSecret = true;
        else if (character->playerInventory[i]->m_ItemName == "Transcendence") {
            character->m_Shield = character->m_Health;
            character->m_Health = 0;
        }
        // Add equipment
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
            LunarPod(&character); break;
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
    // Add deletion when game over!
    return;
}