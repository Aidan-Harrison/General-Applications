#include <iostream>
#include <thread>
#include <chrono>

#include "Player.h"
#include "Map.h"
#include "JungleCreep.h"

// using namespace NeutralItems;

void ShopInterface(Player &p);
void RoshanFight(std::vector<Hero>& team, Map& m, Player& p);
void Game(Player& p, Map& m);

// Randomises between a set of predetermined camps | Check!
void Jungle(Player &p, Map&m) { // Map is currently unessecary! Wasted reference
	bool hasSpawned = true;
	short amountKilled = 0;
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
			for (unsigned int i = 0; i < creeps.size(); i++) { std::cout << "Creep Health: " << std::string("/" + creeps[i].m_Health / 10); }
			if (p.currentHero->m_Health == 0) { // Move to function within player
				std::cout << "You died!\n";
				p.fighting = false;
			}
			if (p.currentHero->m_Health < 100) {
				std::cout << "Your health is low, consider leaving the jungle?\n Would you like to leave? "	
						  << "y/n \t"; std::cin >> p.choice;
				std::tolower(p.choice);
				switch (p.choice) { // Handle incorrect input!!
					case 'y': Game(p, m);
					case 'n': continue;
				}
			}
			std::cout << "What would you like to do: \nS) Keep fighting  L) Leave\n"; std::cin >> p.choice;
			std::tolower(p.choice); // Check (No header!)
			if (p.choice == 's') {
				jungleCamp = rand() % creeps.size(); // Re-use integer
				short temp = creeps[jungleCamp].m_Health;
				creeps[jungleCamp].m_Health -= p.currentHero->AutoAttack(); // Check '->'
				std::cout << "You dealt " << temp - creeps[jungleCamp].m_Health << " damage\n"; // Possibly move into auto attack function
				// Jungle creep
				temp = p.currentHero->m_Health;
				p.currentHero->m_Health -= creeps[jungleCamp].AutoAttack();
				std::cout << "You took " << temp - p.currentHero->m_Health << " damage\n";
				// Check camp health
				for (unsigned int i = 0; i < creeps.size(); i++) {
					if (creeps[i].m_Health == 0) { // Do neutral item
						amountKilled++;
						std::cout << "Jungle creep killed!\n";
						// Neutral Items:
						// jungleCamp = rand() % neutralItems.size(); // Convert to rand singleton
						std::cout << "Jungle creep dropped item: " << "\nTake it? y/n"; std::cin >> p.choice;
						if (p.choice == 'y') // Handle incorrect input
							break;
						else if (p.choice == 'n')
							break;
						// creeps[i].m_NeutralItem = &neutralItems[jungleCamp]; // Check!
							// Erase from vector | Fix!
							// creeps.erase(creeps[i]);
					}
				}
				if(amountKilled == creeps.size()) { // Do fight summary
					hasSpawned = false;
					std::cout << "Camp killed!\n";
					Game(p, m);
				}
			}
			else if (p.choice == 'l') {
				Game(p, m);
			}
		}
	}
}

short ChangeTick(Map &m) { // Check return!
	std::cout << "Current tick rate (Milliseconds): " << m.tickRate << '\n' 
			  << "What would you like the tick rate to be (Avoid going below 200 miliiseconds): "; std::cin >> m.tickRate;
	return m.tickRate;
}

void Scoreboard(Player &p, Map &m) {
	std::cout << "Radiant Team:\n";
	std::cout << "Dire Team:\n";
	std::cout << "Player: =================\n";
	p.currentHero->PrintStats();
	std::cout << "=========================\n"; // Possibly adapt length to max length of said functions
	p.currentHero->PrintAbilities();
	std::cout << "=========================\n";
	p.currentHero->PrintInventory();
	std::cout << "=========================\n";
	p.currentHero->PrintStash();
	std::cout << "=========================\n";
	std::cin.get();
	std::cin.get();
	Game(p, m);
}

void Game(Player& p, Map& m) {
	bool gameRunning = true;
	while(gameRunning) {
		system("cls");
		std::cout << "Time: " << m.minutes << " : " << m.seconds;
		m.GetTime(); // Implement properly into game
		if(m.bases[0]->ancientHealth == 0) {
			std::cout << "The Radiant's ancient has fallen!\n  -DIRE VICTORY-";
			gameRunning = false;
			break;
		}
		else if(m.bases[1]->ancientHealth == 0) {
			std::cout << "The Dire's ancient has fallen!\n  -RADIANT VICTORY-";
			gameRunning = false;
			break;
		}
		// Simulates game, gives player option per tick
		std::cout << "\nRadiant Ancient: " << std::string("/" + m.bases[0]->ancientHealth) << m.bases[0]->ancientHealth 
				  << "\nDire Ancient: "    << std::string("/" + m.bases[1]->ancientHealth) << m.bases[1]->ancientHealth;
		std::cout << "\nRadiant Team\n";
		for(unsigned int i = 0; i < 5; i++) std::cout << m.radiantTeam[i].m_Name << ", ";
		std::cout << "\nDire Team\n";
		for(unsigned int i = 0; i < 5; i++) std::cout << m.direTeam[i].m_Name << ", ";
		// Player
		std::cout << "Player Health: \n" << std::string("/" + p.currentHero->m_Health / 10) 
				  << "Player Mana: \n"   << std::string("/" + p.currentHero->m_Mana / 10); // Possibly convert to functions via header
		std::cout << "What would you like to do?\n";
		std::cout << "P) Shop  J) Jungle  R) Roshan  S) Scoreboard  C) Continue  T) Change tick rate  X) End game\n";
		std::cin >> p.choice;
		std::tolower(p.choice); // Check!
		switch (p.choice) { // Always have tick happen!!!!
			case 'p': ShopInterface(p);
			case 'j': Jungle(p, m);
			case 'r': RoshanFight(p.teamMembers, m, p); // Do team better
			case 's': Scoreboard(p, m);
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
	Scoreboard(p, m); // ?
		
	std::cin.get();
	exit(1);
}
