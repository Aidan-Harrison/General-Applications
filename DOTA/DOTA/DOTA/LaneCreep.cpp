#include "LaneCreep.h"

void LaneCreep::CheckBase(Base &b) {
	return;
}

int LaneCreep::AutoAttack() {
	std::cout << "Lane creep hit!\n";
	return m_Damage;
}