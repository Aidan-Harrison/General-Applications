#include "Hero.h"

void Hero::PrintStats() const { // Check const!
	std::cout << "\nName: " << m_Name
		<< "\nHealth: " << std::string(m_Health / 10, '|') << " : " << m_Health
		<< "\nMana: " << std::string(m_Mana / 10, '|') << " : " << m_Mana
		<< "\nDamage: " << m_Damage
		<< "\nMoveSpeed: " << m_MoveSpeed
		<< "\nGold: " << gold;
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
	std::cout << "\nInventory:\n\t";
	for(unsigned int i = 0; i < 6; i++) std::cout << m_Inventory[i].GetName() << ", ";
	std::cout << "Backpack:\n\t";
	for(unsigned int i = 7; i < 9; i++) std::cout << m_Inventory[i].GetName() << ", ";
}

void Hero::PrintStash() const {
	for(unsigned int i = 0; i < 8; i++) std::cout << m_Stash[i].GetName() << '\n';
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

void Hero::ChangeHealth(const short damage, const char type) {
	if(type == 'p')
		m_Health -= damage / m_Armor;
	if(type == 'm')
		m_Health -= damage / m_MagicRes;
	if (m_Health == 0) {
		std::cout << "You are dead!";
		m_Dead = true;
		gold -= 250; // Apply scaling
		RespawnTime(); // Keep in same function?
	}
}

void Hero::RespawnTime() {
	// Do respawn on seperate thread!?
	respawnTime *= level; // Scale by game time instead?
	while(m_Dead) {
		std::this_thread::sleep_for(std::chrono::seconds(1));
		respawnTime -= 1;
		std::cout << "Respawn: " << respawnTime;
		if (respawnTime == 0)
			m_Dead = false;
	}
	// Reset respawn time to correct values
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

Item Hero::CalcItem(Item &item) {
	m_Strength += item.GetStrength();
	m_Agility += item.GetAgility();
	m_Intelligence += item.GetIntelligence();
	m_Damage += item.GetDamage();
	return item; // Do return? Probably not needed?
}

void Hero::UseItem(Item &item) { // Only pass in useable items
	if(!item.m_isActive) {
		std::cout << "Item does not have an active!\n";
		return; // Go back to game
	}
	else {
		
	}
}

// Riki

// Nightstalker
