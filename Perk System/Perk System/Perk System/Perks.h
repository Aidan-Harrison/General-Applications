#ifndef Perks_h
#define Perks_h

#include <iostream>
#include <cassert>

class Perks {
private:
public:
	std::string perkName = "";
	short m_Health, m_Damage;
	Perks(std::string name, short health, short damage)
		:perkName(name), m_Health(health), m_Damage(damage)
	{
		assert(perkName != " ");
	}
	~Perks() = default;
};

#endif