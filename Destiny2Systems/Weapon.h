#ifndef Weapon_h
#define Weapon_h

#include <array>
#include <cassert>

class Weapon {
private:
    int choice = 0;
public:
    enum TYPE{HAND_CANNON = 1, SIDEARM, SHOTGUN, SNIPER_RIFLE, AUTO_RIFLE, SMG, SCOUT_RIFLE, FUSION_RIFLE, ROCKET_LAUNCHER, GRENADE_LAUNCHER, SWORD};
    int type = 1;
    int rarity = 0;
    std::string weaponName = "";
    std::string weaponType = "";

    int lightLevel = 100;
    // Stats
    int damage = 1;
    int range = 1;
    int stability = 1;
    int handling = 1;
    int impact = 1;

    std::array<int, 5> weaponStats{damage, range, stability, handling, impact};
    std::array<std::string, 5> statNames{"Damage", "Range", "Stability", "Handling", "Impact"};
    // Add perks

    Weapon() {}   
    Weapon(const std::string &name, const int rar) 
        :weaponName(name), rarity(rar) 
    {
        assert(name != "");
    }
    void Modify(); // Try to convert to a single global function?
    ~Weapon() {}
};

void Weapon::Modify() {
    std::cout << "MODIFING!\n";
}

#endif