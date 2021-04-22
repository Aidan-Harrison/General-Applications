#include "LaneCreep.h"

void LaneCreep::CheckBase(Base &b) {
	return;
}

short LaneCreep::AutoAttack() {
	std::cout << "Lane creep hit!\n";
	return m_Damage;
}