#include "Perks.h"

void Perks::PrintPerk(Perks &p) {
	std::cout << "Name: "   << p.perkName << '\n' <<
				 "Cost: "   << p.m_Cost   << '\n' <<
				 "Damage: " << p.m_Damage << '\n' <<
				 "Health: " << p.m_Health << '\n' <<
				 "Unique: " << p.hasUniqueProp;
};
void Perks::DeletePerk(Perks *p) {
	delete p;
};