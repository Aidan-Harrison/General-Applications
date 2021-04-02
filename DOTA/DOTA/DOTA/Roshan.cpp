#include <iostream>
#include <vector>
#include <ctime>

#include "Hero.h"
#include "Map.h"
#include "Random.h"
#include "Player.h"

void Game(Player& p, Map& m);

Random randomGen; // Move semantics

void Roshan(std::vector<Hero>& team, Map& m, Player &p) { // Randomize amount of members in pit
	system("cls");
	if(m.m_RoshUp) {
		short chanceToAttack = 0, health = 5000 * m.minutes / 3, damage = 100 * m.minutes / 25; // Randomize damage in a given ranage
		bool dead = false;
		std::vector<Hero> teamPit = {}; // Unoptimized! Don't need another vector???
		for(unsigned int i = 0; i < team.size(); i++) {
			teamPit.push_back(team[i]);
		}
		std::cout << "Team members in pit:\n";
		for(unsigned int i = 0; i < teamPit.size(); i++)
			std::cout << teamPit[i].m_Name << '\n';
		Item Aegis{"Aegis of the Immortal", 0, "Revives you once", false};
		if(m.minutes > 30) // Change?
			Item Cheese{"Cheese", 0, "Restores health and mana to full instantly", true};
		std::cout << "ROSHAN FIGHT!\n";
		std::cout << "Rosh Health: " << health;
		while(!dead) {
			// Roshan
			// chanceToAttack = rand() % 10;
			chanceToAttack = randomGen.GetInt(10); // Check!
			if(chanceToAttack > 5) {
				std::cout << "Rosh Swing!\n";
				chanceToAttack = rand() % team.size();
				team[chanceToAttack].m_Health -= damage; // Calculate damage reduction, randomize damage between range! | Add player
				std::cout << "You took: " << damage << " damage\n";
			}
			else {
				std::cout << "Roshan misses!\n";
			}
			// Player
			chanceToAttack = randomGen.GetInt(10);
			if(chanceToAttack > 5) {
				chanceToAttack = randomGen.GetInt(5);
				std::cout << "hit Roshan for: "; // Do team part
			}
			// Check for team members and player health
		}
		std::cout << "Roshan has fallen to the: \n"; // Add team
		std::cout << "Roshan dropped: " <<
					  Aegis.m_ItemName;
	}
	else {
		std::cout << "Roshan has not spawned!\n";
		return; // Go back to game
	}
	return;
}