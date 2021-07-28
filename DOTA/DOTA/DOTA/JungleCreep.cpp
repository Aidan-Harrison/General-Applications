#include "JungleCreep.h"

void JungleCreep::AutoAttack(Hero &h) { // Return by address?? Would have to modify hero fundamentals
	m_ChanceToAttack = Random::GetInt(5); // Check static on rand, defeats point of singleton???
	if (m_ChanceToAttack > 2) {
		std::cout << "A jungle creep successfully attacks!\n";
		h.ChangeHealth(m_Damage, 'p');
	}
	else {
		std::cout << "Jungle creep missed!\n";
	}
}

bool JungleCreep::KillCreep(std::vector<Item> &neutrals) {
	int chanceToDrop = 0;
	std::cout << "Creep killed!\n";
	isDead = true; // Pointless??
	chanceToDrop = rand() % 10; // Convert to rand singleton, scale with game??
	if(chanceToDrop > 7) {
		std::cout << "Has dropped!\n";
		chanceToDrop = rand() % neutrals.size(); // Re-use same integer
		m_NeutralItem = &neutrals[chanceToDrop]; // Change int at a later date | Check ref!
		return true;
	}
	else {
		return false;
	}
}

Item& JungleCreep::GetItem() { // Check!
	return *m_NeutralItem;
}

// Merge into polymorphic function
void Roshan::AutoAttack(Hero& h) { // Player function overload?
	chanceToAttack = rand() % 5; // Use rand singleton?
	if (chanceToAttack > 1) {
		std::cout << "Roshan swings!\n";
		chanceToStun = rand() % 5;
		if (chanceToStun > 3) {
			h.m_Health -= m_Damage; // Change to return
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

void Roshan::RoshDeath() {

}