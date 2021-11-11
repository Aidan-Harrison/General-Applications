#ifndef Player_h
#define Player_h

#include <array>
#include "Wand.h"

class Player { // make singleton
private:
public:
    Player() {}
    ~Player() {}
    int curWand = 1;
    std::array<Wand*, 4> wands{};
    std::array<Spell*, 10> storedSpells{};
};

#endif