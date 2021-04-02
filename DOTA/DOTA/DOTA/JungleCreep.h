#ifndef JungleCreep_h
#define JungleCreep_h

#include <cassert>
#include "Item.h"

struct JungleCreep {
	short m_Health = 0, m_Damage = 0, magicRes = 10, armour = 10;
	bool isDead = false, canDrop = false;
	Item *m_NeutralItem;
	JungleCreep() = default;
	JungleCreep(short health, const short damage) // Itialise with item??
		:m_Health(health), m_Damage(damage)
	{
		assert(health != 0 && damage != 0);
	}
	~JungleCreep() = default;
};

struct Roshan : JungleCreep {
	short chanceToStun = 0;
};

#endif