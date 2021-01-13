#include "RoR2.h"
#include "Characters.h"

// Prototypes
void RoR2Main(Characters &character);

Characters::Characters(short health, short moveSpeed, short attackSpeed, short damage, short crit, short hit, std::string name) {
    m_Health = health;
    m_MoveSpeed = moveSpeed;
    m_AttackSpeed = attackSpeed;
    m_Damage = damage;
    m_CritChance = crit;
    m_HitChance = hit;
    m_Name = name;
}

void Characters::PrintItems() {
    std::cout << "Inventory Size: " << playerInventory.size() << '\n';
    for(unsigned int i = 0; i < playerInventory.size(); i++)
        std::cout << i + 1 << ") " << playerInventory[i].m_ItemName << '\n';
}

void Characters::PrintStats(Characters &character) {
remain:
    system("cls");
    std::cout << m_Name << " Stats:\n";
    std::cout << "Health: " << m_Health << '\n';
    std::cout << "Attack Speed: " << m_AttackSpeed << '\n';
    std::cout << "Move Speed: " << m_MoveSpeed << '\n';
    std::cout << "Crit Chance: " << m_CritChance << '\n';
    std::cout << "Hit Chance: " << m_HitChance << '\n';
    std::cout << "Done? Y / N "; std::cin >> RoR2::stringInput;
    if(RoR2::stringInput == "N") goto remain;
    else if(RoR2::stringInput == "Y")
        RoR2Main(character);
}

// Also have stack count independent. Currently increases on an all item basis
// Change duplicate finding algorithm so it works on any state of the inventory
void Characters::StackItems() { // Prevent multiples of the same item from appearing more than once, increase stack count instead
    for(unsigned int i = 0; i < playerInventory.size(); i++) {
        for(unsigned int j = 1; j < playerInventory.size(); j++) {
            if(playerInventory[i].m_ItemName == playerInventory[j].m_ItemName) {
                playerInventory.erase(playerInventory.begin() + j);
                i--; j--;
                itemStacks.push_back(0); // Incorrect
                itemStacks[i]++;
            }
        }
    }
}

void Characters::DeleteItem(Characters& character) {
    PrintItems();
    std::cout << "\nEnter item index: "; std::cin >> RoR2::userInput;
    character.playerInventory.erase(character.playerInventory.begin() + RoR2::userInput);
    RoR2Main(character);
}