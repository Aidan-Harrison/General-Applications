#include "LaneCreep.h"

void LaneCreep::CheckBase(Base &b) {
	int amountDestroyed = 0;
	for (unsigned int i = 0; i < 3; i++) {
		if (b.rB[i].health == 0) amountDestroyed++;
		else if (b.mB[i].health == 0) amountDestroyed++;
	}
	if(amountDestroyed = 6)
		isMega = true;
}

short LaneCreep::AutoAttack() {
	std::cout << "Lane creep hit!\n";
	return m_Damage;
}