#include <iostream>
#include <vector>
#include <ctime>

#include "Hero.h"
#include "Map.h"

void Roshan(std::vector<Hero>& team, Map& m) { // Randomize amount of members in pit
	if(m.m_RoshUp) {
		std::vector<Hero> teamPit = {}; // Unoptimized!
		for(unsigned int i = 0; i < team.size(); i++) {
			teamPit.push_back(team[i]);
		}
		std::cout << "Team members in pit:\n";
		for(unsigned int i = 0; i < teamPit.size(); i++)
			std::cout << teamPit[i].m_Name << '\n';
		Item Aegis{"Aegis of Immortal", 0, "Revives you once"};
		if(m.timeOfDay > 30)
			Item Cheese{"Cheese", 0, "Restores health and mana to full instantly"};
		short chanceToAttack = 0, memberToAttack = 0, health = 5000 * m.timeOfDay / 10, damage = 100 * m.timeOfDay / 25; // Randomize damage in a given ranage
		bool dead = false;
		std::cout << "ROSHAN FIGHT!\n";
		std::cout << "Rosh Health: " << health;
		while(!dead) {
			// Roshan
			chanceToAttack = rand() % 10;
			if(chanceToAttack > 5) {
				std::cout << "Rosh Swing!\n";
				memberToAttack = rand() % team.size(); // Re-use same int?
				team[memberToAttack].m_Health -= damage;
				std::cout << "You took: " << damage << " damage\n";
			}
			else {
				std::cout << "Roshan misses!\n";
			}
			// Player
			chanceToAttack = rand() % 10;
			if(chanceToAttack > 5) {
				std::cout << "You hit Roshan for: "; // Do team part
			}
		}
		if(dead) {
			std::cout << "Roshan has been killed!\n";
		}
	}
	else {
		std::cout << "Roshan has not spawned!\n";
		return;
	}
	return;
}