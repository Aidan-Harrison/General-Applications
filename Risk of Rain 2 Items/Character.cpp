#include "RoR2.h"
#include "Characters.h"

// Prototypes
void RoR2Main(Character &character);

Character::Character(int health, int moveSpeed, int attackSpeed, int damage, int crit, int hit, const std::string && name) {
    m_Health = health;
    m_MoveSpeed = moveSpeed;
    m_AttackSpeed = attackSpeed;
    m_Damage = damage;
    m_CritChance = crit;
    m_HitChance = hit;
    m_Name = name;
}

void Character::PrintItems() const {
    std::cout << "Inventory Size: " << playerInventory.size() << '\n';
    for(unsigned int i = 0; i < playerInventory.size(); i++)
        std::cout << i + 1 << ") " << playerInventory[i]->m_ItemName << '\n';
}

void Character::PrintStats(Character &character) const {
    system("cls");
    std::cout << m_Name << " |Stats:";
    std::cout << "\nHealth: " << m_Health;
    std::cout << "\nAttack Speed: " << m_AttackSpeed;
    std::cout << "\nMove Speed: " << m_MoveSpeed;
    std::cout << "\nCrit Chance: " << m_CritChance;
    std::cout << "\nHit Chance: " << m_HitChance;
    std::cout << "\nDone? Y / N "; 
    std::cin >> RoR2::stringInput;
    while (1) {
        if (RoR2::stringInput == "Y")
            RoR2Main(character);
        else if (RoR2::stringInput == "N")
            PrintStats(character);
        else
            std::cin >> RoR2::stringInput;
    }
}

// Also have stack count independent. Currently increases on an all item basis
// Change duplicate finding algorithm so it works on any state of the inventory
void Character::StackItems() { // Prevent multiples of the same item from appearing more than once, increase stack count instead
    for(unsigned int i = 0; i < playerInventory.size(); i++) {
        for(unsigned int j = 1; j < playerInventory.size(); j++) {
            if(playerInventory[i]->m_ItemName == playerInventory[j]->m_ItemName) {
                playerInventory.erase(playerInventory.begin() + j);
                i--; 
                j--;
                itemStacks.push_back(0); // Incorrect
                itemStacks[i]++;
            }
        }
    }
}

void Character::DeleteItem(Character& character) {
    PrintItems();
    std::cout << "\nEnter item index: "; std::cin >> RoR2::userInput;
    character.playerInventory.erase(character.playerInventory.begin() + RoR2::userInput);
    RoR2Main(character);
}