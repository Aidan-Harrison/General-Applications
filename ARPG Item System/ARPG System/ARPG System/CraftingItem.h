#ifndef CraftingItem_h
#define CraftingItem_h

#include <iostream>
#include "Item.h"

class CraftingItem {
private:
	sf::Font font;
public:
	sf::Text nameText;
	sf::Texture tex;
	sf::RectangleShape debugTex;
	sf::Sprite spr;

	std::string itemName = "Default";
	const std::string itemDescription = "";
	CraftingItem(const std::string &filePath, const std::string &name)  // Fix! Texture having internal OpenGL errors!!!! Write custom handler?
	{
		itemName = name;
		if(!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
			std::cerr << "Failed to load font for crafting item!\n";

		nameText.setFont(font);
		nameText.setString(name);
		nameText.setOrigin(nameText.getLocalBounds().width/2, nameText.getLocalBounds().height/2);

		if (!tex.loadFromFile(filePath)) // Do image selection
			std::cerr << "Failed to load item image!\n";

		spr.setTexture(tex);
		spr.setScale(0.2f, 0.2f);
		spr.setOrigin(spr.getLocalBounds().width/2, spr.getLocalBounds().height/2);

		debugTex.setFillColor(sf::Color::Red);
		debugTex.setSize(sf::Vector2f(50.0f, 50.0f));
		debugTex.setOrigin(debugTex.getSize().x, debugTex.getSize().y);
	}
	~CraftingItem() = default;

	virtual void Use(Item &i, int thresholds[4], int choice) {}
	virtual void Draw(sf::RenderWindow& window) const;

	float GetPosX() { return spr.getPosition().x; }
	float GetPosY() { return spr.getPosition().y; }

	void SetPos(float x, float y);
};

class AgonyOrb : public CraftingItem { // Totally randomises an item
private:
public:
	AgonyOrb(const std::string &filePath)
		:CraftingItem(filePath, "Agony Orb")
	{
	}
	~AgonyOrb() = default;
	void Use(Item& i, int thresholds[4], int choice);
	void Draw(sf::RenderWindow &window, float offset); // Check const?
};

class PerfectionOrb : public CraftingItem { // Upgrades an item by one tier
private:
public:
	PerfectionOrb(const std::string& filePath) 
		:CraftingItem(filePath, "Perfection Orb")
	{
	}
	~PerfectionOrb() = default;
	void Use(Item& i, int thresholds[4], int choice);
	void Draw(sf::RenderWindow& window, float offset);
};

class LamentGem : public CraftingItem { // Upgrades an item by one tier
private:
public:
	LamentGem(const std::string& filePath)
		:CraftingItem(filePath, "Lament Gem")
	{
	}
	~LamentGem() = default;
	void Use(Item& i, int thresholds[4], int choice);
	void Draw(sf::RenderWindow& window, float offset);
};

#endif