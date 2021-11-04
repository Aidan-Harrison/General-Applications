#ifndef Weapon_h
#define Weapon_h

#include <array>
#include <cassert>

#include "WeaponPerk.h"

class Weapon {
private:
    int choice = 0;
public:
    enum TYPE{HAND_CANNON = 1, SIDEARM, SHOTGUN, SNIPER_RIFLE, AUTO_RIFLE, SMG, SCOUT_RIFLE, FUSION_RIFLE, ROCKET_LAUNCHER, GRENADE_LAUNCHER, SWORD};
    int type = 1;
    int rarity = 0;
    std::string weaponName = "";
    std::string weaponType = "";
    std::string itemDescription = "";

    int lightLevel = 100;
    // Stats | Convert to array? Might be cumbersome in the long run
    int damage = 1;
    int range = 1;
    int stability = 1;
    int handling = 1;
    int impact = 1;

    std::array<int, 5> weaponStats{damage, range, stability, handling, impact};
    std::array<std::string, 5> statNames{"Damage", "Range", "Stability", "Handling", "Impact"};
    // Add perks
    std::vector<WeaponPerk*> perks{}; // Different rarities have different amount of perks

    Weapon() {}   
    Weapon(const std::string &name, const int rar) 
        :weaponName(name), rarity(rar) 
    {
        assert(name != "");
        // Ensure perks are set at generation!
        ApplyPerks();
    }
    void Modify(); // Try to convert to a single global function?
    void ApplyPerks();
    ~Weapon() 
    {
        perks.clear();
    }
};

// Exotics | Should be the correct method, generating and pulling stats is more cumbersome and hard to read, although still functional
class Hawkmoon : public Weapon {
private:
public:
    Hawkmoon() 
    {
        weaponName = "Hawkmoon";
        itemDescription = "Hawkmoon description";
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