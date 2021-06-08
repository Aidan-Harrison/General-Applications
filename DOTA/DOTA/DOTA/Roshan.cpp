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
	std::vector<Hero> teamPit = {};
	int teamAmount = 0;
	srand(time(0));
	system("cls");
	if(m.m_RoshUp) { // Do!
		Roshan rosh;
		Item Aegis{"Aegis of the Immortal", 0, "Revives you once", false};
		if(m.minutes > 30)
			Item Cheese{"Cheese", 0, "Restores health and mana to full instantly", true};
		teamAmount = rand() % 5;
		teamAmount++;
		for(unsigned int i = 0; i < teamAmount; i++) {
			teamPit.push_back(team[i]);
		}
		std::cout << "Team members in pit:\n";
		//for(unsigned int i = 0; i < teamPit.size(); i++)
			//std::cout << teamPit[i].GetName() << '\n';
		while(!rosh.isDead) {
			system("cls");
			std::cout << "ROSHAN FIGHT!\n Rosh Health: " << std::string(rosh.m_Health / 100, '|') << " : " << rosh.m_Health
					  << "\nPlayer Health: \n" << std::string(p.currentHero->m_Health / 10, '|')
					  << "\nPlayer Mana: \n" << std::string(p.currentHero->m_Mana / 10, '|'); // Possibly convert to functions via header
			// Player condition
			if(p.currentHero->m_Health == 0) { // Move to function within player?
				std::cout << "You have fallen to Roshan!\n";
				p.fighting = false; // Check fighting var!!!!??
				break;
			}
			if(p.currentHero->m_Health < 200) {
				while (1) {
					std::cout << "Your health is low, consider leaving?\n Would you like to leave? y/n\n"; std::cin >> p.choice;
					std::tolower(p.choice);
					switch (p.choice) {
						case 'y': Game(p, m);
						case 'n': break;
					}
					if(p.choice != 'y' && p.choice != 'n') {
						std::cout << "You have entered an incorrect value. Try again!\n";
						system("cls");
					}
				}
			}
			// Team condition | Fix!
			for (unsigned int i = 0; i < teamPit.size(); i++) {
				std::cout << teamPit[i].GetName();
				std::cout << "Health: " << std::string(teamPit[i].m_Health / 10, '|') << " : " << teamPit[i].m_Health;
				std::cout << "Mana: " << std::string(teamPit[i].m_Mana / 10, '|') << " : " << teamPit[i].m_Mana;
				std::cout << "=============================================================\n";
			}
			// Player | Improve this to take into account everything
			p.currentHero->ChangeHealth(rosh.m_Damage, 'p'); // Do stun!
			int temp = rosh.m_Health;
			rosh.m_Health -= p.currentHero->AutoAttack();
			std::cout << "hit Roshan for: " << temp - rosh.m_Health << " damage"; // Do team part
			// Check for team members and player health
			// Flush strings!?
		}
		rosh.isDead = true;
		std::cout << "Roshan has fallen to the: \n"; // Add team
		std::cout << "Roshan dropped: " <<
					  Aegis.GetName();
	}
	else {
		std::cout << "Roshan has not spawned!\n" << "Press ENTER to continue ";
		std::cin.get();
		std::cin.get();
		Game(p, m);
	}
	return;
}