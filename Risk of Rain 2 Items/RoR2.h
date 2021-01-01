#ifndef RoR2_h
#define RoR2_h

#include "Characters.h"

namespace RoR2 {
    extern int rarityCoeffcient;
    extern int itemMod;
    extern bool gameOver;
    extern int userInput;

    extern void PrintCharacters();
    extern void PrintOptions();
    extern void DeleteItem(Characters &character);
}

#endif