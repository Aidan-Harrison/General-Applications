#include "Player.h"
#include <ctime>

Player player;
void Interface();

void RollPerk() {
	short input = 0;
	std::cout << "Pick a perk:\n" <<
				 "1) Juggernaut  2) Speed - Cola  3) Double - Tap";
	std::cin >> input;
	if(input == 1 && player.points >= 2500)		 player.AddPerk(1);
	else if(input == 2 && player.points >= 2000) player.AddPerk(2);
	else if(input == 3 && player.points >= 3000) player.AddPerk(3);
	else if(input == 4 && player.points >= 3500) player.AddPerk(4);
	else std::cout << "You do not have enough points for "; // Add perk name
	std::cin.get();
	Interface();
}

void MysteryBox() {
	if (player.points >= 950 && player.weaponInventory.size() != player.maxWeapons) {
		player.points -= 950;
		srand(time(0));
		int weapon = 0;
		weapon = rand() % 3;
		switch (weapon) {
			case 1: player.AddWeapon(1); break;
			case 2: player.AddWeapon(2); break;
			case 3: player.AddWeapon(3); break;
		}
	}
	else std::cout << "You don't have enough points or you are already at max weapons!";
	std::cin.get();
	Interface();
}

void Interface() {
	system("cls");
	short input = 0;
	std::cout << "Zombie's System:\n" <<
				 "Pick an option | 1) Perk  2) Mystery Box  3) Print Stats"; 
	std::cin >> input;
	switch (input) {
		case 1: RollPerk();   break;
		case 2: MysteryBox(); break;
		case 3: player.PrintStats(); break;
	}
}

int main() {
	std::cout << "How many points would you like to start with? (Defaults to 500) "; std::cin >> player.points;
	Interface();
	return 0;
}