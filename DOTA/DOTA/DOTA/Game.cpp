#include <iostream>

#include "Player.h"
#include "Map.h"

void ShopInterface(Player &p);
void Roshan(std::vector<Hero>& team, Map& m, Player& p);

void Game(Player& p, Map& m) { // Move to seperate file!?
	system("cls");
	// Simulate game, give player option per tick
	std::cout << "Time: " << m.timeOfDay << '\n';
	std::cout << "Radiant \t Dire\n";
	std::cout << "What would you like to do?\n";
	std::cout << "P) Shop  R) Roshan  X) End game\n";
	std::cin >> p.choice;
	std::tolower(p.choice); // Check!
	switch (p.choice) {
		case 'p': ShopInterface(p);
		case 'r': Roshan(p.teamMembers, m, p); // Do team better
		case 'x': exit(1);
	}
}
