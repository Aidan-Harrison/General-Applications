#include "Player.h"
#include <ctime>
#include "Setup.h"

using namespace PerkSetup;
using namespace WeaponSetup;

Player player;
void Interface();

void PrintStats() {
	std::cout << "\nPlayer name: " << player.name << '\n';
	std::cout << "Points: " << player.points << '\n';
	std::cout << "Perks:\n";
	for (unsigned int i = 0; i < player.perkInventory.size(); i++)
		std::cout << player.perkInventory[i].perkName << '\n';
	std::cout << "Weapons:\n";
	for (unsigned int i = 0; i < player.weaponInventory.size(); i++)
		std::cout << player.weaponInventory[i].wepName << '\n';
}

void RollPerk() {
	short input = 0;
	std::cout << "Pick a perk:\n";
	std::cout << "1) Juggernaut  2) Speed-Cola  3) Double-Tap";
	std::cin >> input;
	if (input == 1) {
		if (player.points >= 2500) {
			player.points -= 2500;
			player.perkInventory.push_back(Juggernaut);
		}
		else {
			std::cout << "You do not have enough points for Juggernaut!\n";
			std::cin.get();
			std::cin.get();
			Interface();
		}
	}
	else if(input == 2) {
		if (player.points >= 2000) {
			player.points -= 2000;
			player.perkInventory.push_back(DoubleTap);
		}
		else {
			std::cout << "You do not have enough points for Double-Tap!\n";
			std::cin.get();
			std::cin.get();
			Interface();
		}
	}
	else if(input == 3) {
		if (player.points >= 3000) {
			player.points -= 3000;
			player.perkInventory.push_back(SpeedCola);
		}
		else {
			std::cout << "You do not have enough points for Speed-Cola!\n";
			std::cin.get();
			std::cin.get();
			Interface();
		}
	}
	Interface();
}

void MysteryBox() {
	if (player.points >= 950) {
		player.points -= 950;
		srand(time(0));
		int weapon = 0;
		weapon = rand() % 3;
		switch (weapon) {
			case 1: player.weaponInventory.push_back(FiveSeven); break;
			case 2: player.weaponInventory.push_back(Olympus);   break;
			case 3: player.weaponInventory.push_back(RPK);       break;
		}
	}
	else {
		std::cout << "You don't have enough points!";
		std::cin.get();
		std::cin.get();
	}
	Interface();
}

void Interface() {
	system("cls");
	short input = 0;
	std::cout << "Zombie's System:\n";
	std::cout << "Pick an option | 1) Perk  2) Mystery Box  3) Print Stats"; 
	std::cin >> input;
	switch (input) {
	case 1: RollPerk();   break;
	case 2: MysteryBox(); break;
	case 3: PrintStats(); break;
	}
}

int main() {
	std::cout << "Enter a name: "; std::cin >> player.name;
	std::cout << "How many points would you like to start with? (Defaults to 500) "; std::cin >> player.points;
	Interface();
	return 0;
}