#ifndef CraftingItem_h
#define CraftingItem_h

#include <iostream>
#include "Item.h"

void RollItem();

class CraftingItem {
private:
	sf::Text nameText; // Have show on hover
	sf::Font font;
public:
	sf::Texture tex;
	sf::Sprite spr;
	const std::string itemName = "Default";
	const std::string itemDescription = "";
	CraftingItem(const std::string &filePath)  // Fix! Texture having internal OpenGL errors!!!! Write custom handler?
	{
		nameText.setFont(font);
		nameText.setString(itemName);
	}
	~CraftingItem() = default;

	virtual void Use(Item *i) {}
	virtual void Draw(sf::RenderWindow &window, float offset) const {}

	float GetPosX() { return spr.getPosition().x; }
	float GetPosY() { return spr.getPosition().y; }
};

// Swap for references???
class AgonyOrb : public CraftingItem { // Totally randomises an item
private:
public:
	AgonyOrb(const std::string &filePath)
		:CraftingItem(filePath)
	{
	}
	~AgonyOrb() = default;
	void Use(Item *i);
	void Draw(sf::RenderWindow &window, float offset); // Check const?
};

class PerfectionOrb : public CraftingItem { // Upgrades an item by one tier
private:
public:
	PerfectionOrb(const std::string& filePath) 
		:CraftingItem(filePath)
	{
	}
	~PerfectionOrb() = default;
	void Use(Item *i);
	void Draw(sf::RenderWindow& window, float offset);
};

class LamentGem : public CraftingItem { // Upgrades an item by one tier
private:
public:
	LamentGem(const std::string& filePath) 
		:CraftingItem(filePath)
	{
	}
	~LamentGem() = default;
	void Use(Item* i);
	void Draw(sf::RenderWindow& window, float offset);
};

#endif