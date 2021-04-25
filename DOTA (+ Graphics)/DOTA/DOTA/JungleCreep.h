#ifndef JungleCreep_h
#define JungleCreep_h

#include <cassert>
#include "Item.h"
#include "Random.h"
#include "Hero.h"

struct JungleCreep {
	short m_Health = 0, m_Damage = 15, magicRes = 10, armour = 10, m_ChanceToAttack = 0;
	bool isDead = false, canDrop = false;
	Item* m_NeutralItem; // Initialise!
	JungleCreep() = default;
	JungleCreep(short health, short damage)
		:m_Health(health), m_Damage(damage)
	{
		assert(health != 0 && damage != 0);
	}
	~JungleCreep() = default;
	virtual void AutoAttack(Hero &h); // Do
	bool KillCreep(std::vector<Item> &neutrals);
	Item& GetItem();
};

struct Roshan : public JungleCreep {
	short chanceToAttack = 0, chanceToStun = 0;
	Roshan() = default;
	Roshan(short health) // Scale
		:JungleCreep(health, 250)
	{
	}
	~Roshan() = default;
	void AutoAttack(Hero& h);
	void RoshDeath();
};

#endif