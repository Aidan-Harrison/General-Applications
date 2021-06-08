#include "CraftingItem.h"

void AgonyOrb::Use(Item *i) {
}

void PerfectionOrb::Use(Item *i) {
	i->rarity++;
	if(i->rarity >= 4)
		i->rarity = 4;
}