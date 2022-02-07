#ifndef Character_h
#define Character_h

#include <iostream>
#include <unordered_map>
#include <type_traits>

#include "Weapon.h"
#include "ArmorPiece.h"
#include "SubClass.h"

void DisplayWeapon(Weapon &wep);

class Character {
private:
    int choice = 0;
    enum CLASS{HUNTER = 1, TITAN, WARLOCK};
    enum SUBCLASS{VOID = 1, SOLAR, ARC, STASIS};
public:
    std::string charName;
    std::string className;
    SubClass currentSubClass;
    int mainStats[3];
    int curClass = 0, curSubClass = 0;
    int lightPower = 100;
    float hunterModifier = 1.0f, titanModifier = 1.0f, warlockModifier = 1.0f;
    // std::array<Weapon, 20> vault;
    std::unordered_map<int, Weapon> weapons; // Change to array, map is pointless here
    std::unordered_map<int, ArmorPiece> armor;
    std::unordered_map<int, std::array<Weapon*, 9>> wepGearSlotInvent;
    std::unordered_map<int, std::array<ArmorPiece, 9>> armGearSlotInvent;
    std::vector<int> stats{};

    Character(const std::string &name = "Default Character")
        :charName(name)
    {
        Check();
        /*
        for(int i = 0; i <= 8; i++) { // Sets default gear
            if(i <= 3) {
                Weapon *newWeapon = new Weapon("Default", 1, 1); // = new Weapon("Default", 1);
                weapons.insert(std::pair<int, Weapon>(i, *newWeapon));
            }
            else {
                ArmorPiece newArmor("Default", 1);   
                armor.insert(std::pair<int, ArmorPiece>(i, newArmor));
            }
        }
        */
    }

    // Add copy/move constructor gear transfer?

    void Check();
    void Interaction();

    // Gear
    void DisplayGear();
    void ChangeGear();
    void ModifyGear();

    template<typename T>
    void AddEquipment(T &item, bool PrintDrop = true); // Universal function which can be expanded to handle all items

    // Vault
    void SearchVault();

    // Classes and Sub-Classes
    void ChangeSubClass();
    void ModifySubClass();

    ~Character() 
    {
        delete[] mainStats;
    }
};

#endif