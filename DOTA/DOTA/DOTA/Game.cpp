#include <iostream>
#include <thread>
#include <chrono>

#include "Player.h"
#include "Map.h"
#include "NeutralItems.h"
#include "JungleCreep.h"
#include "LaneCreep.h"

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
			std::cout << "======JUNGLE======\n";
			// Main ============================================
			std::cout << "Health: " << p.currentHero->m_Health;
			for (unsigned int i = 0; i < creeps.size(); i++) { std::cout << "Creep Health: " << std::string("/" + creeps[i].m_Health / 10) << " | " << creeps[i].m_Health; }
			if (p.currentHero->m_Health == 0) { // Move to function within player
				std::cout << "You died!\n";
				p.fighting = false;
			}
			if (p.currentHero->m_Health < 100) {
				std::cout << "Your health is low, consider leaving the jungle?\n Would you like to leave? "	
						  << "y/n \t"; std::cin >> p.choice;
				std::tolower(p.choice);
				switch (p.choice) {
					case 'y': Game(p, m);
					case 'n': continue;
				}
				if(p.choice != 'y' && p.choice != 'n') {
					std::cout << "You have entered an incorrect value. Try again!\n";
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
				temp = p.currentHero->m_Health; // Possibly '->' instead?
				p.currentHero->m_Health -= creeps[jungleCamp].AutoAttack();
				std::cout << "You took " << temp - p.currentHero->m_Health << " damage\n";
				// Check camp health
				for (unsigned int i = 0; i < creeps.size(); i++) {
					if (creeps[i].m_Health == 0) { // Do neutral item
						bool hasDropped = creeps[i].KillCreep(neutralItems); // Check!
						amountKilled++;
						if(hasDropped) {
							std::cout << "Jungle creep dropped item: " << "\nTake it? y/n"; std::cin >> p.choice;
							if(p.choice == 'y') {
								return;
								//p.currentHero->m_Inventory[0] = creeps[i].GetItem(); // Fix!
								//p.currentHero.m_Inventory.push_back(creeps[i].m_NeutralItem); // Check! | C-Stlye array, do push via C method, not vector | REPLACE WITH VECTOR, WRITE WRAPPER
							}
							else if (p.choice == 'n') {
								// Delete jungle item?
								break;
							}
							else {
								std::cout << "You have entered an incorrect value. Try again!\n";
							}
						}
							// Erase from vector | Fix!
					}
				}
				if(amountKilled == creeps.size()) { // Do fight summary
					hasSpawned = false;
					std::cout << "Camp killed!\n Press ENTER to leave";
					std::cin.get();
					std::cin.get();
					Game(p, m);
				}
			}
			else if (p.choice == 'l') {
				Game(p, m);
			}
		}
	}
}

void Laning(Player &p, Map &m) { // Add teams
	system("cls");
	std::cout << "======LANE======\n";
	p.currentHero->PrintStats();
	if(p.currentHero->m_Health < 100) {
		std::cout << "Your health is low, consider leaving!\n";
	}
	std::vector<LaneCreep> creeps{};
	for(unsigned int i = 0; i < 6; i++) {
		std::cout << "Creep created!\n";
	}
	std::cin.get();
	std::cin.get();
	Game(p, m);
}

short ChangeTick(Map &m) { // Check return!
	std::cout << "Current tick rate (Milliseconds): " << m.tickRate << '\n' 
			  << "What would you like the tick rate to be (Avoid going below 200 miliiseconds): "; std::cin >> m.tickRate;
	return m.tickRate;
}

void Scoreboard(Player &p, Map &m) {
	std::cout << "Radiant Team:\n";
	for (unsigned int i = 0; i < 5; i++) std::cout << m.radiantTeam[i].m_Name << " | ";
	std::cout << "Dire Team:\n";
	for (unsigned int i = 0; i < 5; i++) std::cout << m.direTeam[i].m_Name << " | ";
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

// Simulates game, gives player option per tick
void Game(Player& p, Map& m) {
	bool gameRunning = true;
	while(gameRunning) {
		std::cout << "======GAME======\n";
		system("cls");
		std::cout << "  Time: " << m.minutes << " : " << m.seconds << '\n';
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
		std::cout << m.bases[0]->ancientHealth; // Fix!!!!!!!!!!!!!!!!!
		std::cout << "\nRadiant Ancient: " << std::string("/" + m.bases[0]->ancientHealth / 100) << " | " << m.bases[0]->ancientHealth 
				  << "\nDire Ancient: "    << std::string("/" + m.bases[1]->ancientHealth / 100) << " | " << m.bases[1]->ancientHealth;
		std::cout << "\nRadiant Team:\n";
		for(unsigned int i = 0; i < 5; i++) std::cout << m.radiantTeam[i].m_Name << " | ";
		std::cout << "\nDire Team:\n";
		for(unsigned int i = 0; i < 5; i++) std::cout << m.direTeam[i].m_Name << " | ";
		// Player
		p.currentHero->PrintStats();
		std::cout << "\nWhat would you like to do?\n";
		std::cout << "P) Shop  L) Laning  J) Jungle  R) Roshan  S) Scoreboard  C) Continue  T) Change tick rate  X) End game\n";
		std::cin >> p.choice;
		std::tolower(p.choice); // Check!
		switch (p.choice) { // Always have tick happen!!!!
			case 'p': ShopInterface(p);
			case 'l': Laning(p, m);
			case 'j': Jungle(p, m);
			case 'r': RoshanFight(p.teamMembers, m, p); // Do team better
			case 's': Scoreboard(p, m);
			case 'c': continue; // Check!
			case 't': m.tickRate = ChangeTick(m); // Do this!, avoid passing the player around!
			case 'x': exit(1);
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(m.tickRate)); // Add speed modifier | Have tick regardless of input!!! (Multi thread?)
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
