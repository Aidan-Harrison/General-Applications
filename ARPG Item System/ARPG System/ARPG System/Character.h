#ifndef Character_h
#define Character_h

#include <iostream>	
#include <vector>

#include "Item.h"
#include "CraftingItem.h"

#include <SFML/Graphics.hpp>

class Character {
private:
	std::string m_Name = "";
	sf::Text nameGraphics;
	sf::Font font;
public:
	int m_Strength = 0, m_Agility = 0, m_Intelligence = 0;
	float attackSpeed = 1.0f;
	float moveSpeed = 10.0f;
	std::vector<Item> *itemStash{}; // Check!
	std::vector<CraftingItem> materialsStash{}; // Change to pointer, solve function call
	Character(const std::string &name, int startingItemAmount)
		:m_Name(name) 
	{
		if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
			std::cerr << "Failed to load font!\n";
		nameGraphics.setFont(font);
		nameGraphics.setString(m_Name);
		nameGraphics.setOrigin(nameGraphics.getLocalBounds().width / 2, nameGraphics.getLocalBounds().height / 2);
		nameGraphics.setPosition(400.0f, 15.0f);

		itemStash = new std::vector<Item>[startingItemAmount];

		// Probably don't need to heap allocate
		AgonyOrb aO("Images/Moyai.png");
		PerfectionOrb pO("Images/Moyai.png");
		LamentGem lG("Images/Moyai.png");
		// Use vector.insert instead??? | Below method seems far too ineffcient
		materialsStash.push_back(aO);
		materialsStash.push_back(pO);
		materialsStash.push_back(lG);
	}

	Item* GetItem() const;

	std::string GetName() const { return m_Name; }

	void PrintStats(sf::RenderWindow &window) const;

	void GetItemStash() const;
	void GetCraftingStash(sf::RenderWindow &window) const;

	~Character() = default;
};

#endif