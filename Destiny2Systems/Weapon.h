#ifndef Weapon_h
#define Weapon_h

#include <array>
#include <cassert>
#include <tuple>

#include "WeaponPerk.h"

class Weapon {
private:
    int choice = 0;
    enum AMMOTYPE{COMMON = 1, SPECIAL, HEAVY};
public:
    enum TYPE{HAND_CANNON = 1, SIDEARM, SHOTGUN, SNIPER_RIFLE, AUTO_RIFLE, SMG, SCOUT_RIFLE, FUSION_RIFLE, ROCKET_LAUNCHER, GRENADE_LAUNCHER, SWORD};
    int type = 1;
    int ammoType = 1;
    int slot = 1; // In most cases the ammo type refers to what slot the weapon is associated with, however there are several exceptions
    int rarity = 0;
    int perkCount;
    std::string weaponName = "";
    std::string weaponType = "";
    std::string weaponDescription = "";

    int lightLevel = 100;
    // Stats | Convert to array? Might be cumbersome in the long run
    int damage = 1;
    int range = 1;
    int stability = 1;
    int handling = 1;
    int impact = 1;

    std::vector<std::tuple<std::string, int>> weaponStats{{"Damage", 1},
                                                        {"Range", 1},
                                                        {"Stability", 1},
                                                        {"Handling", 1},
                                                        {"Impact", 1},
    };
    // Add perks
    std::vector<WeaponPerk*> perks{}; // Different rarities have different amount of perks

    Weapon() {}   
    Weapon(const std::string &name, const int rar, const int perks) 
        :weaponName(name), rarity(rar), perkCount(perks) 
    {
        assert(name != "");
        // Ensure perks are set at generation!
        ApplyPerks();
    }
    Weapon(Weapon &other) 
        :weaponName(other.weaponName), rarity(other.rarity)
    {
        type = other.type;
        ammoType = other.type;
        slot = other.slot;
        weaponType = other.weaponType;
        weaponDescription = other.weaponDescription;
    }

    void Modify(); // Try to convert to a single global function?
    void ApplyPerks();
    ~Weapon() 
    {
        perks.clear();
    }

    Weapon& operator=(Weapon&other) {
        weaponName = other.weaponName;
        rarity = other.rarity;
        type = other.type;
        ammoType = other.type;
        slot = other.slot;
        weaponType = other.weaponType;
        weaponDescription = other.weaponDescription; 
    }
};

// Remove? Could be integrated into new method of generation
// Exotics | Should be the correct method, generating and pulling stats is more cumbersome and hard to read, although still functional
class Hawkmoon : public Weapon {
private:
public:
    Hawkmoon() 
    {
        weaponName = "Hawkmoon";
        weaponDescription = "Hawkmoon description";
    }
    ~Hawkmoon() {}
};

void Weapon::Modify() {
    std::cout << "MODIFING!\n";
}

void Weapon::ApplyPerks() {
    for(unsigned int i = 0; i < perks.size(); i++) {
        switch (perks[i]->statPN[0]) {
            case false: damage += perks[i]->statEffects[0]; break;
            case true: damage -= perks[i]->statEffects[0]; break;
        }
        switch (perks[i]->statPN[1]) {
            case false: range += perks[i]->statEffects[1]; break;
            case true: range -= perks[i]->statEffects[1]; break;
        }
        switch (perks[i]->statPN[2]) {
            case false: stability += perks[i]->statEffects[2]; break;
            case true: stability -= perks[i]->statEffects[2]; break;
        }
        switch (perks[i]->statPN[3]) {
            case false: handling += perks[i]->statEffects[3]; break;
            case true: handling -= perks[i]->statEffects[3]; break;
        }
        switch (perks[i]->statPN[4]) {
            case false: impact += perks[i]->statEffects[4]; break;
            case true: impact -= perks[i]->statEffects[4]; break;
        }
    }
}

#endif