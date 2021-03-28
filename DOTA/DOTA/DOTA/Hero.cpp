#include "Hero.h"

void Hero::PrintStats() const {
	std::cout << "\nName: " << m_Name << '\n'
		<< "Health: " << m_Health << '\n'
		<< "Mana: " << m_Mana << '\n'
		<< "Damage: " << m_Damage << '\n'
		<< "MoveSpeed: " << m_MoveSpeed << '\n';
}

void Hero::PrintAbilities() const {
	std::cout << "Abilities:\n";
	for (unsigned int i = 0; i < abilities.size(); i++) {
		std::cout << "Ability name: " << abilities[i].m_AbilityName << '\n';
		std::cout << "Ability cooldown: " << abilities[i].m_Cooldown << '\n';
		std::cout << "Description:===========" << abilities[i].m_Description << '\n' << "===========";
	}
}

void Hero::PrintInventory() const {
	std::cout << "Inventory:\n";
	for (unsigned int i = 0; i < 6; i++)
		std::cout << m_Inventory[i].m_ItemName << ", ";
	std::cout << "Backpack:\n";
	for (unsigned int i = 0; i < 3; i++)
		std::cout << m_Backpack[i].m_ItemName << ", ";
}