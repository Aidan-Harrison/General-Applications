#ifndef Ally_h
#define Ally_h

#include <array>
#include <vector>
#include <string>
#include <cassert>
#include <tuple>

#include <SFML/Graphics.hpp>

#include "Item.h"
#include "Enemy.h"

class Spell {
private:
public:
	bool isDamage = false; // If true, can only be applied to enemies
	short m_ManaCost = 50;
	int type = 0;
	enum type{ NEUTRAL, FIRE, WATER, ICE, EARTH };
	Spell(const bool damage = false, const short manaCost = 50, const short type = 1)
		:m_ManaCost(manaCost), type(type) // REDO TYPE
	{
		// assert(manaCost != 0 && type < 5);
	}
	~Spell() = default;
	virtual void Use() {}
};

class Ally {
private:
	sf::RectangleShape body; // Change to sprite once images added!!!
	// Add graphics to constructor, let user chose appearance
	sf::Text healthValue;
	sf::Text manaValue;
	sf::RectangleShape healthBar;
	sf::RectangleShape manaBar;
public:
	std::string m_Name = "";
	std::string m_Description = "";
	short m_Health = 500;
	short m_Mana = 250;
	short m_Damage = 100;
	bool isDead = false;
	std::array<Item, 5> inventory;
	std::array<Spell, 3> spells;
	Ally(const std::string &name = "Member", const short baseHealth = 500, const short baseMana = 250)
		:m_Name(name), m_Health(baseHealth), m_Mana(baseMana)
	{
		body.setSize(sf::Vector2f(25.0f, 25.0f));
		body.setFillColor(sf::Color::Green);

		assert(m_Name != " " && m_Health > 100 && m_Mana > 100);
		// Generic (Applies to all objects, cannot be altered)
		healthBar.setFillColor(sf::Color::Blue);
		manaBar.setFillColor(sf::Color::Magenta);

		healthValue.setString(std::to_string(m_Health));
		manaValue.setString(std::to_string(m_Mana));
	}
	~Ally() = default;

	void Move(std::array<Enemy, 5> &e, sf::RenderWindow &window, sf::Event &event); // Handles below 3 functions

	void Attack(std::array<Enemy, 5> &enemies, sf::RenderWindow &window);
	void Spell(std::array<Enemy, 5> &enemies);
	void UseItem();

	void TakeDamage(const short damage, sf::RenderWindow &window); // Bool?

	void Draw(sf::RenderWindow &window);

	void SetPosition(float x, float y); // Possibly remove!?
};

// Spells
// Support spells
class Heal : public Spell {
private:
public:
	short amountToHeal = 200;
	bool isDamage = false;
	Heal(const bool isDamage, const short manaCost = 50, const short type = 0)
		:Spell(manaCost, type)
	{
	}
	~Heal() = default;
	void Use(std::array<Ally, 2> &allies, std::array<Enemy, 5>& enemies);
};

class Armor : public Spell {
private:
public:
	bool isDamage = false;
	short turnsToShield = 2;
	short damageReduction = 30; // Percent based
	Armor(const bool isDamage, const short manaCost, const short type)
		:Spell(isDamage, manaCost, type)
	{
	}
	void Use(std::array<Ally, 2> &allies, std::array<Enemy, 5>& enemies);
};

class Cleanse : public Spell {
private:
public:
	Cleanse(const bool isDamage, const short manaCost, const short type)
		:Spell(isDamage, manaCost, type)
	{
	}
	void Use(std::array<Ally, 2> &allies, std::array<Enemy, 5>& enemies);
};

// DamageSpells
class Fireball : public Spell {
private:
public:
	short damageToDeal = 200;
	Fireball(const bool isDamage, const short manaCost, const short type)
		:Spell(isDamage, manaCost, type)
	{
	}
	void Use(std::array<Ally, 2>& allies, std::array<Enemy, 5>& enemies);
};

class Explosion : public Spell {
private:
public:
	short damageToDeal = 300;
	Explosion(const bool isDamage, const short manaCost, const short type)
		:Spell(isDamage, manaCost, type)
	{
	}
	void Use(std::array<Ally, 2>& allies, std::array<Enemy, 5>& enemies);
};

class Blizzard : public Spell {
private:
public:
	short turnsToSlow = 2;
	Blizzard(const bool isDamage, const short manaCost, const short type)
		:Spell(isDamage, manaCost, type)
	{
	}
	void Use(std::array<Ally, 2>& allies, std::array<Enemy, 5>& enemies);
};


#endif