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

void ShopSetup(); // In shop.cpp
void Game(Player& p, Map& m);

// Remove these from global?
Map map;
Player player;

void PlayerSetup() { // Possibly convert to a single loop | Sort and print in alphabetical order!
	short choice = 0, team = 0, index = 1;
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

	// Hero Pick
	std::cout << "Pick your hero: "; std::cin >> choice;
	player.currentHero = &heroes[choice]; // Fix!
	player.teamID = rand() % 3;
	player.teamID++;
	player.teamID == 1 ? player.currentTeam = "Radiant" : player.currentTeam = "Dire"; // Check!
	std::cout << "You are playing as " << player.currentHero->GetName() << " and are on team: " << player.currentTeam;
	std::cout << "\nYour health is " << player.currentHero->GetHealth() << " | Base health regen: " << player.currentHero->m_HealthRegen;
	std::cout << "\nYour mana is " << player.currentHero->GetMana() << " | Base mana regen: " << player.currentHero->m_ManaRegen;
	std::cout << "\nYour armor is: " << player.currentHero->GetArmor();
	std::cout << "\nYour magic resistance is: " << player.currentHero->GetMagicRes();
	std::cin.get();
	std::cin.get();
}

// Add team compositions | Move to map setup!?
void TeamSetup() {
	srand(time(0));
	int membersToAdd = 0;
	for(unsigned int i = 0; i < 5; i++) { // Do better randomisation!?
		membersToAdd = rand() & heroes.size() - 1; // Change to custom rand singleton | Prevent subscript range error
		map.radiantTeam.push_back(heroes[membersToAdd]);
		membersToAdd = rand() & heroes.size() - 1; // Change to custom rand singleton
		map.direTeam.push_back(heroes[membersToAdd]);
		//map.radiantTeam[i].AddAbilities(Heroes::rikiAbilities);
	}
	//std::cout << "Teams\n";
	//for(unsigned int i = 0; i < 10; i++) { // Fix overflow
		//if(i <= 4) std::cout << map.radiantTeam[i].m_Name << '\n';
		//else if(i > 4) std::cout << map.direTeam[i].m_Name << '\n';
	//}
}

int main() {
	PlayerSetup();
	TeamSetup();
	ShopSetup();
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
	Game(player, map);

	return 0;
}

