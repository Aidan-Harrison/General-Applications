#ifndef Hero_h
#define Hero_h

#include <iostream>
#include <cassert>
#include <thread>
#include <vector>
#include <cctype>
#include <array>
#include "Item.h"

#include <SFML/Graphics.hpp>
// This file is becoming hard to read, clean up at a later date

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
	// Add Vector wrapper (Constrains vector size to given amount) | Re-do | Use resize()
	const short inventSize = 6, backSize = 3;
	void VectorWrap(int maxSize, char type) { // Do!
		switch(type) {
			case 'i': maxSize = inventSize;
			case 'b': maxSize = backSize;
		}
	}
	const std::string m_Name = " ";
	short m_Armor = 3, m_MagicRes = 3;
	short m_Strength = 10, m_Agility = 10, m_Intelligence = 10;
	short kills = 0, deaths = 0, assists = 0;
	// SFML
	sf::RectangleShape body; // Replace with sprites
	sf::Text hoverText; // Hovers above sprite at all times
public:
	short id = 1;
	enum Abilities {Q = 1, W, E, R};
	enum Type {STRENGTH, AGILITY, INTELLIGENCE};
	enum Team {RADIANT, DIRE}; // Check need! | Check against player team!
	short m_Health = 450, m_Mana = 200, m_Damage = 50, m_MoveSpeed = 250, m_AttackRange = 300; // Main stats
	short m_AttackChance = 0, m_StunDuration = 0; // Sub properties | Stun duration referes to the amount of game ticks
	short m_HealthRegen = 2.5, m_ManaRegen = 1.5;
	bool m_Dead = false, m_Invis = false, m_HasAghs = false, m_isStunned = false, m_SpellImune = false;
	bool isBanned = false;
	int type = 0, gold = 500, team = 0, level = 1, experience = 0, respawnTime = 20; // Type defaults to strength | Have respawn time scale
	std::vector<Ability> abilities = {};
	std::array<Item, 9> m_Inventory{};
	std::array<Item, 8> m_Stash{};
	Hero() = default;
	// Defaults to Axe
	Hero(const char* name = "Axe", short health = 500, short mana = 250, short damage = 60, short moveSpeed = 250, short attackRange= 500, int type = 0) // Check type!
		:m_Name(name), m_Health(health), m_Mana(mana), m_Damage(damage), m_MoveSpeed(moveSpeed), m_AttackRange(attackRange), type(type)
	{
		assert(m_Name != " " && m_Health != 0 && m_Mana != 0 && m_Damage != 0 && m_MoveSpeed != 0);

		body.setSize(sf::Vector2f(25.0f, 25.0f));
		body.setOrigin(12.5f, 12.5f);
		body.setFillColor(sf::Color::Red);

		hoverText.setString(m_Name);
	}
	~Hero() = default;
	// Main (Gameplay)
	void AddAbilities(std::vector<Ability> &abilList); // ??
	int UseAbility(const char key);
	short AutoAttack(); // Universal, also takes into account items
	void UseItem(Item &item);
	void ChangeHealth(const short damage, const char type);
	Item CalcItem(Item &item); // Calculates item statistics | Change return?
	// General
	inline std::string GetName() const { return m_Name; }
	inline int GetTeam() const { return team; } // Check, use enum!?
	inline short GetHealth() const { return m_Health; }
	inline short GetMana() const { return m_Mana; }
	inline short GetArmor() const { return m_Armor; }
	inline short GetMagicRes() const { return m_MagicRes; }
	int GetType() const { return type; }
	void RespawnTime(); // Runs on seperate thread | Change to 'Respawn'?
	inline void BanHero() { delete this; }
	// Printing
	void PrintStats() const;
	void PrintAbilities() const;
	void PrintInventory() const;
	void PrintStash() const;
	void PrintKDA() const;
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
	void CheckTime(); // Check!
};

#endif