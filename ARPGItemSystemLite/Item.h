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

// Not the cleanest but functional
// Generate stats differently as these are mostly multipliers!
std::vector<std::string> corruptedMods{"Multiplied Damage", "Reduced Mana Cost Multiplication"};

// Temp function until linker works

struct Item {
    int iLevel = 1, type = 1, rarity = 1;
    enum TYPE{SWORD = 0, AXE, SHIELD}; // Make external, not every item needs this!
    enum RARITY{COMMON = 1, MAGIC, RARE, UNIQUE}; // Add more legendaries?
    bool isCorrupted = false;
    int maxMods = 5; // Opens up some interesting crafting | Pointless?
    itemName m_ItemName{"", "", ""};
    itemMods m_Mods{};
    Item() = default;
    Item(const itemName &&name, const int rarity = 1) noexcept // Check! Might not want to do rvalue
        : m_ItemName(name)
    {
    }
    Item(const int base, const int rar, const int iL, const itemName &name, itemMods &mods) 
        : type(base), rarity(rar), iLevel(iL), m_ItemName(name), m_Mods(mods)
    {
        RarityChecker();
    }

    void RarityChecker();

    bool SafetyCheck(std::string newGen, bool baseCheck);
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

bool Item::SafetyCheck(std::string newGen = "", bool baseCheck = false) {
    if(baseCheck) {
        // Checks if the base being generated is the same as current
        // if(m_ItemName == newGen)
           // return false;
    }
    else {
        // Checks all existing modifiers and ensures another one of the same type cannot generate
        // This function is not called when using a 'mirror'
        // Find optimised method
        // Need to also account for self generation
        int counter = 0;
        std::map<std::string, int> map;
        for(int i = 0; i < m_Mods.size(); i++) {
            map[std::get<1>(m_Mods[i])]++; // Check!
        }
        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->second > 1)
                return false;
            if(it->first == std::get<1>(m_Mods[counter]))
                return false;
            counter++;
        }
    }
    return true;
}

void Item::Apply(CraftingItem &cItem, std::vector<std::string> &modifiers) {
    // Regenerate stats or alter based on crafting item index
    if(cItem.itemName == "AgonyOrb") {
        isCorrupted = true;
        for(int i = 0; i < 2; i++) {
            int roll = rand() % corruptedMods.size(); // Use same safety check as regular mod pool!
            int modToChange = rand() % m_Mods.size();
            // Run safety check
            std::get<1>(m_Mods[modToChange]) = corruptedMods[roll];
        }
        // Create unique mod pool
        // Change two stats to any of these new uniques
    }
    else if(cItem.itemName == "Divine Orb") { // Fix!
        int choice = 0;
        while(std::get<2>(m_Mods[choice]) != 1)
            choice = rand() % m_Mods.size();
        std::get<2>(m_Mods[choice]) = 1;
    }
    else if(cItem.itemName == "Lament Gem") {
        int roll;
        for(int i = 0; i < m_Mods.size(); i++) {
            // Modifiers
                // Account for previous/existing rolls
                // Avoid using a nested for loop if possible, Map - ID system instead?
                // More storage but considerably faster, scales better also.
                // Current method is extremely ineffcient, must re-write
                // Also want to move safety check to function!
            while(!SafetyCheck("", false)) {
                roll = rand() % modifiers.size();
                std::get<1>(m_Mods[i]) = modifiers[roll];
            }
            // Values and Tiers
            std::get<0>(m_Mods[i]) = rand() % 100;
            std::get<0>(m_Mods[i])++;
            roll = std::get<0>(m_Mods[i]);
            if(roll > 75)
                std::get<2>(m_Mods[i]) = 1;
            else if(roll < 75 && roll > 50)
                std::get<2>(m_Mods[i]) = 2;
            else if(roll < 50 && roll > 25)
                std::get<2>(m_Mods[i]) = 3;
            else
                std::get<2>(m_Mods[i]) = 4;
        }              
    }
    else if(cItem.itemName == "Molten Core") {
        // Get item type
        // Regenerate to any item of that same type
        // Only alters base and thus implicits, everything else remains the same
        // Store everything but impicits and then paste into everything but implicits
    }
    else if(cItem.itemName == "Mirror") {
        int modToSwap = 0;
        int modToCopy = 0;
        std::tuple<std::string, int, int> modToCopyTuple;
        std::tuple<std::string, int, int> modToSwapTuple;
        modToCopy = rand() % m_Mods.size();
        modToSwap = rand() % m_Mods.size();
        while(modToSwap == modToCopy) {
            modToSwap = rand() % m_Mods.size();
        }
        m_Mods[modToSwap] = m_Mods[modToCopy];
    }
    else if(cItem.itemName == "Extension Orb") {
    }
}

#endif