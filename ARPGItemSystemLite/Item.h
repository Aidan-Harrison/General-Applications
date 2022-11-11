#ifndef Item_h
#define Item_h

#include <iostream>
#include <tuple>
#include <map>
#include <vector>
#include <array>

#include "CraftingItem.h"

// VALUE | MOD | TIER
typedef std::vector<std::tuple<int, std::string, int>> itemMods;
typedef std::array<std::string, 3> itemName;

#define VALUE std::get<0>
#define NAME std::get<1>
#define TIER std::get<2>

// Not the cleanest but functional
// Generate stats differently as these are mostly multipliers!
std::vector<std::string> corruptedMods{"Multiplied Damage", "Reduced Mana Cost Multiplication"};

enum TYPE{SWORD = 1, AXE, SHIELD}; // Make external, not every item needs this!
enum RARITY{COMMON = 1, MAGIC, RARE, UNIQUE}; // Add more legendaries?
enum CORE{WEAPON = 1, CHEST, BELT, JEWELLERY, HELMET};

struct Item {
    int core = 1;
    int iLevel = 1, type = 1, rarity = 1;
    bool isCorrupted = false;
    int maxMods = 5; // Opens up some interesting crafting | Pointless?
    itemName m_ItemName{"", "", ""};
    itemMods m_Mods{};
    Item() = default;
    Item(const itemName && name, int rarity = 1) noexcept // Check! Might not want to do rvalue
        : m_ItemName(name)
    {
    }
    Item(const int base, const int rar, const int iL, const itemName & name, itemMods & mods) 
        : type(base), rarity(rar), iLevel(iL), m_ItemName(name), m_Mods(mods)
    {
        RarityChecker();
    }

    void RarityChecker();

    bool SafetyCheck(const std::string & newGen, bool baseCheck);
    void Apply(CraftingItem &cItem, std::vector<std::string> &modifiers);

    ~Item() {}
};

void Item::RarityChecker() {
    switch(rarity) {
        case 0: {
            rarity = 1;
            m_Mods.resize(2);
            break;
        }
        case 2: {
            rarity = 2;
            m_Mods.resize(4);
            break;
        }
        case 3: {
            rarity = 3;
            m_Mods.resize(6);
            break;
        }
        case 4: {
            rarity = 4;
            m_Mods.resize(6);
            break;
        }
    }
}

// Does the following:
/*
    - Checks for duplicate mods
*/
bool Item::SafetyCheck(const std::string & newGen = "", bool baseCheck = false) {
    if(baseCheck) {
        // Checks if the base being generated is the same as current
        // if(m_ItemName == newGen)
           // return false;
        return true;
    }
    // Checks all existing modifiers and ensures another one of the same type cannot generate
    // This function is not called when using a 'mirror'
    // Find optimised method
    // Need to also account for self generation
    std::map<std::string, int> map;
    for(int i = 0; i < m_Mods.size(); i++)
        map[NAME(m_Mods[i])]++; 
    for(auto it = map.begin(); it != map.end(); it++) {
        if(it->second > 1) {
            return false; // Return index
        }
    }
    return true;
}

void Item::Apply(CraftingItem & cItem, std::vector<std::string> & modifiers) {
    if(cItem.type == 0) { // Agony Orb
        isCorrupted = true;
        for(int i = 0; i < 2; i++) {
            int roll = rand() % corruptedMods.size(); // Use same safety check as regular mod pool!
            int modToChange = rand() % m_Mods.size();
            // Run safety check!
            NAME(m_Mods[modToChange]) = corruptedMods[roll];
        }
        // Create unique mod pool
        // Change two stats to any of these new uniques
    }
    else if(cItem.type == 1) { // Divine Orb
        bool hasChanged = false;
        while(!hasChanged) {
            int choice = m_Mods.size();
            if(TIER(m_Mods[choice]) != 1) {
                TIER(m_Mods[choice]) = 1;
                hasChanged = true;
            }
        }
    }
    else if(cItem.type == 2) { // Lament Gem
        for(int i = 0; i < m_Mods.size(); i++) {
            // Modifiers
                // Account for previous/existing rolls
                // Avoid using a nested loop if possible, Map - ID system instead?
                // More storage but considerably faster, scales better also.
                // Current method is extremely ineffcient, must re-write
                // Also want to move safety check to function!
            while(!SafetyCheck(NAME(m_Mods[i]), false))
                NAME(m_Mods[i]) = modifiers[rand() % modifiers.size()];
            // Values and Tiers
            VALUE(m_Mods[i]) = rand() % 100;
            VALUE(m_Mods[i])++;
            if(VALUE(m_Mods[i]) > 75)
                TIER(m_Mods[i]) = 1;
            else if(VALUE(m_Mods[i]) < 75 && VALUE(m_Mods[i]) > 50)
                TIER(m_Mods[i]) = 2;
            else if(VALUE(m_Mods[i]) < 50 && VALUE(m_Mods[i]) > 25)
                TIER(m_Mods[i]) = 3;
            else
                TIER(m_Mods[i]) = 4;
        }              
    }
    else if(cItem.type == 3) { // Molten Core
        // Get item type
        // Regenerate to any item of that same type
        // Only alters base and thus implicits, everything else remains the same
        // Store everything but impicits and then paste into everything but implicits
    }
    else if(cItem.type == 4) { // Mirror
        Item * copyItem = this; // Just do copy semantics
        copyItem->m_ItemName = m_ItemName;
        for(unsigned int i = 0; i < m_Mods.size(); i++) {
            
        }
    }
    else if(cItem.type == 5) { // Extension Orb

    }
}

#endif