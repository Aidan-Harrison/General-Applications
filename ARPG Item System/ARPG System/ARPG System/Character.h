#ifndef Character_h
#define Character_h

#include <iostream>	
#include <vector>

#include "Item.h"
#include "CraftingItem.h"

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
	std::vector<CraftingItem> materialsStash{};
	Character(const std::string &name, int startingItemAmount)
		:m_Name(name) 
	{
		if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
			std::cerr << "Failed to load font!\n";
		nameGraphics.setFont(font);
		nameGraphics.setString(m_Name);
		nameGraphics.setOrigin(nameGraphics.getLocalBounds().width / 2, nameGraphics.getLocalBounds().height / 2);
		nameGraphics.setPosition(400.0f, 25.0f);
		itemStash = new std::vector<Item>[startingItemAmount];
	}

	Item* GetItem() const;

	std::string GetName() const { return m_Name; }

	void PrintStats(sf::RenderWindow &window) const;

	void GetItemStash() const;
	void GetCraftingStash() const;

	~Character() = default;
};

#endif