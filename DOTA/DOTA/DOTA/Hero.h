#ifndef Hero_h
#define Hero_h

#include <iostream>
#include <cassert>
#include <vector>
#include <cctype>
#include "Item.h"

struct Ability {
	const std::string m_AbilityName = "", m_Description = "";
	float m_Cooldown = 0.0f;
	bool used = false, passive = false; // Passive abilites have zero cost
	int m_Index = 1, m_AbiLevel = 1; // References key (Q, W, E, R)
	short manaCost = 0;
	Ability() = default;
	Ability(const char* name, short cost, short cooldown, const bool isPassive)
		:m_AbilityName(name), manaCost(cost), m_Cooldown(cooldown), passive(isPassive)
	{
		assert(m_AbilityName != " "); // Cost can be zero
	}
	~Ability() = default;
	std::string GetName() const { return m_AbilityName; }
	float GetCooldown() const { return m_Cooldown; }
	std::string GetDescription() const { return m_Description; }
};

class Hero {
private:
	// Add Vector wrapper (Constrains vector size to given amount)
	const short inventSize = 6, backSize = 3;
	void VectorWrap(int maxSize, char type) { // Do!
		switch(type) {
			case 'i': maxSize = inventSize;
			case 'b': maxSize = backSize;
		}
	}
public:
	enum Abilities {Q = 1, W, E, R};
	enum Type {STRENGTH, AGILITY, INTELLIGENCE};
	enum Team {RADIANT, DIRE}; // Check need! | Check against player team!
	short m_Health = 450, m_Mana = 200, m_Damage = 50, m_MoveSpeed = 250, m_AttackRange = 300; // Main stats
	short m_AttackChance = 0, m_StunDuration = 0; // Sub properties | Stun duration referes to the amount of game ticks
	bool m_Dead = false, m_Invis = false, m_HasAghs = false, m_isStunned = false;
	const std::string m_Name = " ";
	int type = 0, gold = 500, team = 0, level = 1, experience = 0, respawnTime = 20; // Type defaults to strength | Have respawn time scale
	std::vector<Ability> abilities = {};
	Item m_Inventory[6]; // Possibly combine with backpack!? Const? Only need one?
	Item m_Backpack[3];
	Item m_Stash[8];
	Hero() = default;
	// Defaults to Axe
	Hero(const char* name = "Axe", short health = 500, short mana = 250, short damage = 60, short moveSpeed = 250, short attackRange= 500, int type = 0) // Check type!
		:m_Name(name), m_Health(health), m_Mana(mana), m_Damage(damage), m_MoveSpeed(moveSpeed), m_AttackRange(attackRange), type(type)
	{
		assert(m_Name != " " && m_Health != 0 && m_Mana != 0 && m_Damage != 0 && m_MoveSpeed != 0);
	}
	~Hero() = default;
	// Main
	void AddAbilities(std::vector<Ability> &abilList); // ??
	int UseAbility(const char key);
	short AutoAttack(); // Universal, also takes into account items
	void UseItem(Item &item);
	// General
	inline std::string GetName() const { return m_Name; } // Check need for inline!?
	inline int GetTeam() const { return team; } // Check, use enum!
	inline short GetHealth() const { return m_Health; }
	inline short GetMana() const { return m_Mana; }
	int GetType() const { return type; }
	// Printing
	void PrintStats() const;
	void PrintAbilities() const;
	void PrintInventory() const;
	void PrintStash() const;
	void PrintAll() const;
};


class Riki : public Hero { // Check initialiation!?
private:
public:
};

class Nightstalker : public Hero {
private:
public:
	bool isEmpowered = false;
};

#endif