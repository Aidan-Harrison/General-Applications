#ifndef Hero_h
#define Hero_h

#include <iostream>
#include <cassert>
#include <vector>
#include "Item.h"

struct Ability {
	std::string m_AbilityName = "", m_Description = "";
	float m_Cooldown = 0.0f;
	bool used = false, passive = false; // Passive abilites have zero cost
	int m_Index = 1; // References key (Q, W, E, R)
	short manaCost = 0;
	Ability() = default;
	Ability(const char* name, short cost, const bool isPassive)
		:m_AbilityName(name), manaCost(cost), passive(isPassive)
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
	// Add
public:
	enum Abilities {Q = 1, W, E, R};
	enum Type {STRENGTH, AGILITY, INTELLIGENCE};
	enum Team {RADIANT, DIRE}; // Check need!
	short m_Health = 450, m_Mana = 200, m_Damage = 50, m_MoveSpeed = 250, m_AttackRange = 300;
	bool m_Dead = false, m_Invis = false, m_HasAghs = false;
	const std::string m_Name = " ";
	int type = 0, gold = 500, team = 0; // Defaults to strength
	std::vector<Ability> abilities = {};
	Item m_Inventory[6]; // Possibly combine with backpack!? Const?
	Item m_Backpack[3];
	Hero() = default;
	Hero(const char* name, short health, short mana, short damage, short moveSpeed, short attackRange) // Do type!
		:m_Name(name), m_Health(health), m_Mana(mana), m_Damage(damage), m_MoveSpeed(moveSpeed), m_AttackRange(attackRange)
	{
		assert(m_Name != " " && m_Health != 0 && m_Mana != 0 && m_Damage != 0 && m_MoveSpeed != 0);
	}
	~Hero() = default;
	inline std::string GetName() const { return m_Name; } // Check need for inline!?
	void PrintStats() const;
	void PrintAbilities() const;
	void PrintInventory() const;
	int GetTeam() const { return team; } // Check, use enum!
};


class Riki : Hero { // Check initialiation!?
private:
public:
};

class Nightstalker : Hero {
private:
public:
};

#endif Hero_h