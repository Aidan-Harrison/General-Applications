#ifndef Player_h
#define Player_h

#include <array>
#include "Wand.h"

class Player { // make singleton
private:
public:
    int curWand = 1;
    int expandInterface = 0;
    int maxWands = 4;
    std::array<Wand*, 4> wands{};
    std::array<Spell*, 10> storedSpells{};
    std::vector<Spell*> storedSpells_r{};
        // Allow for empty spaces and fit it into system
    Player() {}
    ~Player() {}
};

#endif