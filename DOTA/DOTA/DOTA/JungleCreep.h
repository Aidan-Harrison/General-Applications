#ifndef JungleCreep_h
#define JungleCreep_h

#include <cassert>
#include "Item.h"
#include "Random.h"
#include "Hero.h"

struct JungleCreep {
	short m_Health = 0, m_Damage = 0, magicRes = 10, armour = 10, m_ChanceToAttack = 0;
	bool isDead = false, canDrop = false;
	Item *m_NeutralItem; // Initialise!
	JungleCreep() = default;
	JungleCreep(short health, short damage)
		:m_Health(health), m_Damage(damage)
	{
		assert(health != 0 && damage != 0);
	}
	~JungleCreep() = default;
	short AutoAttack() { // Move to .cpp file? | Return by address?? Would have to modify hero fundamentals
		m_ChanceToAttack = Random::GetInt(5); // Check static on rand, defeats point of singleton???
		if (m_ChanceToAttack > 2) {
			std::cout << "A jungle creep successfully attacks!\n";
			return m_Damage;
		}
		else {
			std::cout << "Jungle creep missed!\n";
			return 0;
		}
		return 0;
	}
};

struct Roshan : public JungleCreep { // Check public! | Object construction not working
	short chanceToAttack = 0, chanceToStun = 0;
	Roshan() = default;
	~Roshan() = default;
	void RoshAutoAttack(Hero &h) { // Player function overload?
		chanceToAttack = rand() % 5; // Use rand singleton?
		if(chanceToAttack > 1) {
			std::cout << "Roshan swings!\n";
			chanceToStun = rand() % 5;
			if (chanceToStun > 3) {
				h.m_Health -= m_Damage;
				h.m_isStunned = true;
				h.m_StunDuration = 1; // Refers to the amount of ticks
				std::cout << "Roshan stuns!\n";
			}
			else {
				std::cout << "Roshan hits!\n";
				h.m_Health -= m_Damage;
			}
		}
		else {
			std::cout << "Roshan missed!\n";
		}
	}
};

#endif