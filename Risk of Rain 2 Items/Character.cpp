#include "Characters.h"

Characters::Characters(short health, short moveSpeed, short attackSpeed, std::string name) {
    m_Health = health;
    m_MoveSpeed = moveSpeed;
    m_AttackSpeed = attackSpeed;
    m_Name = name;
}

void Characters::PrintItems() {
    for(int i = 0; i <= playerInventory.size(); i++)
        std::cout << playerInventory[i] << ", " << itemStacks[i]; // Check
}

void Characters::PrintStats() {
    std::cout << m_Name << " Stats:\n";
    std::cout << "Attack Speed: " << m_AttackSpeed;
}

// Remove said item without ruining stats
int Characters::StackItems() { // Prevent multiples of the same item from appearing more than once, increase stack count instead
    for(int i = 0; i < playerInventory.size(); i++) {
        for(int j = 1; j < playerInventory.size(); j++) {
            if(playerInventory[i] == playerInventory[j]) {
                stackCount++;
                playerInventory.erase(playerInventory.begin() + j);
                i--; // Adjust for overflow, check!
            }
        }
    }
    return stackCount;
}