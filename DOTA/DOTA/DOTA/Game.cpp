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

int screenWidth = 800, screenHeight = 600;

sf::Image background;
sf::Font font;

void Setup() { // Move to different file!
	font.loadFromFile(""); // Do!
}

void Draw(Player &p, Map &m) {
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "DOTA");
	// Scoreboard/Header
	sf::RectangleShape headerBar;
	headerBar.setFillColor(sf::Color::White);
	headerBar.setSize(sf::Vector2f((float)screenWidth, 100.0f));
	headerBar.setOrigin(screenWidth / 2, 50.0f);
	headerBar.setPosition(headerBar.getOrigin().x, headerBar.getOrigin().y);

	sf::Text timeOfDay;
	//timeOfDay.setString(); // Do!
	timeOfDay.setFont(font);
	timeOfDay.setPosition(screenWidth / 2, 50.0f);

	while (window.isOpen()) {

		window.draw(headerBar);
		p.currentHero->Draw(window);
		for (unsigned int i = 0; i < m.direTeam.size(); i++)
			m.direTeam[i].Draw(window);
		for (unsigned int i = 0; i < m.radiantTeam.size(); i++)
			m.radiantTeam[i].Draw(window);

		window.display();
		window.clear();
	}
}

// Randomises between a set of predetermined camps | Check!
void Jungle(Player &p, Map&m) { // Map is currently unessecary! Wasted reference | Add teams
	jungVision = true;
	bool hasSpawned = true;
	int amountKilled = 0;
	if(!hasSpawned)
		Game(p, m);
	else {
		p.fighting = true;
		int jungleCamp = 0, spawnTime = 10;
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
				if(!creeps[i].m_Health <= 0)
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
				char c = std::tolower(p.choice);
				switch (c) {
					case 'y': Game(p, m); break;
					case 'n': continue;
				}
				if(c != 'y' && c != 'n') {
					std::cout << "You have entered an incorrect value. Try again!\n";
				}
			}
			std::cout << "\nWhat would you like to do: \nS) Keep fighting  L) Leave\n"; std::cin >> p.choice;
			char c = std::tolower(p.choice);
			if (c == 's') {
				jungleCamp = rand() % creeps.size(); // Re-use integer
				// Player attack
				int temp = creeps[jungleCamp].m_Health;
				creeps[jungleCamp].m_Health -= p.currentHero->AutoAttack();
				std::cout << "You dealt " << temp - creeps[jungleCamp].m_Health << " damage\n"; // Possibly move into auto attack function, account for miss chance and items
				// Jungle creep attack | Move to function!
				temp = p.currentHero->m_Health;
				creeps[jungleCamp].AutoAttack(*p.currentHero); // Check!
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
								char c = std::tolower(p.choice);
								if (c == 'y') { 
									for (unsigned int i = 0; i < p.currentHero->m_Inventory.size(); i++) {
										p.currentHero->m_Inventory[i] = &creeps[i].GetItem(); // Check!
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
				std::cin.get();
				std::cin.get();
			}
			else if (p.choice == 'l') {
				Game(p, m);
			}
		}
	}
}

// Will always run for 3 ticks
void Laning(Player &p, Map &m) { // Add teams
	system("cls");
	laneVision = true;
	int ticks = 0;
	bool laning = true;
	std::array<LaneCreep*, 8> creeps{};
	for (unsigned int i = 0; i < creeps.size(); i++) {
		LaneCreep* newCreep = new LaneCreep();
		creeps[i] = newCreep;
	}
	std::cout << "======LANE======\n";
	while(laning) {
		system("cls");
		if(ticks < 3) {
			p.currentHero->PrintStats();
			if (p.currentHero->m_Health < 100) {
				std::cout << "Your health is low, consider leaving!\ny/n"; std::cin >> p.choice;
				char c = std::tolower(p.choice);
				switch (c) {
					case 'y': laning = false; break;
					case 'n': continue;
				}
			}
			for (unsigned int i = 0; i < creeps.size(); i++) {
				std::cout << i << ") " << std::string(creeps[i]->GetHealth() / 2, '|') << '\n';
			}
		}
		std::cout << "\nWhat would you like to do?\n"
				  << "1)Continue  2)Jungle  3)Back";
		std::cin >> p.choice;
		switch(p.choice) {
			case 1: continue;
			case 2: Jungle(p, m); break;
			case 3: laning = false; break;
		}
		ticks++;
	}
	Game(p, m);
}

int ChangeTick(Map &m) { // Check return!
	std::cout << "Current tick rate (Milliseconds): " << m.tickRate << '\n' 
			  << "What would you like the tick rate to be (Avoid going below 200 miliiseconds): "; std::cin >> m.tickRate;
	return m.tickRate;
}

void Scoreboard(Player &p, Map &m) {
	std::cout << "Radiant Team:\n";
	for (unsigned int i = 0; i < 5; i++) {
		std::cout << m.radiantTeam[i].GetName() << " | ";
		m.radiantTeam[i].PrintStats();
		putchar('\n');
	}
	std::cout << "Dire Team:\n";
	for (unsigned int i = 0; i < 5; i++) {
		std::cout << m.direTeam[i].GetName() << " | ";
		m.direTeam[i].PrintStats();
		putchar('\n');
	}
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
		std::cout << "TIME: M|" << m.minutes << " : " << "S|" << m.seconds << '\n';
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
		// p.currentHero->PrintInventory();

		// Vision
		if(jungVision) {
			std::cout << "You can see the jungle:\n";
			// Check jungle
		}
		if (laneVision) {
			std::cout << "You can see the lane:\n";
			// Check lane
		}

		std::cout << "\n\nWhat would you like to do?\n";
		std::cout << "P) Shop  L) Laning  J) Jungle  R) Roshan  S) Scoreboard  C) Continue  T) Change tick rate  X) End game\n";
		std::cin >> p.choice;
		system("cls");
		char c = std::tolower(p.choice);
		switch (c) { // Always have tick happen!!!!????
			case 'p': ShopInterface(p);
			case 'l': Laning(p, m);
			case 'j': Jungle(p, m);
			case 'r': RoshanFight(p.teamMembers, m, p); // Do team better
			case 's': Scoreboard(p, m);
			case 'c': break;
			case 't': m.tickRate = ChangeTick(m); continue; // Do this!, avoid passing the player around!
			case 'x': EndScreen(p, m);
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
	std::cout << "Game has ended!\n" << "Game summary\n"
			  << "=====Player Stats=====\n"
			  << "Gold: " << p.currentHero->gold << '\n'
			  << "Creeps killed: " << p.creepsKilled << '\n';
	Scoreboard(p, m);
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