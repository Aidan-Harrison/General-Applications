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
    float m_Health, m_MoveSpeed, m_AttackSpeed, m_CritChance, m_HitChance;
    int itemTotal = 0, stackCount = 0, numberOfLives = 1;
    std::vector<Items> playerInventory{};
    std::vector<int> itemStacks{}; // Possibly remove
    Characters() = default;
    Characters(short health, short moveSpeed, short attackSpeed, short crit, short hit, std::string name);
    ~Characters() = default;

    void PrintItems();
    void PrintStats();
    int StackItems();
};

#endif