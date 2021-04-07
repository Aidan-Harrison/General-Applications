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

// Remove these from global!
Map map;
Player player;

void PlayerSetup() { // Possibly convert to a single loop | Sort and print in alphabetical order!
	short choice = 0, team = 0, index = 1;
	std::cout << "List of heroes:\n" << "Total: " << heroes.size() << '\n';
	std::cout << "Strength:\n";
	for(unsigned int i = 0; i < heroes.size(); i++) {
		if (heroes[i].type == 0) {
			std::cout << index << ") " << heroes[i].m_Name << '\n';
			index++;
		}
	}
	std::cout << "Agility:\n";
	for(unsigned int i = 0; i < heroes.size(); i++) {
		if(heroes[i].type == 1) {
			std::cout << index << ") " << heroes[i].m_Name << '\n';
			index++;
		}
	}
	std::cout << "Intelligence:\n";
	for(unsigned int i = 0; i < heroes.size(); i++) {
		if(heroes[i].type == 2) {
			std::cout << index << ") " << heroes[i].m_Name << '\n';
			index++;
		}
	}
	// Do hero ban!
	std::cout << "Pick your hero: "; std::cin >> choice;
	player.currentHero = &heroes[choice]; // Fix!
	player.teamID = rand() % 3;
	player.teamID++;
	player.teamID == 1 ? player.currentTeam = "Radiant" : player.currentTeam = "Dire"; // Check!
	std::cout << "You are playing as " << player.currentHero->m_Name << " and are on team: " << player.currentTeam;
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
	file.open("Res/Art/DOTALogo.txt"); // Get path working | (Add 'Res'???) | Convert to PNG when SFML implemented!
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