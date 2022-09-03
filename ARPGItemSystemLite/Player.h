#ifndef Player_h
#define Player_h

// Gear
#define gear_ID       std::get<0>
#define gear_Item     std::get<1>
#define gear_Equipped std::get<2>

// Stats
#define stat_F std::get<0>
#define stat_S std::get<1>

#include <vector>
#include "Item.h"
#include "Keyboard.h"

struct Player {
    int level = 1;
    std::vector<Item*> inventory{};
    std::vector<Item*> gear{}; // First index = ID, defines slot | Change to array | Remove equipped??
    std::vector<int> gearID{};
    std::vector<std::pair<std::string, int>> stats;
    std::string playerName = "";
    Player() {}
    Player(const int baseLevel, const std::string && name) 
        : level(baseLevel), playerName(name) 
    {
        gear.resize(9);
        gearID.resize(9);

        // Set gear ID's
        gearID[0] = WEAPON;
        gearID[1] = WEAPON;

        gearID[2] = HELMET;
        gearID[3] = CHEST;
        gearID[4] = BELT;
        gearID[5] = JEWELLERY;

        stats.resize(15);

        // ==== CORE ====
        stats[0] = {"INT", 20};
        stats[1] = {"DEX", 20};
        stats[2] = {"STR", 20};
        // ==== GENERAL ====
        stats[3] = {"Physical Damage",      100};
        stats[4] = {"Pierce Rating",        50};
        stats[5] = {"Block Chance",         20};
        stats[6] = {"Evasion Rating",       20};
        stats[7] = {"Dodge Rating",         20};
        stats[8] = {"Movement Speed",       100};
        stats[9] = {"Fire Resistance",      15};
        stats[10]= {"Cold Resistance",      15};
        stats[11]= {"Lightning Resistance", 15};
        stats[12]= {"Holy Resistance",      15};
        stats[13]= {"Dark Resistance",      15};
        stats[14]= {"Poison Resistance",    15};
    }

    void CharacterScreen() const;
    void GearScreen() const;
    void PrintInventory() const;

    ~Player() {}
};

void Player::CharacterScreen() const {
    std::cout << "====== " << playerName << " ======\n";
    for(int i = 0; i < stats.size(); i++)
        std::cout << stats[i].first << " | " << stats[i].second << '\n';
}

void Player::GearScreen() const {
    std::cout << "====== GEAR ======\n";
    for(int i = 0; i < gear.size(); i++) {
        if(i % 4 == 0 && i != 0)
            putchar('\n');
        if(gear[i] != nullptr) {
            for(int i = 0; i <= gear[i]->m_ItemName.size(); i++ )
                std::cout << gear[i]->m_ItemName[i];
            putchar('\t');
        }
        else 
            std::cout << "  ...  \t";
    }
}

// Fix printing!
void Player::PrintInventory() const {
    std::cout << "====== INVENTORY ======\n";
    for(int i = 0; i < inventory.size(); i++) {
        std::cout << i+1 << "| " << inventory[i]->m_ItemName[0] << inventory[i]->m_ItemName[1] << inventory[i]->m_ItemName[2] << '\n';
    }
}

#endif