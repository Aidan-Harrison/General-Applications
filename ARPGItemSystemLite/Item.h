#ifndef Item_h
#define Item_h

#include <iostream>
#include <tuple>
#include <map>
#include <vector>

#include "CraftingItem.h"

// Not the cleanest but functional
// Generate stats differently as these are mostly multipliers!
std::vector<std::string> corruptedMods{"Multiplied Damage", "Reduced Mana Cost Multiplication"};

// Temp function until linker works

struct Item {
    int iLevel = 1;
    int type = 1;
    enum TYPE{SWORD = 1, AXE, SHIELD};
    enum RARITY{COMMON = 1, MAGIC, RARE, UNIQUE};
    bool isCorrupted = false;
    std::string m_ItemName = "";
    std::tuple<std::string,int,int,int> m_base;
    // Stat - Value - Tier // In-order instead?
    std::array<std::tuple<std::string, int, int>, 5> m_Stats{};
    Item(const int iL, const std::tuple<std::string,int,int,int> &base, std::array<std::tuple<std::string, int, int>, 5> &stats) 
        : iLevel(iL), m_base(base), m_Stats(stats)
    {
        m_ItemName = std::get<0>(m_base);
    }

    void RegenerateType(); // Remove!!
    bool SafetyCheck(std::string newGen, bool baseCheck);
    void Apply(CraftingItem &cItem, std::vector<std::string> &modifiers);

    ~Item() {}
};

void Item::RegenerateType() {
    switch(type) {
        case 0: break;
    }
}

bool Item::SafetyCheck(std::string newGen, bool baseCheck = false) {
    if(baseCheck) {
        // Checks if the base being generated is the same as current
        if(m_ItemName == newGen)
            return false;
    }
    else {
        // Checks all existing modifiers and ensures another one of the same type cannot generate
        // This function is not called when using a 'mirror'
        // Find optimised method
        // Need to also account for self generation
        int counter = 0;
        std::map<std::string, int> map;
        for(int i = 0; i < m_Stats.size(); i++) {
            map[std::get<0>(m_Stats[i])]++; // Check!
        }
        for(auto it = map.begin(); it != map.end(); it++) {
            if(it->second > 1)
                return false;
            if(it->first == std::get<0>(m_Stats[counter]))
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
            int modToChange = rand() % m_Stats.size();
            // Run safety check
            std::get<0>(m_Stats[modToChange]) = corruptedMods[roll];
        }
        // Create unique mod pool
        // Change two stats to any of these new uniques
    }
    else if(cItem.itemName == "Divine Orb") { // Fix!
        int choice = 0;
        while(std::get<2>(m_Stats[choice]) != 1)
            choice = rand() % m_Stats.size();
        std::get<2>(m_Stats[choice]) = 1;
    }
    else if(cItem.itemName == "Lament Gem") {
        int roll;
        for(int i = 0; i < m_Stats.size(); i++) {
            // Modifiers
                // Account for previous/existing rolls
                // Avoid using a nested for loop if possible, Map - ID system instead?
                // More storage but considerably faster, scales better also.
                // Current method is extremely ineffcient, must re-write
                // Also want to move safety check to function!
            while(!SafetyCheck("", false)) {
                roll = rand() % modifiers.size();
                std::get<0>(m_Stats[i]) = modifiers[roll];
            }
            // Values and Tiers
            std::get<1>(m_Stats[i]) = rand() % 100;
            std::get<1>(m_Stats[i])++;
            roll = std::get<1>(m_Stats[i]);
            if(roll > 75)
                std::get<2>(m_Stats[i]) = 1;
            else if(roll < 75 && roll > 50)
                std::get<2>(m_Stats[i]) = 2;
            else if(roll < 50 && roll > 25)
                std::get<2>(m_Stats[i]) = 3;
            else
                std::get<2>(m_Stats[i]) = 4;
        }              
    }
    else if(cItem.itemName == "Molten Core") {
        // Get item type
        // Regenerate to any item of that same type
        // Only alters base and thus implicits, everything else remains the same
        // Store everything but impicits and then paste into everything but implicits
        RegenerateType(); // Molten core seems a bit overblown!
    }
    else if(cItem.itemName == "Mirror") {
        int modToSwap = 0;
        int modToCopy = 0;
        std::tuple<std::string, int, int> modToCopyTuple;
        std::tuple<std::string, int, int> modToSwapTuple;
        modToCopy = rand() % m_Stats.size();
        modToSwap = rand() % m_Stats.size();
        while(modToSwap == modToCopy) {
            modToSwap = rand() % m_Stats.size();
        }
        m_Stats[modToSwap] = m_Stats[modToCopy];
    }
}

#endif