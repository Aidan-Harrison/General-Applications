#ifndef Weapons_h
#define Weapons_h

#include <iostream>
#include <cassert>

class Weapon {
private:
public:
	int m_Damage, m_Range, m_Weight, m_Ammo;
	std::string wepName = "";
	bool isWonder = false; // Dictates whether a gun has something special about it
	Weapon(std::string name = "Default", int damage = 10, int range = 5, int weight = 1, int ammo = 50, bool unique = false)
		:wepName(name), m_Damage(damage), m_Range(range), m_Weight(weight), m_Ammo(ammo)
	{
		assert(m_Damage != 0 && m_Range != 0 && m_Weight != 0 && ammo != 0);
	}

	~Weapon() {};
};

#endif