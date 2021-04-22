#include <iostream>
#include <array>
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
void EndScreen(Player &p, Map &m);
void CheckVision();

// Move these!
bool jungVision = false;
bool laneVision = false;

// Randomises between a set of predetermined camps | Check!
void Jungle(Player &p, Map&m) { // Map is currently unessecary! Wasted reference | Add teams
	jungVision = true;
	bool hasSpawned = true;
	short amountKilled = 0;
	if(!hasSpawned)
		Game(p, m);
	else {
		p.fighting = true;
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
		while(p.fighting) {
			system("cls");
			std::cout << "======JUNGLE======\n";
			// Main ============================================
			p.currentHero->PrintStats();
			putchar('\n');
			for (unsigned int i = 0; i < creeps.size(); i++) { 
				std::cout << i << ") Creep Health: " << std::string(creeps[i].m_Health / 10, ' |') << " : " << creeps[i].m_Health << '\n'; 
			}
			if(p.currentHero->m_Health == 0) { // Move to function within player
				std::cout << "You died!\n";
				p.fighting = false;
				p.currentHero->m_Dead = true; // Pointless if below function exists? Depends on how said function turns out
				p.currentHero->RespawnTime();
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
			std::cout << "\nWhat would you like to do: \nS) Keep fighting  L) Leave\n"; std::cin >> p.choice;
			std::tolower(p.choice);
			if (p.choice == 's') {
				jungleCamp = rand() % creeps.size(); // Re-use integer
				// Player attack
				short temp = creeps[jungleCamp].m_Health;
				creeps[jungleCamp].m_Health -= p.currentHero->AutoAttack();
				std::cout << "You dealt " << temp - creeps[jungleCamp].m_Health << " damage\n"; // Possibly move into auto attack function, account for miss chance and items
				// Jungle creep attack | Move to function!
				temp = p.currentHero->m_Health;
				p.currentHero->m_Health -= creeps[jungleCamp].AutoAttack();
				std::cout << "You took " << temp - p.currentHero->m_Health << " damage\n";
				// Check camp health
				for (unsigned int i = 0; i < creeps.size(); i++) {
					if (creeps[i].m_Health == 0) { // Do neutral item
						neutralItems[jungleCamp]; // Do!
						bool hasDropped = creeps[i].KillCreep(neutralItems); // Check!
						amountKilled++;
						if(hasDropped) {
							while (1) {
								std::cout << "Jungle creep dropped item: " << "\nTake it? y/n"; std::cin >> p.choice;
								if (p.choice == 'y') {
									// 
									for (unsigned int i = 0; i < p.currentHero->m_Inventory.size(); i++) {
										//p.currentHero->m_Inventory[i] = creeps[i].GetItem(); // Fix!
									}
									break;
								}
								else if (p.choice == 'n') {
									// Delete neutral item
									break;
								}
								else {
									std::cout << "You have entered an incorrect value. Try again!\n";
									system("cls"); // Possibly remove?
								}
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

// Will always run for 3 ticks
void Laning(Player &p, Map &m) { // Add teams
	laneVision = true;
	short ticks = 0;
	bool laning = false;
	std::array<LaneCreep, 8> creeps{};
	system("cls");
	std::cout << "======LANE======\n";
	while(laning) {
		if(ticks < 3) {
			p.currentHero->PrintStats();
			if (p.currentHero->m_Health < 100) {
				std::cout << "Your health is low, consider leaving!\n";
			}
			for (unsigned int i = 0; i < creeps.size(); i++) {
				std::cout << "Creep created!\n";
				// Calculate attacks

			}
			ticks++;
		}
		std::cout << "What would you like to do?\n"
				  << "1)Continue  2)Jungle  3)Back";
		std::cin >> p.choice;
		switch(p.choice) {
			case 1: continue;
			case 2: Jungle(p, m); break;
			case 3: laning = false; break;
		}
		// Get other team members and enemies
	}
	Game(p, m);
}

short ChangeTick(Map &m) { // Check return!
	std::cout << "Current tick rate (Milliseconds): " << m.tickRate << '\n' 
			  << "What would you like the tick rate to be (Avoid going below 200 miliiseconds): "; std::cin >> m.tickRate;
	return m.tickRate;
}

void Scoreboard(Player &p, Map &m) {
	std::cout << "Radiant Team:\n";
	for (unsigned int i = 0; i < 5; i++) std::cout << m.radiantTeam[i].GetName() << " | ";
	std::cout << "Dire Team:\n";
	for (unsigned int i = 0; i < 5; i++) std::cout << m.direTeam[i].GetName() << " | ";
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
		system("cls");
		std::cout << "======GAME======\n";
		std::cout << "Time: " << m.minutes << " : " << m.seconds << '\n';
		m.GetTime(); // Implement properly into game
		if(m.bases[0].ancientHealth == 0) {
			std::cout << "The Radiant's ancient has fallen!\n  -DIRE VICTORY-";
			gameRunning = false;
			break;
		}
		else if(m.bases[1].ancientHealth == 0) {
			std::cout << "The Dire's ancient has fallen!\n  -RADIANT VICTORY-";
			gameRunning = false;
			break;
		}
		std::cout << "\nRadiant Ancient: " << std::string(m.bases[0].ancientHealth / 100, '|') << " : " << m.bases[0].ancientHealth 
				  << "\nDire Ancient: "    << std::string(m.bases[1].ancientHealth / 100, '|') << " : " << m.bases[1].ancientHealth;
		std::cout << "\nRadiant Team:\n\t";
		for(unsigned int i = 0; i < 5; i++) std::cout << m.radiantTeam[i].GetName() << " | ";
		std::cout << "\nDire Team:\n\t";
		for(unsigned int i = 0; i < 5; i++) std::cout << m.direTeam[i].GetName() << " | ";
		// Player
		std::cout << "\n===PLAYER==="; // Add usernames?
		p.currentHero->PrintStats();
		p.currentHero->PrintInventory();

		// Vision
		if(jungVision) {
			std::cout << "You can see jungle:\n";
			// Check jungle
		}
		if (laneVision) {
			std::cout << "You can see lane:\n";
			// Check lane
		}

		std::cout << "\n\nWhat would you like to do?\n";
		std::cout << "P) Shop  L) Laning  J) Jungle  R) Roshan  S) Scoreboard  C) Continue  T) Change tick rate  X) End game\n";
		std::cin >> p.choice;
		system("cls");
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
	EndScreen(p, m);
}

// Extra
void EndScreen(Player &p, Map &m) {
	std::cout << "Game has ended!\n" << "Game summary\n";
	std::cout << "Player Stats\n";
	std::cout << "Gold: " << p.currentHero->gold << '\n';
	std::cout << "Creeps killed: " << p.creepsKilled << '\n';
	Scoreboard(p, m);
	std::cin.get();
	exit(0);
}

void StartScreen() {
	std::cout << "=====GAME STARTING=====\n";
	// Print teams, move part of main file to here
	// Used threads and load?
}

void CheckVision() {
	return;
}