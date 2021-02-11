#ifndef Weapons_h
#define Weapons_h

#include <iostream>
#include <cassert>

class Weapon {
private:
public:
	short m_Damage, m_Range, m_Weight, m_Ammo;
	std::string wepName = "";
	Weapon(std::string name, short damage, short range, short weight, short ammo)
		:m_Damage(damage), m_Range(range), m_Weight(weight), m_Ammo(ammo)
	{
		assert(m_Damage != 0 && m_Range != 0 && m_Weight != 0);
	}
	~Weapon() = default;
};

#endif