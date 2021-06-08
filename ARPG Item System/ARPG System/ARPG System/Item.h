#ifndef Item_h
#define Item_h

#include <iostream>
#include <array>

#include <SFML/Graphics.hpp>

class Item { // Contains global modifiers | ALL items can inherit
private:
	std::string itemName = "";
	sf::Text itemText;
	std::array<sf::Text, 5> statText;
	sf::Font font; // Possibly different fonts for title and stats
	sf::Image img;
public:	
	std::string itemDescription = "";
	float offset = 0.0f;
	// Stats: Implicit

	// Stats: Prefix
	int typeValue = 0; // STRENGTH, AGILITY, INTELLIGENCE | Can have multiple
	int fireResistance = 0; // Percent based
	int coldResistance = 0;
	int lightningResistance = 0;

	// Stats: Suffix

	enum TYPE{SWORD = 0, BOW, SHIELD, BOOTS, CHEST, RING, AMULET};
	enum RARITIES{NORMAL = 0, MAGIC, RARE, UNIQUE};
	int rarity = 0;
	int type = 0;
	std::array<int, 5> stats;
	Item(const std::string &name)
		:itemName(name) 
	{
		if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
			std::cerr << "Failed to load font!\n";
		itemText.setFont(font);
		itemText.setString(itemName);
		itemText.setOrigin(itemText.getLocalBounds().width / 2, itemText.getLocalBounds().height / 2);
		itemText.setPosition(600.0f, 100.0f);

		// Stat setup
		for (unsigned int i = 0; i < statText.size(); i++) {
			statText[i].setFont(font);
			statText[i].setOrigin(itemText.getLocalBounds().width / 2, itemText.getLocalBounds().height / 2);
			statText[i].setPosition(600.0f, 125.0f + offset);
			statText[i].setString(std::to_string(stats[i]));
			offset += 25.0f;
		}
	}
	~Item() = default;

	void PrintItem(sf::RenderWindow &window) const; // Prints everything about the item in an ordered format | SFML based
};

class Sword : public Item {
private:
public:
	Sword(const std::string &name)
		:Item(name)
	{
	}
	int damageModifier = 0; // Percent based
	int attackSpeedModifier = 0;
	int critMulti = 0;
	int critChance = 0;
	int fireDamage = 0;
	int coldDamage = 0;
	int lightningDamage = 0;

	void GenerateStats();
};

class Boots : public Item {
private:
public:
	Boots(const std::string& name)
		:Item(name)
	{
	}
	int moveSpeedModifier = 0; // Percent based
};

class Ring : public Item {
private:
public:
	Ring(const std::string& name)
		:Item(name)
	{
	}
};

class Amulet : public Item {
private:
public:
};

class Chest : public Item {
private:
public:
};

#endif