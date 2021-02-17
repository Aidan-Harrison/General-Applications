#ifndef Perks_h
#define Perks_h

#include <iostream>
#include <cassert>

struct Perks {
	std::string perkName = "";
	short m_Health, m_Damage, m_Cost;
	bool hasUniqueProp = false; // Dictates whether a perk has something special about it
	Perks() = default;
	Perks(std::string name, short cost, short health, short damage, bool unique)
		:perkName(name), m_Health(health), m_Damage(damage), m_Cost(cost)
	{
		assert(perkName != " " && m_Cost != 0);
	}
	void PrintPerk(Perks &p);
	void DeletePerk(Perks *p);
	~Perks() = default;
};

#endif