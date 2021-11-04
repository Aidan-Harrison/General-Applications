#ifndef ArmorPiece_h
#define ArmorPiece_h

#include "ArmorMod.h"
#include <array>
#include <cassert>
#include <vector>

namespace ModPool {
    std::vector<ArmorMod> modPool{};
}

class ArmorPiece {
private:
    int choice = 0;
public:
    std::array<ArmorMod, 5> mods{};
    enum TYPE{HELMET = 1, CHEST, LEGS, GAUNTLETS, CLASS_PIECE, ARTIFACT};
    int type = 1;
    int rarity = 0;
    int lightLevel = 100;
    std::string armorName = "";
    std::string armorType = "";
    std::string itemDescription = "";
    // Class Stats
    int mobility = 1; // Hunter
    int resillience = 1; // Titan
    int recovery = 1; // Warlock
    // Stats
    int discipline = 1;
    int intellect = 1;
    int strength = 1;
    std::array<int, 6> stats{mobility, resillience, recovery, discipline, intellect, strength};
    std::array<std::string, 6> statNames{"Mobility", "Resillience", "Recovery", "Discipline", "Intellect", "Strength"};
    ArmorPiece() {}
    ArmorPiece(const std::string &name, const int rar) 
        :armorName(name), rarity(rar)
    {
        assert(name != "");

    }
    void Modify(); // Try to convert to a single global function
    ~ArmorPiece() {}
};

void ArmorPiece::Modify() {
    std::cout << "Choose a mod slot to change:\n";
    for(unsigned int i = 0; i < mods.size(); i++)
        std::cout << i << ")" << mods[i].modName << '\n';
    std::cin >> choice;
    int curSlot = choice;
    std::cout << "Choose a different mod to swap\n";
    for(unsigned int i = 0; i < ModPool::modPool.size(); i++)
        std::cout << i << ") " << ModPool::modPool[i].modName << " | " << ModPool::modPool[i].type << '\n';
    std::cin >> choice;
    mods[curSlot] = ModPool::modPool[choice];
}

#endif