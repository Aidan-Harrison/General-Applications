#ifndef Characters_h
#define Characters_h

#include "Items.h"

#include <iostream>
#include <vector>

// Add move semantics!!
class Characters {
private:
    std::string m_Name;
public:
    // Stats
    float m_Health, m_MoveSpeed, m_AttackSpeed, m_Damage, m_CritChance, m_HitChance, m_Shield = 0, m_Luck = 1;
    int itemTotal = 0, stackCount = 0, numberOfLives = 1;
    // Character Extra
    bool toSecret = false;
    // Inventory
    std::vector<Items*> playerInventory{};
    std::vector<int> itemStacks{}; // Print next to invent

    Characters() = default;
    Characters(short health, short moveSpeed, short attackSpeed, short damage, short crit, short hit, std::string name);
    ~Characters() = default;

    void PrintItems();
    void PrintStats();
    int StackItems();
};

#endif