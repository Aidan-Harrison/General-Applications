#include "Player.h"
using namespace PerkSetup;
using namespace WeaponSetup;

void Player::AddPerk(short perk) {
	switch(perk) {
		case 1: perkInventory.push_back(Juggernaut); break;
		case 2: perkInventory.push_back(DoubleTap);  break;
		case 3: perkInventory.push_back(SpeedCola);  break;
		case 4: perkInventory.push_back(MuleKick);   break;
	}
}
void Player::AddWeapon(short weapon) {
	switch(weapon) {
		case 1: weaponInventory.push_back(FiveSeven); break;
		case 2: weaponInventory.push_back(Olympus);   break;
		case 3: weaponInventory.push_back(RPK);		  break;
	}
}
void Player::PrintStats() {
	std::cout << "Points: " << points << '\n';
	std::cout << "Perks:\n";
	for (unsigned int i = 0; i < perkInventory.size(); i++)
		std::cout << perkInventory[i].perkName << '\n';
	std::cout << "Weapons:\n";
	for (unsigned int i = 0; i < weaponInventory.size(); i++)
		std::cout << weaponInventory[i].wepName << '\n';
}