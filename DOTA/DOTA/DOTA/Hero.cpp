#include "Hero.h"

void Hero::PrintStats() const {
	std::cout << "\nName: " << m_Name << '\n'
		<< "Health: " << m_Health << '\n'
		<< "Mana: " << m_Mana << '\n'
		<< "Damage: " << m_Damage << '\n'
		<< "MoveSpeed: " << m_MoveSpeed << '\n'
		<< "Team: " << team << '\n'; // Conver to string
}

void Hero::PrintAbilities() const {
	std::cout << "Abilities:\n";
	for(unsigned int i = 0; i < abilities.size(); i++) {
		std::cout << "Ability name: " << abilities[i].m_AbilityName << '\n';
		std::cout << "Ability cooldown: " << abilities[i].m_Cooldown << '\n';
		std::cout << "Description:===========" << abilities[i].m_Description << '\n' << "===========";
	}
}

void Hero::PrintInventory() const {
	std::cout << "Inventory:\n";
	for(unsigned int i = 0; i < 6; i++) std::cout << m_Inventory[i].m_ItemName << ", ";
	std::cout << "Backpack:\n";
	for(unsigned int i = 0; i < 3; i++) std::cout << m_Backpack[i].m_ItemName << ", ";
}

void Hero::PrintStash() const {
	for(unsigned int i = 0; i < 8; i++) std::cout << m_Stash[i].m_ItemName << '\n';
}

void Hero::PrintAll() const {
	putchar('\n');
	PrintStats();
	putchar('\n');
	PrintAbilities();
	putchar('\n');
	PrintInventory();
	putchar('\n');
	PrintStash();
}

void Hero::AddAbilities(std::vector<Ability> &abiList) { // Do move semantics
	for(unsigned int i = 0; i < abilities.size(); i++)
		abilities.push_back(abiList[i]);
}

// Probably not the best method, seperate functions per hero????
int Hero::UseAbility(const char key) { // Returns damage, if any, other effects are calculated within function and based on the entitiy being attacked | Check return!
	std::tolower(key); // Check!
	if(key == 'q') {
		if(!abilities[0].passive) { // Possibly optimise to one check?
			abilities[0].used = true;
		}
		else {std::cout << "This ability is passive (Cannot be activated!)\n"; return 0;}
	}
	else if(key == 'w') {
		if(!abilities[1].passive) {
			abilities[1].used = true;
		}
		else {std::cout << "This ability is passive (Cannot be activated!)\n"; return 0;}
	}
	else if(key == 'e') {
		if(!abilities[2].passive) {
			abilities[2].used = true;
		}
		else {std::cout << "This ability is passive (Cannot be activated!)\n"; return 0;}
	}
	else if(key == 'r') {
		if(!abilities[3].passive) {
			abilities[3].used = true;
		}
		else {std::cout << "This ability is passive (Cannot be activated!)\n"; return 0;}
	}
	else {
		std::cout << "You have entered an invalid key!: Must be Q, W, E or R\n";
		return 0.0f; // Check!
	}
	return 0; // Control path (Change?)
}

short Hero::AutoAttack() { // Add chances/items! | Returns damage
	m_AttackChance = rand() % 5; // Convert to rand singleton | Change size of range with items
	if (m_AttackChance > 1) {
		return m_Damage;
		std::cout << "You dealt"; // ?
	}
	else {
		std::cout << "Miss!\n";
		return 0;
	}
	return 0;
	// Do, take into account everything else
}

void Hero::UseItem(Item &item) { // Only pass in useable items
	if(!item.m_isActive) {
		std::cout << "Item cannot is not active!\n";
		return; // Go back to game
	}
	else {
	}
}