#include "Player.h"
using namespace PerkSetup;
using namespace WeaponSetup;
using namespace GumSetup;

void Interface();

void Player::AddPerk(short perk) {
	switch(perk) {
		case 1: perkInventory.push_back(QuickRevive); break;
		case 2: perkInventory.push_back(Juggernaut);  break;
		case 3: perkInventory.push_back(DoubleTap);   break;
		case 4: perkInventory.push_back(SpeedCola);   break;
		case 5: perkInventory.push_back(MuleKick);    break;
		case 6: perkInventory.push_back(WidowsWine);  break;
		case 7: perkInventory.push_back(StaminaUp);   break;
	}
}
void Player::AddWeapon(short weapon) {
	switch(weapon) {
		case 0: weaponInventory.push_back(FiveSeven);  break;
		case 1: weaponInventory.push_back(Olympus);    break;
		case 2: weaponInventory.push_back(RPK);		   break;
		case 3: weaponInventory.push_back(Raygun);     break;
		case 4: weaponInventory.push_back(Thundergun); break;
	}
}
void Player::AddGum(short gum) {
	switch(gum) {
		case 0: gumInventory.push_back(PerkAHolic);    break;
		case 1: gumInventory.push_back(FastHands);     break;
		case 2: gumInventory.push_back(AvoidZombies);  break;
	}
}
void Player::PrintStats() {
	std::cout << "Points: " << points;
	std::cout << "\nStats:\n";
	std::cout << "Health: " << m_Health << " | Damage: " << m_Damage << " | Reload Speed: " << m_ReloadSpeed << " | Stamina: " << m_Stamina;
	std::cout << "\nPerks:\n";
	for(unsigned int i = 0; i < perkInventory.size(); i++)
		std::cout << perkInventory[i].perkName << " | " <<
				     perkInventory[i].m_Cost   << " | " <<
					 perkInventory[i].hasUniqueProp << '\n';
	std::cout << "Weapons:\n";
	for(unsigned int i = 0; i < weaponInventory.size(); i++) {
		std::cout << weaponInventory[i].wepName << " | " <<
					 weaponInventory[i].m_Damage << '|' <<
					 weaponInventory[i].m_Ammo   << '|' <<
					 weaponInventory[i].m_Range  << '|' <<
					 weaponInventory[i].m_Weight << '|' <<
				     weaponInventory[i].isWonder << "|\n";
	}
	std::cout << "Gums:\n";
	for (unsigned int i = 0; i < gumInventory.size(); i++) {
		std::cout << gumInventory[i].m_Name << " | " <<
			gumInventory[i].m_Rarity << '|' <<
			gumInventory[i].rarityName;
	}
	std::cin.get();
	std::cin.get();
	Interface();
}
void Player::DeletePlayer(Player *p) {
	delete p;
}