#ifndef Player_h
#define Player_h

#define stat_F std::get<0>
#define stat_S std::get<1>

#include <vector>
#include "Item.h"

struct Player {
    int level = 1;
    std::vector<Item*> inventory{};
    std::vector<std::tuple<int, Item*, bool>> gear{}; // First index of tuple = ID, defines slot
    std::vector<std::tuple<std::string, int>> stats;
    std::string playerName = "";
    Player() {}
    Player(const int baseLevel, const std::string &name) 
        : level(baseLevel), playerName(name) 
    {
        gear.resize(9);
        stats.resize(15);
        // ==== CORE ====
        stat_F(stats[0]) = "INT"; stat_S(stats[0]) = 20;
        stat_F(stats[1]) = "DEX"; stat_S(stats[1]) = 20;
        stat_F(stats[2]) = "STR"; stat_S(stats[2]) = 20;
        // ==== GENERAL ====
        stat_F(stats[3]) =  "Physical Damage";      stat_S(stats[3])  = 100;
        stat_F(stats[4]) =  "Pierce Rating";        stat_S(stats[4])  = 50;
        stat_F(stats[5]) =  "Block Chance";         stat_S(stats[5])  = 20;
        stat_F(stats[6]) =  "Evasion Rating";       stat_S(stats[6])  = 20;
        stat_F(stats[7]) =  "Dodge Rating";         stat_S(stats[7])  = 20;
        stat_F(stats[8]) =  "Movement Speed";       stat_S(stats[8])  = 100;
        stat_F(stats[9]) =  "Fire Resistance";      stat_S(stats[9])  = 15;
        stat_F(stats[10]) = "Cold Resistance";      stat_S(stats[10]) = 15;
        stat_F(stats[11]) = "Lightning Resistance"; stat_S(stats[11]) = 15;
        stat_F(stats[12]) = "Holy Resistance";      stat_S(stats[12]) = 15;
        stat_F(stats[13]) = "Dark Resistance";      stat_S(stats[13]) = 15;
        stat_F(stats[14]) = "Poison Resistance";    stat_S(stats[14]) = 15;
    }

    void CharacterScreen();
    void GearScreen();
    void PrintInventory() const;

    ~Player() {}
};

void Player::CharacterScreen() {
    std::cout << "======" << playerName << "======\n";
    for(int i = 0; i < stats.size(); i++) {
        std::cout << std::get<0>(stats[i]) << " | " << std::get<1>(stats[i]) << '\n';
    }
}

void Player::GearScreen() { // Make look like standard ARPG layout
    std::cout << "====== GEAR ======\n";
    for(int i = 0; i < gear.size(); i++)
        std::cout << "ID: " << stat_F(gear[i]) << " | " << stat_S(gear[i])->m_ItemName << '\n';
}

void Player::PrintInventory() const {
    for(int i = 0; i < inventory.size(); i++) {
        std::cout << i << "| " << inventory[i]->m_ItemName << '\n';
    }
}

#endif