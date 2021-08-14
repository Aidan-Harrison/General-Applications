#include "HeroList.h"
#include "Player.h"
#include "Map.h"
#include "Random.h"

#include <iostream>
#include <vector>
#include <ctime>
#include <cctype>
#include <algorithm>
#include <fstream>

// Add graphics
#include <SFML/Graphics.hpp>

void ShopSetup(); // In shop.cpp
void Game(Player& p, Map& m);
void Draw(Player &p, Map &m);

std::fstream fileHandler;

void ParseFile(const std::string &filePath) { // Move!?
	fileHandler.open(filePath);
	if (fileHandler.fail()) {
		std::cerr << "Failed to open file! Either corrupt or missing\n";
	}
	else {
		if (filePath.find_last_of(".jpg") || filePath.find_last_of(".jpeg") || filePath.find_last_of(".png")) {
			sf::Image img;
			img.loadFromFile(filePath);
		}
		else if (filePath.find_last_of(".txt")) {
			// Handle file writing
		}
	}
}

void SetupAbilities(Hero &h) { // One giant switch statement, may be a better solution although I do not think so
	switch(h.id) {
		case 1: h.AddAbilities(Heroes::rikiAbilities); break;   // Riki
		case 2: h.AddAbilities(Heroes::sniperAbilities); break; // Sniper
	}
}

void PlayerSetup(Player &p) { // Possibly convert to a single loop | Sort and print in alphabetical order!
	int choice = 0, team = 0, index = 1;
	std::cout << "List of heroes:\n" << "Total: " << heroes.size() << '\n';
	std::cout << "Strength:\n";
	for (unsigned int i = 0; i < heroes.size(); i++) {
		if (heroes[i].type == 0) {
			std::cout << index << ") " << heroes[i].GetName() << '\n';
			index++;
		}
	}
	std::cout << "Agility:\n";
	for (unsigned int i = 0; i < heroes.size(); i++) {
		if (heroes[i].type == 1) {
			std::cout << index << ") " << heroes[i].GetName() << '\n';
			index++;
		}
	}
	std::cout << "Intelligence:\n";
	for (unsigned int i = 0; i < heroes.size(); i++) {
		if (heroes[i].type == 2) {
			std::cout << index << ") " << heroes[i].GetName() << '\n';
			index++;
		}
	}

	/*
	std::cout << "Ban a hero: "; std::cin >> choice;
	heroes[choice].isBanned = true; // Check zeroing

	// Team bans
	std::vector<Hero> bannedHeroes{};
	for (unsigned int i = 0; i < heroes.size(); i++) {
		index = rand() % heroes.size();
		bannedHeroes.push_back(heroes[index]);
		heroes[index].BanHero();
	}
	std::cout << "The following heroes have been banned:\n";
	for (unsigned int i = 0; i < bannedHeroes.size(); i++)
		std::cout << bannedHeroes[i].m_Mana << '\n';

	// Delete any other hero which was not picked
	for (unsigned int i = 0; i < heroes.size(); i++) {
		if (!heroes[i].isBanned)
			heroes[i].BanHero();
	}
	*/

	// Hero Pick | Convert to SFML
	std::cout << "Pick your hero: "; std::cin >> choice;
	p.currentHero = &heroes[choice];
	p.teamID = rand() % 3;
	p.teamID++;
	p.teamID == 1 ? p.currentTeam = "Radiant" : p.currentTeam = "Dire"; // Check!
	std::cout << "You are playing as " << p.currentHero->GetName() << " and are on team: " << p.currentTeam;
	std::cout << "\nYour health is " << p.currentHero->GetHealth() << " | Base health regen: " << p.currentHero->m_HealthRegen;
	std::cout << "\nYour mana is " << p.currentHero->GetMana() << " | Base mana regen: " << p.currentHero->m_ManaRegen;
	std::cout << "\nYour armor is: " << p.currentHero->GetArmor();
	std::cout << "\nYour magic resistance is: " << p.currentHero->GetMagicRes();
	std::cin.get();
	std::cin.get();
	SetupAbilities(heroes[choice]);
}

// Add team compositions | Move to map setup!????
void TeamSetup(Map &m, Player &p) { // Heap allocate heroes? or player
	srand(time(0));
	int membersToAdd = 0;
	if(p.teamID == 1)// Radiant | Add player to respective team, then calcualte rest
		m.radiantTeam.push_back(*p.currentHero); // Check!
	else
		m.direTeam.push_back(*p.currentHero);

	for(unsigned int i = 0; i < 5; i++) {
		membersToAdd = rand() & heroes.size() - 1; // Change to custom rand singleton
		m.radiantTeam.push_back(heroes[membersToAdd]);
		membersToAdd = rand() & heroes.size() - 1;
		m.direTeam.push_back(heroes[membersToAdd]);
	}

	if(m.radiantTeam.size() > 5) 
		m.radiantTeam.pop_back();
	if(m.direTeam.size() > 5) 
		m.direTeam.pop_back();

	for (unsigned int i = 0; i < m.radiantTeam.size(); i++)
		SetupAbilities(m.radiantTeam[i]);
	for (unsigned int i = 0; i < m.direTeam.size(); i++)
		SetupAbilities(m.direTeam[i]);

	if (p.teamID == 1) {
		for (unsigned int i = 0; i < 4; i++)
			p.teamMembers.push_back(m.radiantTeam[i]);
	}
	else {
		for (unsigned int i = 0; i < 4; i++)
			p.teamMembers.push_back(m.direTeam[i]);
	}
}

int main() {
	Map m;
	Player p;

	PlayerSetup(p);
	TeamSetup(m, p);
	ShopSetup();

	// std::thread drawThread(Draw, m, p);
	// DOTA LOGO
	std::fstream file;
	std::string line = " ";
	file.open("Res/Art/DOTALogo.txt"); // Get path working | Convert to PNG when SFML implemented!
	if (file.fail()) {
		std::cerr << "Failed to open file!\n";
	}
	else {
		while(!file.eof()) {
			file >> line;
			std::cout << line << '\n';
		}
	}
	file.close();

	// Fix this | string issue
	/*
		std::cout << "Radiant Team:\n"; 
		for(unsigned int i = 0; i < 1; i++) {
			std::cout << map.radiantTeam[i].m_Name;
			if(player.currentHero->m_Name == map.radiantTeam[i].m_Name)
				std::cout << " (YOU)\n";
			putchar('\n');
		}
		std::cout << "Dire Team:\n";    
		for(unsigned int i = 0; i < 1; i++) {
			std::cout << map.direTeam[i].m_Name;
			if(player.currentHero->m_Name == map.direTeam[i].m_Name)
				std::cout << " (YOU)\n";
			putchar('\n');
		}
	*/
	std::cin.get();
	Game(p, m);

	// drawThread.join();
	return 0;
}

