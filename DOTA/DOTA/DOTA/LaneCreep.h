#ifndef LaneCreep_h
#define LaneCreep_h

#include <iostream>
#include <cassert>
#include "Item.h"
#include "Base.h"

struct LaneCreep {
	// Add pathing?
	short health = 100, m_exp = 25, m_Damage = 30, goldToGive = 35;
	bool dead = false, isMega = false;
	LaneCreep() {
		assert(health != 0 && m_exp != 0 && m_Damage != 0);
	}
	~LaneCreep() = default;
	void CheckBase(Base &b);
	short AutoAttack();
};

struct MegaCreep : public LaneCreep {
};

#endif
