#ifndef JungleCreep_h
#define JungleCreep_h

#include <cassert>
#include "Item.h"

struct JungleCreep {
	short m_Health = 0, damage = 0, magicRes = 10, armour = 10;
	bool isDead = false, canDrop = false;
	Item item;
	JungleCreep() = default;
	JungleCreep(short health) // Itialise with item??
		:m_Health(health)
	{
		assert(health != 0);
	}
	~JungleCreep() = default;
};

struct Roshan : JungleCreep {
	short chanceToStun = 0;
};

#endif