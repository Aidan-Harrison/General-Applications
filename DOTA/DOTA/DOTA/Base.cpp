#include "Base.h"

void Base::InitialiseBase() {
	
}

void Base::checkBarracks(std::array<MeleeBarracks, 3> &m, std::array<RangedBarracks, 3> &r) {
	int meleeDestroyed = 0;
	int rangeDestroyed = 0;
	for(unsigned int i = 0; i < 3; i++) {
		if(m[i].health == 0)
			meleeDestroyed++;
		if(r[i].health == 0)
			rangeDestroyed++;
	}
	if(meleeDestroyed == 3)
		meleeBuffed = true;
	if(rangeDestroyed == 3)
		rangeBuffed = true;
}