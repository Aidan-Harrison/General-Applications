#ifndef Spell_h
#define Spell_h

#include <iostream>

struct Spell {
    std::string spellName = "";
    std::string description = "";
    std::string properties = "";
    int ID = 0; // Set to global ID board
    Spell(const std::string &name) 
        : spellName(name)
    {
    }

    virtual void Use() { // Poly?
        std::cout << "Used " << spellName << '\n';        
    }

    ~Spell() {}
};



#endif