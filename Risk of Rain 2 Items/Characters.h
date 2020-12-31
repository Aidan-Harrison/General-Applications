#ifndef Characters_h
#define Characters_h

#include <iostream>
#include <vector>

// Add move semantics!!
class Characters {
private:
    int m_Health, m_MoveSpeed, m_AttackSpeed;
    std::string m_Name;
public:
    // float playerHealth = 500.0f, attackSpeed = 1.0f, moveSpeed = 10.0f, critChance = 10.0f, hitChance = 100.0f; // Check!
    int itemTotal = 0, stackCount = 0, numberOfLives = 1;
    std::vector<std::string> playerInventory{};
    std::vector<int> itemStacks{};
    Characters() = default;
    Characters(short health, short moveSpeed, short attackSpeed, std::string name);
    ~Characters() = default;

    void PrintItems();
    void PrintStats();
    int StackItems();
};

#endif