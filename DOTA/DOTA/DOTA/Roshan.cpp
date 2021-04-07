#include <iostream>
#include <vector>
#include <ctime>

#include "Hero.h"
#include "Map.h"
#include "Random.h"
#include "Player.h"
#include "JungleCreep.h"

void Game(Player& p, Map& m);

Random randomGen; // Move semantics

void RoshanFight(std::vector<Hero>& team, Map& m, Player &p) { // Randomize amount of members in pit
	system("cls");
	if(m.m_RoshUp) {
		Roshan rosh;
		srand(time(0));
		short teamAmount = 0;
		std::vector<Hero> teamPit = {};
		teamAmount = rand() % 5;
		for(unsigned int i = 0; i < teamAmount; i++) {
			teamPit.push_back(team[i]);
		}
		std::cout << "Team members in pit:\n";
		for(unsigned int i = 0; i < teamPit.size(); i++)
			std::cout << teamPit[i].m_Name << '\n';
		Item Aegis{"Aegis of the Immortal", 0, "Revives you once", false};
		if(m.minutes > 30) // Change?
			Item Cheese{"Cheese", 0, "Restores health and mana to full instantly", true};
		while(!rosh.isDead) {
			system("cls");
			std::cout << "ROSHAN FIGHT!\n Rosh Health: " << std::string("/" + rosh.m_Health) 
					  << "Player Health: \n" << std::string("/" + p.currentHero->m_Health / 10)
					  << "Player Mana: \n"   << std::string("/" + p.currentHero->m_Mana / 10); // Possibly convert to functions via header
			// Player condition
			if(p.currentHero->m_Health == 0) { // Move to function within player
				std::cout << "You have fallen to Roshan!\n";
				p.fighting = false; // Check fighting var!!!!??
				break;
			}
			if(p.currentHero->m_Health < 100) {
				std::cout << "Your health is low, consider leaving?\n Would you like to leave? "
					<< "y/n \t"; std::cin >> p.choice;
				std::tolower(p.choice);
				switch (p.choice) {
				case 'y': Game(p, m);
				case 'n': continue;
				}
				if (p.choice != 'y' && p.choice != 'n') {
					std::cout << "You have entered an incorrect value. Try again!\n";
				}
			}
			// Team condition
			for (unsigned int i = 0; i < teamPit.size(); i++) {
				std::cout << teamPit[i].m_Name;
				std::cout << "Health: " << std::string("/" + teamPit[i].m_Health) << " | " << teamPit[i].m_Health;
				std::cout << "Mana: " << std::string("/" + teamPit[i].m_Mana) << " | " << teamPit[i].m_Mana;
				std::cout << "=============================================================\n";
			}
			p.currentHero->m_Health = rosh.AutoAttack(); // Fix!
			// Player
			short temp = rosh.m_Health;
			rosh.m_Health -= p.currentHero->AutoAttack();
			std::cout << "hit Roshan for: " << temp - rosh.m_Health << " damage"; // Do team part
			// Check for team members and player health
		}
		std::cout << "Roshan has fallen to the: \n"; // Add team
		std::cout << "Roshan dropped: " << // Re-do
					  Aegis.m_ItemName;
	}
	else {
		std::cout << "Roshan has not spawned!\n" << "Press ENTER to continue ";
		std::cin.get();
		std::cin.get();
		Game(p, m);
	}
	return;
}