#ifndef WeaponPerk_h
#define WeaponPerk_h

#include <array>
// Alters stats of weapon

struct WeaponPerk {
    std::string perkname = "";
    bool isActive = false; // If true, apply functionallity
    WeaponPerk(const std::string &name) :perkname(name) {}

    std::array<int, 5> statEffects{};
    std::array<bool, 5> statPN{};

    ~WeaponPerk() {}
};

#endif