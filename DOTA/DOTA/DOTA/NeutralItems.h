#ifndef NeutralItem_h
#define NeutralItem_h

#include <vector>
#include "Item.h"

// Ineffcient, should only create objects when necessary!!!!!!!!!!!!!!!!!!!
namespace NeutralItems {
	Item RoyalJelly{ "Royal Jelly", 0, "Gives you permenant HP and Mana regen", true, "Jelly Player", "Apply to another teamate", true };
	Item PaladinsSword{ "Paladins Sword", 0, "Damage and lifesteam", false, " ", "20 damage, 16% lifesteal", true };
}

std::vector<Item> neutralItems{
	NeutralItems::RoyalJelly,
	NeutralItems::PaladinsSword
}; // Remove once map(hash table) is solved, shouldn't be in global

#endif