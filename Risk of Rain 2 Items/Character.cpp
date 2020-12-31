#include "Characters.h"

Characters::Characters(short health, short moveSpeed, short attackSpeed, short crit, short hit, std::string name) {
    m_Health = health;
    m_MoveSpeed = moveSpeed;
    m_AttackSpeed = attackSpeed;
    m_CritChance = crit;
    m_HitChance = hit;
    m_Name = name;
}

void Characters::PrintItems() {
    for (unsigned int i = 0; i < playerInventory.size(); i++)
        std::cout << playerInventory[i]->m_ItemName << ", "; // Add item stacks
}

void Characters::PrintStats() {
    std::cout << m_Name << " Stats:\n";
    std::cout << "Health: " << m_Health << '\n';
    std::cout << "Attack Speed: " << m_AttackSpeed << '\n';
    std::cout << "Move Speed: " << m_MoveSpeed << '\n';
    std::cout << "Crit Chance: " << m_CritChance << '\n';
    std::cout << "Hit Chance: " << m_HitChance << '\n';
    std::cout << "Done? Press Enter: "; std::cin.get(); // Do, Y / N instead
}

// Remove said item without affecting stats
int Characters::StackItems() { // Prevent multiples of the same item from appearing more than once, increase stack count instead
    for(unsigned int i = 0; i < playerInventory.size(); i++) {
        for(unsigned int j = 1; j < playerInventory.size(); j++) {
            if(playerInventory[i]->m_ItemName == playerInventory[j]->m_ItemName) {
                stackCount++;
                playerInventory.erase(playerInventory.begin() + j);
                i--; // Adjust for overflow, check!
            }
        }
    }
    return stackCount;
}