#ifndef Characters_h
#define Characters_h

#include "Items.h"

#include <iostream>
#include <vector>
#include <map>

// Add move semantics!!
class Character {
private:
    std::string m_Name; // Check!
public:
    Character(int health, int moveSpeed, int attackSpeed, int damage, int crit, int hit, const std::string && name);
    // Stats
    float m_Health, m_MoveSpeed, m_AttackSpeed, m_Damage, m_CritChance, m_HitChance, m_Shield = 0, m_Luck = 1;
    int itemTotal = 0, numberOfLives = 1;
    // Character Extra

    std::vector<Items*> playerInventory{}; // Change from pointer
    std::map<std::string, Items> playerInv{};
    std::vector<int> itemStacks{}; // Initialize as 0 when an item is added?
    
    std::string GetName() const { return m_Name; }
    void PrintItems() const;
    void PrintStats(Character & character) const;
    void StackItems();
    void DeleteItem(Character & character);

    ~Character() {};
};

#endif