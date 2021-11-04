#ifndef Item_h
#define Item_h

#include <iostream>
#include <tuple>
#include <map>

#include "CraftingItem.h"

struct Item {
    int iLevel = 1;
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

    void Apply(CraftingItem &cItem, std::vector<std::string> &modifiers);

    ~Item() {}
};

void Item::Apply(CraftingItem &cItem, std::vector<std::string> &modifiers) {
    // Regenerate stats or alter based on crafting item index
    if(cItem.itemName == "AgonyOrb") {

    }
    else if(cItem.itemName == "Divine Orb") { // Fix!
        int choice = 0;
        while(std::get<2>(m_Stats[choice]) != 1)
            choice = rand() % m_Stats.size();
        std::get<2>(m_Stats[choice]) = 1;
    }
    else if(cItem.itemName == "Lament Gem") {
        for(int i = 0; i < m_Stats.size(); i++) {
            // Modifiers
                // Account for previous/existing rolls
                // Avoid using a nested for loop if possible, Map - ID system instead?
                // More storage but considerably faster, scales better also.
            int roll = rand() % modifiers.size();            
            for(int j = 0; j < m_Stats.size(); j++) {
                if(std::get<0>(m_Stats[j]) == std::get<0>(m_Stats[i])) {
                    
                }
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
    }
}

#endif