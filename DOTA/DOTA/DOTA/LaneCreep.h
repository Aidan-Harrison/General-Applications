#ifndef LaneCreep_h
#define LaneCreep_h

#include <iostream>
#include <cassert>
#include "Item.h"

struct LaneCreep {
	int health = 100, m_exp = 25, damage = 30, goldToGive = 35;
	bool dead = false;
	LaneCreep() {
		assert(health != 0 && m_exp != 0 && damage != 0);
	}
	~LaneCreep() = default;
};

#endif
