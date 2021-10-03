#ifndef Character_h
#define Character_h

#include <iostream>
#include <unordered_map>

#include "Weapon.h"
#include "ArmorPiece.h"
#include "SubClass.h"

class Character {
private:
    int choice = 0;
public:
    enum CLASS{HUNTER = 1, TITAN, WARLOCK};
    enum SUBCLASS{VOID = 1, SOLAR, ARC, STASIS};
    SubClass currentSubClass;
    int mainStats[3];
    int curClass = 0, curSubClass = 0;
    int lightPower = 100;
    float hunterModifier = 1.0f, titanModifier = 1.0f, warlockModifier = 1.0f;
    // std::array<Weapon, 20> vault;
    std::unordered_map<int, Weapon> weapons;
    std::unordered_map<int, ArmorPiece> armor;
    std::unordered_map<int, std::array<Weapon, 9>> wepGearSlotInvent;
    std::unordered_map<int, std::array<ArmorPiece, 9>> armGearSlotInvent;
    std::vector<int> stats{};
    Character() {
        Check();
        for(int i = 0; i <= 8; i++) { // Sets default gear
            if(i <= 3) {
                Weapon newWeapon("Default", 1); // = new Weapon("Default", 1);
                weapons.insert(std::pair<int, Weapon>(i, newWeapon));
            }
            else {
                ArmorPiece newArmor("Default", 1);   
                armor.insert(std::pair<int, ArmorPiece>(i, newArmor));
            }
        }
    }

    void Check();
    void Interaction();

    // Gear
    void DisplayGear();
    void ChangeGear();
    void ModifyGear();

    // Vault
    void SearchVault();

    // Classes and Sub-Classes
    void ChangeSubClass();
    void ModifySubClass();

    ~Character() {}
};

#endif