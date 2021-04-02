#include <iostream>
#include <thread>
#include <chrono>

#include "Player.h"
#include "Map.h"
#include "JungleCreep.h"

using namespace NeutralItems;

void ShopInterface(Player &p);
void Roshan(std::vector<Hero>& team, Map& m, Player& p);

// Randomises between a set of predetermined camps | Check!
void Jungle(Player &p, Map&m) { // Map is currently unessecary! Wasted reference
	bool hasSpawned = true;
	if(!hasSpawned) // Do!
		Game(p, m);
	else {
		short jungleCamp = 0, spawnTime = 10;
		std::vector<JungleCreep> creeps{};
		jungleCamp = rand() % 5; // Convert to rand singleton
		jungleCamp++;
		if(jungleCamp == 1) { // No need to execute a for loop
			JungleCreep j1{ 250, 25 };
			JungleCreep j2{ 100, 10 };
			creeps.push_back(j1);
			creeps.push_back(j2);
		}
		else if(jungleCamp == 2) {
			JungleCreep j1{ 150, 20 };
			JungleCreep j2{ 150, 20 };
			JungleCreep j3{ 150, 20 };
			creeps.push_back(j1);
			creeps.push_back(j2);
			creeps.push_back(j3);
		}
		else if(jungleCamp == 3) {
			JungleCreep j1{ 300, 40 };
			JungleCreep j2{ 250, 35 };
			creeps.push_back(j1);
			creeps.push_back(j2);
		}
		else if(jungleCamp == 3) {
			JungleCreep j1{ 50, 10 };
			JungleCreep j2{ 100, 15 };
			JungleCreep j3{ 50, 10 };
			creeps.push_back(j1);
			creeps.push_back(j2);
			creeps.push_back(j3);
		}
		else if (jungleCamp == 4) {
			JungleCreep j1{ 500, 75 };
			creeps.push_back(j1);
		}
		while (p.fighting) {
			// Main ============================================
			std::cout << "Health: " << p.currentHero->m_Health;
			for (unsigned int i = 0; i < creeps.size(); i++) { std::cout << "Creep Health: " << "/" + creeps[i].m_Health / 10 << " | " << creeps[i].m_Health; }
			if(p.currentHero->m_Health == 0) { // Move to function within player
				std::cout << "You died!\n";
				p.fighting = false;
			}
			if(p.currentHero->m_Health < 100) {
				std::cout << "Your health is low, consider leaving the jungle?\n Would you like to leave?";
				std::cout << "y/n\n"; std::cin >> p.choice;
				std::tolower(p.choice);
				if(p.choice == 'y') // Do!
					return;
				else if(p.choice == 'n')
					return;
				else {
					std::cout << "You have entered an incorrect option!\n Try again!\n";
				}
			}
			std::cout << "What would you like to do: \nS) Keep fighting  L) Leave\n"; std::cin >> p.choice;
			std::tolower(p.choice); // Check (No header!)
			if(p.choice == 's') { // Player attack
				p.chanceToAttack = rand() % 2; // Convert to rand singleton
				if (p.chanceToAttack > 1) {
					jungleCamp = rand() % creeps.size(); // Re-use
					short temp = creeps[jungleCamp].m_Health;
					creeps[jungleCamp].m_Health -= p.currentHero->AutoAttack(); // Check '->'
					//std::cout << "You dealt " << creeps[jungleCamp].m_Health - temp << " damage\n";
				//}
				//else {
					//std::cout << "Miss!\n";
				//}
				jungleCamp = rand() % 2; // Convert to rand singleton
				if (jungleCamp > 1) {
					short temp = p.currentHero->m_Health;
					p.currentHero->m_Health -= creeps[jungleCamp].m_Damage;
					std::cout << "A jungle creep successfully attacks!\n";
					std::cout << "You took " << p.currentHero->m_Health - temp << " damage\n";
				}
				else {
					std::cout << "Jungle creep missed!\n";
				}
				// Check camp health
				for(int i = 0; i < creeps.size(); i++) {
					if(creeps[i].m_Health == 0) { // Do neutral item
						std::cout << "Jungle creep killed!\n";
						// Neutral Items:
						jungleCamp = rand() % neutralItems.size(); // Convert to rand singleton
						creeps[i].m_NeutralItem = &neutralItems[jungleCamp]; // Check!
						// Erase from vector | Fix!
						// creeps.erase(creeps[i]);
					}
				}
			}
			else if(p.choice == 'l') {
				Game(p, m);
			}
		}
	}
}

short ChangeTick(Map &m) { // Check return!
	std::cout << "Current tick rate (Milliseconds): " << m.tickRate << '\n' 
			  << "What would you like the tick rate to be (Avoid going below 200 miliiseconds): "; std::cin >> m.tickRate;
}

void Game(Player& p, Map& m) {
	bool gameRunning = true;
	while(gameRunning) {
		system("cls");
		// Simulate game, give player option per tick
		std::cout << "Time: " << m.minutes << " : " << m.seconds << '\n';
		std::cout << "Radiant Ancient: " << m.bases[0].ancientHealth << '\n';
		std::cout << "Dire Ancient: " << m.bases[1].ancientHealth << '\n';
		std::cout << "Radiant\n";
		for(unsigned int i = 0; i < 5; i++) std::cout << m.radiantTeam[i].m_Name << ", ";
		std::cout << "Dire\n";
		for(unsigned int i = 0; i < 5; i++) std::cout << m.direTeam[i].m_Name << ", ";
		if(m.bases[1].ancientHealth == 0) {
			std::cout << "The Radiant's ancient has fallen!\n";
			gameRunning = false;
			break;
		}
		else if(m.bases[2].ancientHealth == 0) {
			std::cout << "The Dire's ancient has fallen!\n";
			gameRunning = false;
			break;
		}
		std::cout << "What would you like to do?\n";
		std::cout << "P) Shop  J) Jungle  R) Roshan  C) Continue  T) Change tick rate  X) End game\n";
		std::cin >> p.choice;
		std::tolower(p.choice); // Check!
		switch (p.choice) {
			case 'p': ShopInterface(p);
			case 'j': Jungle(p, m);
			case 'r': Roshan(p.teamMembers, m, p); // Do team better
			case 'c': continue; // Check!
			case 't': m.tickRate = ChangeTick(m); // Do this!, avoid passing the player around!
			case 'x': exit(1);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(m.tickRate)); // Add speed modifier
		m.seconds++;
		if(m.seconds == 60) {
			m.minutes++;
			m.seconds = 0;
		}
	}
	std::cout << "Game has ended!\n" << "Game summary\n";
	std::cout << "Player Stats\n";
	std::cout << "Gold: " << p.currentHero->gold << '\n';
	std::cout << "Creeps killed: " << p.creepsKilled << '\n';
	// Print team and their stats
		
	exit(1);
}
