#ifndef Character_h
#define Character_h

#include <iostream>	
#include <vector>
#include <unordered_map>

#include "Item.h"
#include "CraftingItem.h"

#include <SFML/Graphics.hpp>

template<typename T> 
class Character {
private:
	std::string m_Name = "";
	sf::Text nameGraphics;
	sf::Font font;
public:
	// Stats
	int health = 100, mana = 100;
	int STR = 0, DEX = 0, INT = 0;
	float attackSpeed = 1.0f;
	float moveSpeed = 10.0f;
	int physRes = 0, fireRes = 0, coldRes = 0, lightningRes = 0, chaosRes = 0, poisonRes = 0;

	std::vector<T> stats{};
	std::vector<sf::Text> statsText{};

	float xOffset = 150.0f;
	float yOffset = 500.0f;
	std::vector<Item*> itemStash{}; // Check!
	std::unordered_map<int, Item> itemStashMap;
	std::vector<CraftingItem> materialsStash{}; // Change to pointer, solve function call
	Character(const std::string& name, int startingItemAmount)
		:m_Name(name)
	{
		if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
			std::cerr << "Failed to load font!\n";
		nameGraphics.setFont(font);
		nameGraphics.setString(m_Name);
		nameGraphics.setOrigin(nameGraphics.getLocalBounds().width / 2, nameGraphics.getLocalBounds().height / 2);
		nameGraphics.setPosition(400.0f, 15.0f);

		itemStash.resize(startingItemAmount);

		// Probably don't need to heap allocate
		AgonyOrb aO("Images/Moyai.png");
		PerfectionOrb pO("Images/Moyai.png");
		LamentGem lG("Images/Moyai.png");
		materialsStash.push_back(aO);
		materialsStash.push_back(pO);
		materialsStash.push_back(lG);

		for (unsigned int i = 0; i < materialsStash.size(); i++) {
			materialsStash[i].SetPos(xOffset, yOffset);
			xOffset += 100.0f;
			if (xOffset == 200.0f) {
				xOffset = 150.0f;
				yOffset += 50.0f;
			}
		}
	}

	// Item* GetItem() const; // Check!

	void SetStats();

	std::string GetName() const { return m_Name; }

	void SetInventory();

	void PrintStats(sf::RenderWindow &window) const;
	void PrintItemStash(sf::RenderWindow &window) const;
	void PrintMatStash(sf::RenderWindow &window) const;

	void SortInventory();

	void GetItemStash() const;

	void SearchItemStash(std::string &search); // const?

	~Character() = default;
};

#endif