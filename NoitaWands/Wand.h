#ifndef Wand_h
#define Wand_h

#include <iostream>
#include <vector>
#include <thread>

#include "Spell.h"

struct Wand {
    std::string wandName = "";
    std::string flavourText = "";
    int damage = 1;
    int range = 10;
    int reloadSpeed = 1;
    int ammo = -1; // -1 = infinite
    int ID = 1; // Global ID board // ? Map solves this
    int curSpell = 0;

    // SpellQueue sQ;
    std::vector<Spell*> spellLoadout{};

    void AddSpell(Spell *s);
    void Fire();

    Wand(const std::string &name)  
        : wandName(name)
    {
    }
    ~Wand() {}
};

void Wand::AddSpell(Spell *s) {
    spellLoadout.push_back(s);
}

void Wand::Fire() {
    std::cout << wandName << '\n'; // Remove! | Debugging only
    std::cout << spellLoadout.size() << '\n';
    for(int i = 0; i < spellLoadout.size(); i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));        
        spellLoadout[i]->Use();
    }
    curSpell++;
    if(curSpell == spellLoadout.size())
        curSpell = 0;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));        
}

#endif