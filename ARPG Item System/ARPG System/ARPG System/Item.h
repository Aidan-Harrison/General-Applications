#ifndef Item_h
#define Item_h

#include <iostream>
#include <array>
#include <tuple>
#include <vector>

#include <SFML/Graphics.hpp>

class Item {
private:
	std::array<std::string, 5> a_Name{" ", " ", " ", " ", " "}; // PREFIX - BASE - SUFFIX
	sf::Text itemText;

	sf::Font font; // Possibly different fonts for title and stats
	sf::Texture tex;
	sf::Sprite img;
public:	
	sf::RectangleShape itemPrevBack;
	sf::RectangleShape GREY_OUT;
	sf::Sprite itemPreview;

	std::string itemName;
	sf::RectangleShape rarityVisual;
	sf::Text rarityText;
	enum RARITIES{NORMAL = 0, MAGIC, RARE, UNIQUE, EXALTED, BOSS};
	int rarity = 0;

	enum TYPE{SWORD = 0, BOW, SHIELD, BOOTS, CHEST, RING, AMULET, BELT};
	int type = 0;

	int iLevel = 1;
	bool stashSet = false;
	// Stats: Fundamental
	std::tuple<int, int, int> typeValue{0, 0, 0}; // STRENGTH, AGILITY, INTELLIGENCE | Scales with iLevel
	std::tuple<int, int, int> requirements{0, 0, 0}; // STRENGTH, AGILITY, INTELLIGENCE | Scales with iLevel

	// Stats: Implicit
	std::array<int, 2> implicitValues{0,0};
	std::array<std::string, 2> implicitMods{"",""};
	std::array<int, 2> implicitTiers{0,0}; // 5 - 1
	// Stats: Prefix
	std::array<int, 2> prefixValues{0,0};
	std::array<std::string, 2> prefixMods{"",""};
	std::array<int, 2> prefixTiers{0,0};
	// Stats: Suffix
	std::array<int, 3> suffixValues{0,0,0};
	std::array<std::string, 3> suffixMods{"","",""};
	std::array<int, 3> suffixTiers{0,0,0};

	std::string itemDescription = "";

	// SFML
	std::array<sf::Text, 2> implicitStatText;
	std::array<sf::Text, 2> implicitModText;
	std::array<sf::Text, 2> implicitTierText;

	std::array<sf::Text, 2> prefixStatText;
	std::array<sf::Text, 2> prefixModText;
	std::array<sf::Text, 2> prefixTierText;

	std::array<sf::Text, 3> suffixStatText;
	std::array<sf::Text, 3> suffixModText;
	std::array<sf::Text, 3> suffixTierText;
	sf::Text itemDescriptionText;

	float offset = 0.0f; // Offsets text vertically
	Item(const std::array<std::string, 5> &name, int screenWidth, int screenHeight)
		:a_Name(name)
	{
		// Set name (Visual)
		itemName.append(name[0]);
		itemName.append(name[1]);
		itemName.append(name[2]);
		itemName.append(name[3]);
		itemName.append(name[4]);

		if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
			std::cerr << "Failed to load font!\n";
		itemText.setFont(font);
		itemText.setString(itemName);
		itemText.setOrigin(itemText.getLocalBounds().width / 2, itemText.getLocalBounds().height / 2);
		itemText.setPosition(screenWidth/2, 100.0f);

		// Item image
		if (!tex.loadFromFile("Images/Placeholder.png")) // Get correct image selection
			std::cerr << "Failed to load item image!\n";
		img.setTexture(tex);
		img.setOrigin(img.getLocalBounds().width/2, img.getLocalBounds().height/2);
		img.setPosition(itemText.getPosition().x, itemText.getPosition().y + 150.0f);

		// Rarity
		rarityVisual.setSize(sf::Vector2f(15.0f,250.0f));
		rarityVisual.setOrigin(rarityVisual.getSize().x/2, rarityVisual.getSize().y/2);
		rarityVisual.setPosition(itemText.getPosition().x - 190.0f, itemText.getPosition().y + 150.0f);
		rarityText.setFont(font);
		rarityText.setOrigin(rarityText.getLocalBounds().width/2, rarityText.getLocalBounds().height/2);
		rarityText.setPosition(itemText.getPosition().x - 70.0f, itemText.getPosition().y - 50.0f);

		// Remove string set from constructor???
		// Stat Setup | VALUE
		for (unsigned int i = 0; i < implicitStatText.size(); i++) {
			implicitStatText[i].setFont(font);
			implicitStatText[i].setString(std::to_string(implicitValues[i])); 
			implicitStatText[i].setOrigin(implicitStatText[i].getLocalBounds().width / 2, implicitStatText[i].getLocalBounds().height / 2); 
			implicitStatText[i].setPosition(screenWidth/3, offset + 150.0f);
			implicitStatText[i].setFillColor(sf::Color(70, 130, 180, 255));
			implicitStatText[i].setStyle(sf::Text::Italic);
			offset += 25.0f;
		}
		for (unsigned int i = 0; i < prefixStatText.size(); i++) { 
			prefixStatText[i].setFont(font);
			prefixStatText[i].setString(std::to_string(prefixValues[i])); 
			prefixStatText[i].setOrigin(prefixStatText[i].getLocalBounds().width / 2, prefixStatText[i].getLocalBounds().height / 2); 
			prefixStatText[i].setPosition(screenWidth/3, offset + 150.0f);
			prefixStatText[i].setFillColor(sf::Color(70, 130, 180, 255));
			prefixStatText[i].setStyle(sf::Text::Italic);
			offset += 25.0f;
		}
		for (unsigned int i = 0; i < suffixStatText.size(); i++) {
			suffixStatText[i].setFont(font);
			suffixStatText[i].setString(std::to_string(suffixValues[i])); 
			suffixStatText[i].setOrigin(suffixStatText[i].getLocalBounds().width / 2, suffixStatText[i].getLocalBounds().height / 2); 
			suffixStatText[i].setPosition(screenWidth/3, offset + 150.0f);
			suffixStatText[i].setFillColor(sf::Color(70, 130, 180, 255));
			suffixStatText[i].setStyle(sf::Text::Italic);
			offset += 25.0f;
		}

		offset = 0.0f;
		// Stat Setup | MOD
		for (unsigned int i = 0; i < implicitModText.size(); i++) { 
			implicitModText[i].setFont(font);
			implicitModText[i].setString(implicitMods[i]); 
			implicitModText[i].setOrigin(implicitModText[i].getLocalBounds().width / 2, implicitModText[i].getLocalBounds().height / 2); 
			implicitModText[i].setPosition(screenWidth/2.5, offset + 140.0f);
			implicitModText[i].setFillColor(sf::Color(70, 130, 180, 255));
			offset += 25.0f;
		}
		for (unsigned int i = 0; i < prefixModText.size(); i++) { 
			prefixModText[i].setFont(font);
			prefixModText[i].setString(prefixMods[i]); 
			prefixModText[i].setOrigin(prefixModText[i].getLocalBounds().width / 2, prefixModText[i].getLocalBounds().height / 2); 
			prefixModText[i].setPosition(screenWidth/2.5, offset + 140.0f);
			prefixModText[i].setFillColor(sf::Color(70, 130, 180, 255));
			offset += 25.0f;
		}
		for (unsigned int i = 0; i < suffixModText.size(); i++) {  
			suffixModText[i].setFont(font);
			suffixModText[i].setString(suffixMods[i]); 
			suffixModText[i].setOrigin(suffixModText[i].getLocalBounds().width / 2, suffixModText[i].getLocalBounds().height / 2); 
			suffixModText[i].setPosition(screenWidth/2.5, offset + 140.0f);
			suffixModText[i].setFillColor(sf::Color(70, 130, 180, 255));
			offset += 25.0f;
		}

		offset = 0.0f;
		// Stat Setup | TIER | Problematic
		for (unsigned int i = 0; i < implicitTierText.size(); i++) { 
			implicitTierText[i].setFont(font);
			implicitTierText[i].setString(std::to_string(implicitTiers[i])); 
			implicitTierText[i].setOrigin(implicitTierText[i].getLocalBounds().width / 2, implicitTierText[i].getLocalBounds().height / 2); 
			implicitTierText[i].setPosition(screenWidth - 200, offset + 150.0f);
			implicitTierText[i].setFillColor(sf::Color(70, 130, 180, 255));
			offset += 25.0f;
		}
		for (unsigned int i = 0; i < prefixTierText.size(); i++) { 
			prefixTierText[i].setFont(font);
			prefixTierText[i].setString(std::to_string(prefixTiers[i])); 
			prefixTierText[i].setOrigin(prefixTierText[i].getLocalBounds().width / 2, prefixTierText[i].getLocalBounds().height / 2); 
			prefixTierText[i].setPosition(screenWidth - 200, offset + 150.0f);
			prefixTierText[i].setFillColor(sf::Color(70,130,180,255));
			offset += 25.0f;
		}
		for (unsigned int i = 0; i < suffixTierText.size(); i++) { 
			suffixTierText[i].setFont(font);
			suffixTierText[i].setString(std::to_string(suffixTiers[i])); 
			suffixTierText[i].setOrigin(suffixTierText[i].getLocalBounds().width / 2, suffixTierText[i].getLocalBounds().height / 2); 
			suffixTierText[i].setPosition(screenWidth - 200, offset + 150.0f);
			suffixTierText[i].setFillColor(sf::Color(70, 130, 180, 255));
			offset += 25.0f;
		}

		itemPrevBack.setSize(sf::Vector2f(50.0f, 70.0f));
		itemPrevBack.setOrigin(itemPrevBack.getSize().x/2, itemPrevBack.getSize().y/2);

		GREY_OUT.setSize(sf::Vector2f(itemPrevBack.getSize().x, itemPrevBack.getSize().y));
		GREY_OUT.setOrigin(GREY_OUT.getSize().x/2, GREY_OUT.getSize().y/2);
		GREY_OUT.setFillColor(sf::Color(0,0,0,128));
	}
	~Item() {};

	void Draw(sf::RenderWindow &window) const; // Prints everything about the item in an ordered format | SFML based
	// virtual void GenerateStats(std::vector<std::string>& suffixes); // Implicit and Prefix | Suffix generation is global
	virtual void GenerateStats(int thresholds[4], int choice) {} // Check!
	void StashDraw(sf::RenderWindow &window) const;
};

class Sword : public Item {
private:
public:
	Sword(std::array<std::string, 5> &name, int screenWidth, int screenHeight)
		:Item(name, screenWidth, screenHeight)
	{
		type = 0;
	}
	void GenerateStats(int thresholds[4], int choice);
};

class Boots : public Item {
private:
public:
	Boots(std::array<std::string, 5> &name, int screenWidth, int screenHeight)
		:Item(name, screenWidth, screenHeight)
	{
		type = 3;
	}
	void GenerateStats(int thresholds[4], int choice);
};

class Ring : public Item {
private:
public:
	Ring(std::array<std::string, 5> &name, int screenWidth, int screenHeight)
		:Item(name, screenWidth, screenHeight)
	{
		type = 5;
	}
	void GenerateStats(int thresholds[4], int choice);
};

class Chest : public Item {
private:
public:
	Chest(std::array<std::string, 5> &name, int screenWidth, int screenHeight)
		:Item(name, screenWidth, screenHeight)
	{
		type = 4;
	}
	void GenerateStats(int thresholds[4], int choice);
};

class Belt : public Item {
private:
public:
	Belt(std::array<std::string, 5> &name, int screenWidth, int screenHeight)
		:Item(name, screenWidth, screenHeight)
	{
		type = 7;
	}
	void GenerateStats(int thresholds[4], int choice);
};

class Bow : public Item {
private:
public:
	Bow(std::array<std::string, 5> &name, int screenWidth, int screenHeight)
		:Item(name, screenWidth, screenHeight)
	{
		type = 2;
	}
	void GenerateStats(int thresholds[4], int choice);
};

class Staff : public Item {
private:
public:
	Staff(std::array<std::string, 5> &name, int screenWidth, int screenHeight)
		:Item(name, screenWidth, screenHeight)
	{
	}
	void GenerateStats(int thresholds[4], int choice);
};

class Helmet : public Item {
private:
public:
	Helmet(std::array<std::string, 5> &name, int screenWidth, int screenHeight)
		:Item(name, screenWidth, screenHeight)
	{
	}
	void GenerateStats(int thresholds[4], int choice);
};

class Amulet : public Item {
private:
public:
	Amulet(std::array<std::string, 5>& name, int screenWidth, int screenHeight)
		:Item(name, screenWidth, screenHeight)
	{
		type = 6;
	}
	void GenerateStats(int thresholds[4], int choice);
};

#endif