#include <fstream>
#include <ctime>
#include <cctype>
#include <thread>
#include <string>

#include "SuffixStats.h"
#include "Prefixes.h"
#include "Character.h"
#include "Generator.h"

#include <SFML/Graphics.hpp>

// Re-write crafting system input
// Draw crafting materials
// Re-write item generator
// Fix positioning
// Replace images
// Add different fonts
// Add window scaling

Character c("TestCharacter", 5);
int screenWidth = 1000, screenHeight = 800;
sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "ARPG Crafting System");
sf::Event event;

// Hover
sf::Font font;
sf::Text hoverText;

void Interface(Item& i);
void RollItem();

bool Compare(const sf::Text &str1, const sf::Text &str2) {
	if (str1.getString() == str2.getString())
		return true;
	return false;
}

void RarityGen(Item &i, int choice) {
	choice = rand() % 6;
	switch (choice) {
		case 0: i.rarity = i.NORMAL; 
				i.rarityText.setString("NORMAL");
				i.rarityText.setFillColor(sf::Color(225,225,225,255));
				i.rarityVisual.setFillColor(sf::Color(225,225,225,200));
			break;
		case 1: i.rarity = i.MAGIC;  
				i.rarityText.setString("MAGIC");
				i.rarityText.setFillColor(sf::Color(0,0,139,255));
				i.rarityVisual.setFillColor(sf::Color(0,0,139,200));
			break;
		case 2: i.rarity = i.RARE;   
				i.rarityText.setString("RARE");
				i.rarityText.setFillColor(sf::Color(255,255,51,255));
				i.rarityVisual.setFillColor(sf::Color(255,255,51,200));
			break;
		case 3: i.rarity = i.UNIQUE; 
				i.rarityText.setString("UNIQUE");
				i.rarityText.setFillColor(sf::Color(255,140,0,255));
				i.rarityVisual.setFillColor(sf::Color(255,140,0,200));
			break;
		case 4: i.rarity = i.EXALTED;
				i.rarityText.setString("EXALTED");
				i.rarityText.setFillColor(sf::Color(186,85,211,255));
				i.rarityVisual.setFillColor(sf::Color(186,85,211,200));
			break;
		case 5: i.rarity = i.BOSS;   
				i.rarityText.setString("BOSS");
				i.rarityText.setFillColor(sf::Color(60, 179, 113,255));
				i.rarityVisual.setFillColor(sf::Color(60, 179, 113,200));
			break;
	}
}

void PrefixStatGeneration(Item &i, int choice) {
	if (i.type == 0) { // SWORDS
		for (unsigned int j = 0; j < i.prefixModText.size(); j++)
			i.prefixModText[j].setString(SwordPrefixes::prefixes[choice = rand() % SwordPrefixes::prefixes.size()]);
		for(unsigned int j = 0; j < i.prefixStatText.size(); j++)
			i.prefixStatText[j].setString(std::to_string(choice = rand() % 75));
		while(Compare(i.prefixModText[0], i.prefixModText[1]))
			i.prefixModText[0].setString(SwordPrefixes::prefixes[choice = rand() % SwordPrefixes::prefixes.size()]);
	}
	else if (i.type == 2) {
		while(Compare(i.prefixModText[0], i.prefixModText[1]))
			i.prefixModText[0].setString(SwordPrefixes::prefixes[choice = rand() % SwordPrefixes::prefixes.size()]);
	}
	else if (i.type == 3) { // BOOTS
		for (unsigned int j = 0; j < i.prefixModText.size(); j++)
			i.prefixModText[j].setString(BootPrefixes::prefixes[choice = rand() % BootPrefixes::prefixes.size()]);
		for (unsigned int j = 0; j < i.prefixStatText.size(); j++)
			i.prefixStatText[j].setString(std::to_string(choice = rand() % 75));
		while(Compare(i.prefixModText[0], i.prefixModText[1]))
			i.prefixModText[0].setString(BootPrefixes::prefixes[choice = rand() % BootPrefixes::prefixes.size()]);
	}
	else if (i.type == 4) { // CHEST
		for (unsigned int j = 0; j < i.prefixModText.size(); j++)
			i.prefixModText[j].setString(ChestPrefixes::prefixes[choice = rand() % ChestPrefixes::prefixes.size()]);
		for (unsigned int j = 0; j < i.prefixStatText.size(); j++)
			i.prefixStatText[j].setString(std::to_string(choice = rand() % 75));
		while(Compare(i.prefixModText[0], i.prefixModText[1]))
			i.prefixModText[0].setString(ChestPrefixes::prefixes[choice = rand() % ChestPrefixes::prefixes.size()]);
	}
	else if (i.type == 5) {
		for (unsigned int j = 0; j < i.prefixModText.size(); j++)
			i.prefixModText[j].setString(RingPrefixes::prefixes[choice = rand() % RingPrefixes::prefixes.size()]);
		for (unsigned int j = 0; j < i.prefixStatText.size(); j++)
			i.prefixStatText[j].setString(std::to_string(choice = rand() % 75));
		while(Compare(i.prefixModText[0], i.prefixModText[1]))
			i.prefixModText[0].setString(RingPrefixes::prefixes[choice = rand() % RingPrefixes::prefixes.size()]);
	}
	else if (i.type == 6) {
		return;
	}
	else if (i.type == 7) {
		for (unsigned int j = 0; j < i.prefixModText.size(); j++)
			i.prefixModText[j].setString(BeltPrefixes::prefixes[choice = rand() % BeltPrefixes::prefixes.size()]);
		for (unsigned int j = 0; j < i.prefixStatText.size(); j++)
			i.prefixStatText[j].setString(std::to_string(choice = rand() % 75));
		while (Compare(i.prefixModText[0], i.prefixModText[1]))
			i.prefixModText[0].setString(BeltPrefixes::prefixes[choice = rand() % BeltPrefixes::prefixes.size()]);
	}
}

void SuffixStatGeneration(Item &i, int choice) {
	for(unsigned int j = 0; j < i.suffixModText.size(); j++)
		i.suffixModText[j].setString(Suffixes::suffixes[choice = rand() % Suffixes::suffixes.size()]);
	for (unsigned int j = 0; j < i.suffixStatText.size(); j++) {
		i.suffixValues[j] = choice = rand() % 50;
		i.suffixStatText[j].setString(std::to_string(i.suffixValues[j]));
	}
	/* Fix 
	for (unsigned int j = 0; j < i.suffixTierText.size(); j++) {
		for (unsigned int k = 0; k < 4; k++) {
			if (i.implicitValues[j] > SwordThresholds::thresholds[k])
				i.suffixTierText[j].setString(std::to_string(j));
		}
	}
	*/
}

// Generators
// Seperate loops for different tiering
void SwordGen(Item &i, int choice) {
	if(i.itemName.find("Damascus Steel Sword") != std::string::npos) {
		i.implicitModText[0].setString("extra damage");
		i.implicitModText[1].setString("crit chance");
	}
	else if(i.itemName.find("Iron Sword") != std::string::npos) {
		i.implicitModText[0].setString("extra attack speed");
		i.implicitModText[1].setString("crit multi");
	}
	else if(i.itemName.find("Serrated Sword") != std::string::npos) {
		i.implicitModText[0].setString("bleed chance");
		i.implicitModText[1].setString("damage dealt over time");
	}
	else if(i.itemName.find("Scimitar") != std::string::npos) {
		i.implicitModText[0].setString("extra attack speed");
		i.implicitModText[1].setString("dexterity");
	}
	else if(i.itemName.find("Twisted Sword") != std::string::npos) {
		i.implicitModText[0].setString("strength"); // +
		i.implicitModText[1].setString("health"); // +
	}
	else if(i.itemName.find("Spiral Sword") != std::string::npos) {
		i.implicitModText[0].setString("pierce rating");
		i.implicitModText[1].setString("crit-multi");
	}
	else if(i.itemName.find("Katana") != std::string::npos) {
		i.implicitModText[0].setString("attack range");
		i.implicitModText[1].setString("multi strike chance");
	}
	else if(i.itemName.find("Plate Sword") != std::string::npos) {
		i.implicitModText[0].setString("block chance"); // %
		i.implicitModText[1].setString("increased armor");
	}
	else if(i.itemName.find("Falchion") != std::string::npos) {
		i.implicitModText[0].setString("dodge rating");
		i.implicitModText[1].setString("movement speed");
	}
	else if(i.itemName.find("Rapier") != std::string::npos) {
		i.implicitModText[0].setString("crit chance");
		i.implicitModText[1].setString("crit multi");
	}
	for(unsigned int j = 0; j < i.implicitStatText.size(); j++) 
		i.implicitStatText[j].setString(std::to_string(choice = rand() % 100));
	for (unsigned int j = 0; j < 4; j++) { // Fix!
		if (i.implicitValues[0] > SwordThresholds::thresholds[j]) i.implicitTierText[0].setString(j);
		if (i.implicitValues[1] > SwordThresholds::thresholds[j]) i.implicitTierText[1].setString(j);
	}
	PrefixStatGeneration(i, choice);
	SuffixStatGeneration(i, choice);
}

void BootGen(Item &i, int choice) {
	if (i.itemName.find("Leather Boots") != std::string::npos) {
		i.implicitModText[0].setString("movement speed");
		i.implicitModText[1].setString("dodge rating");
	}
	else if (i.itemName.find("Steel Greaves") != std::string::npos) {
		i.implicitModText[0].setString("armor");
		i.implicitModText[1].setString("block rating");
	}
	else if (i.itemName.find("Silk Slippers") != std::string::npos) {
		i.implicitModText[0].setString("INT");
		i.implicitModText[1].setString("mana");
	}
	else if (i.itemName.find("Paladain Greaves") != std::string::npos) {
		i.implicitModText[0].setString("STR");
		i.implicitModText[1].setString("physical resistance");
	}
	else if (i.itemName.find("Rag Shoes") != std::string::npos) {
		i.implicitModText[0].setString("DEX");
		i.implicitModText[1].setString("crown control reduction");
	}
	else if (i.itemName.find("Woven Treads") != std::string::npos) {
		i.implicitModText[0].setString("movement ability cooldown reduction");
		i.implicitModText[1].setString("reduced mana usage");
	}
	else if (i.itemName.find("Studded Boots") != std::string::npos) {
		i.implicitModText[0].setString("damage");
		i.implicitModText[1].setString("damage reflect");
	}
	else if (i.itemName.find("Steelcapped Boots") != std::string::npos) {
		i.implicitModText[0].setString("movement speed");
		i.implicitModText[1].setString("more armor"); // % based
	}
	for (unsigned int j = 0; j < i.implicitStatText.size(); j++)
		i.implicitStatText[j].setString(std::to_string(choice = rand() % 100));
	for (unsigned int j = 0; j < 4; j++) {
		if (i.implicitValues[0] > BootThresholds::thresholds[j]) i.implicitTierText[0].setString(j);
		if (i.implicitValues[1] > BootThresholds::thresholds[j]) i.implicitTierText[1].setString(j);
	}
	PrefixStatGeneration(i, choice);
	SuffixStatGeneration(i, choice);
}

void RingGen(Item &i, int choice) {
	if (i.itemName.find("Leather Boots") != std::string::npos) {
		i.implicitModText[0].setString("extra damage");
		i.implicitModText[1].setString("crit chance");
	}
	else if (i.itemName.find("Leather Boots") != std::string::npos) {
		i.implicitModText[0].setString("extra damage");
		i.implicitModText[1].setString("crit chance");
	}
	else if (i.itemName.find("Leather Boots") != std::string::npos) {
		i.implicitModText[0].setString("extra damage");
		i.implicitModText[1].setString("crit chance");
	}
	for (unsigned int j = 0; j < i.implicitStatText.size(); j++)
		i.implicitStatText[j].setString(std::to_string(choice = rand() % 100));
	for (unsigned int j = 0; j < 4; j++) {
		if (i.implicitValues[0] > BootThresholds::thresholds[j]) i.implicitTierText[0].setString(j);
		if (i.implicitValues[1] > BootThresholds::thresholds[j]) i.implicitTierText[1].setString(j);
	}
	PrefixStatGeneration(i, choice);
	SuffixStatGeneration(i, choice);
}

void ChestGen(Item& i, int choice) {
	if (i.itemName.find("Leather Armor") != std::string::npos) {
		i.implicitModText[0].setString("Increased armor");
		i.implicitModText[1].setString("STR");
	}
	else if (i.itemName.find("Paladins Plate") != std::string::npos) { // Significantly more armor
		i.implicitModText[0].setString("Increased armor");
		i.implicitModText[1].setString("Light radius");
	}
	else if (i.itemName.find("Silk Robes") != std::string::npos) {
		i.implicitModText[0].setString("Increased mana");
		i.implicitModText[1].setString("Spell damage resistance");
	}
	else if (i.itemName.find("Rag Cloth") != std::string::npos) {
		i.implicitModText[0].setString("DEX");
		i.implicitModText[1].setString("Attack Speed");
	}
	PrefixStatGeneration(i, choice);
	SuffixStatGeneration(i, choice);
}

void BeltGen(Item &i, int choice) {
	if (i.itemName.find("Leather Armor") != std::string::npos) {
		i.implicitModText[0].setString("Increased armor");
		i.implicitModText[1].setString("STR");
	}
	else if (i.itemName.find("Paladins Plate") != std::string::npos) { // Significantly more armor
		i.implicitModText[0].setString("Increased armor");
		i.implicitModText[1].setString("Light radius");
	}
	else if (i.itemName.find("Silk Robes") != std::string::npos) {
		i.implicitModText[0].setString("Increased mana");
		i.implicitModText[1].setString("Spell damage resistance");
	}
	else if (i.itemName.find("Rag Cloth") != std::string::npos) {
		i.implicitModText[0].setString("DEX");
		i.implicitModText[1].setString("Attack Speed");
	}
	PrefixStatGeneration(i, choice);
	SuffixStatGeneration(i, choice);
}

std::array<std::string, 5> GenerateName(char t) {
	int choice = 0;
	std::array<std::string, 5> nameTest{"", " ", "", " ", ""};
	if (t == 's') {
		choice = rand() % 5;
		if (choice > 3) {
			choice = rand() % SwordPrefixNames::prefixes.size();
			nameTest[0] = SwordPrefixNames::prefixes[choice];
		}
		choice = rand() % SwordBaseNames::bases.size();
		nameTest[2] = SwordBaseNames::bases[choice];
	}
	else if (t == 'b') {
		choice = rand() % 5;
		if (choice > 3) {
			choice = rand() % BootsPrefixNames::prefixes.size();
			nameTest[0] = BootsPrefixNames::prefixes[choice];
		}
		choice = rand() % BootsBaseNames::bases.size();
		nameTest[2] = BootsBaseNames::bases[choice];
	}
	else if(t == 'r') {
		choice = rand() % 5;
		if (choice > 3) {
			choice = rand() % RingPrefixNames::prefixes.size();
			nameTest[0] = RingPrefixNames::prefixes[choice];
		}
		choice = rand() % RingBaseNames::bases.size();
		nameTest[2] = RingBaseNames::bases[choice];
	}
	else if (t == 'c') {
		choice = rand() % 5;
		if (choice > 3) {
			choice = rand() % ChestPrefixNames::prefixes.size();
			nameTest[0] = ChestPrefixNames::prefixes[choice];
		}
		choice = rand() % ChestBaseNames::bases.size();
		nameTest[2] = ChestBaseNames::bases[choice];
	}
	else if (t == 'w') {
		choice = rand() % 5;
		if (choice > 3) {
			choice = rand() % BeltPrefixNames::prefixes.size();
			nameTest[0] = BeltPrefixNames::prefixes[choice];
		}
		choice = rand() % BeltBaseNames::bases.size();
		nameTest[2] = BeltBaseNames::bases[choice];
	}
	// Suffix generation
	choice = rand() % 5;
	if (choice > 3) {
		choice = rand() % SuffixNames::nameSuffixes.size();
		nameTest[4] = SuffixNames::nameSuffixes[choice];
	}
	return nameTest;
}

void ConfirmSelection(Item &item) {
	char input = 0;
	std::cout << "Stash?: Y/N\n";
	std::cin >> input;
	char i = std::tolower(input);
	switch (i) {
		case 'y': c.itemStash->push_back(item); break;
		case 'n': delete &item; RollItem(); break;
	}
}

void RollItem() { // Optimise! 	
	system("cls"); // Remove eventually
	int choice = 0;
	choice = rand() % 5;
	if (choice == 0) {
		std::array<std::string, 5> itemName = GenerateName('s');
		Sword *s = new Sword(itemName, screenWidth, screenHeight);
		RarityGen(*s, choice);
		SwordGen(*s, choice);
		Interface(*s); // Check!
		ConfirmSelection(*s);
	}
	else if (choice == 1) {
		std::array<std::string, 5> itemName = GenerateName('b');
		Boots *b = new Boots(itemName, screenWidth, screenHeight);
		RarityGen(*b, choice);
		BootGen(*b, choice);
		Interface(*b);
		ConfirmSelection(*b);
	}
	else if (choice == 2) {
		std::array<std::string, 5> itemName = GenerateName('r');
		Ring *r = new Ring(itemName, screenWidth, screenHeight);
		RarityGen(*r, choice);
		RingGen(*r, choice);
		Interface(*r);
		ConfirmSelection(*r);
	}
	else if (choice == 3) {
		std::array<std::string, 5> itemName = GenerateName('c');
		Chest *c = new Chest(itemName, screenWidth, screenHeight);
		RarityGen(*c, choice);
		ChestGen(*c, choice);
		Interface(*c);
		ConfirmSelection(*c);
	}
	else if (choice == 4) {
		std::array<std::string, 5> itemName = GenerateName('w');
		Belt *b = new Belt(itemName, screenWidth, screenHeight);
		RarityGen(*b, choice);
		BeltGen(*b, choice);
		Interface(*b);
		ConfirmSelection(*b);
	}
}

void Interface(Item &i) { // Add SFML here
	int choice = 0;
	window.setFramerateLimit(24);

	while (window.isOpen()) {
		window.clear();
		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) // Delete previous item if not saved!
				RollItem();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
				std::cout << "Agony\n";
				c.materialsStash[0].Use(i);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
				std::cout << "Perfection\n";
				c.materialsStash[1].Use(i);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
				std::cout << "Lament\n";
				c.materialsStash[2].Use(i);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // Fix!
				for (unsigned int i = 0; i < c.materialsStash.size(); i++) {
					std::cout << c.materialsStash[i].debugTex.getPosition().x << "|" << c.materialsStash[i].debugTex.getPosition().y << '\n';
					std::cout << sf::Mouse::getPosition().x << "|" << sf::Mouse::getPosition().y << '\n';
					for (unsigned int j = 0; j < c.materialsStash[i].debugTex.getSize().x; j++) {
						if (sf::Mouse::getPosition().x == c.materialsStash[i].debugTex.getPosition().x - j || sf::Mouse::getPosition().x == c.materialsStash[i].debugTex.getPosition().x + j) {
							std::cout << "HIT\n";
						}
					}
					for (unsigned int j = 0; j < c.materialsStash[i].debugTex.getSize().y; j++) {
						if (sf::Mouse::getPosition().y == c.materialsStash[i].debugTex.getPosition().y - j || sf::Mouse::getPosition().y == c.materialsStash[i].debugTex.getPosition().y + j) {
							std::cout << "HIT\n";
						}
					}
				}
			}
			for (unsigned int i = 0; i < c.materialsStash.size(); i++) {
				for (unsigned int j = 0; j < c.materialsStash[i].debugTex.getSize().x; j++) {
					if (sf::Mouse::getPosition().x == c.materialsStash[i].debugTex.getPosition().x - j || sf::Mouse::getPosition().x == c.materialsStash[i].debugTex.getPosition().x + j) {
						hoverText.setString(c.materialsStash[i].itemName);
						hoverText.setPosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
					}
				}
				for (unsigned int j = 0; j < c.materialsStash[i].debugTex.getSize().y; j++) {
					if (sf::Mouse::getPosition().y == c.materialsStash[i].debugTex.getPosition().y - j || sf::Mouse::getPosition().y == c.materialsStash[i].debugTex.getPosition().y + j) {
						hoverText.setString(c.materialsStash[i].itemName);
						hoverText.setPosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
					}
				}
			}
		}
		c.PrintStats(window);
		i.Draw(window);
		c.PrintMatStash(window);
		window.draw(hoverText);
		window.display();
	}
}

int main() {
	if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
		std::cerr << "Failed to load hover text font!\n";
	hoverText.setFont(font);
	hoverText.setOrigin(hoverText.getLocalBounds().width - hoverText.getLocalBounds().width, hoverText.getLocalBounds().height/2);

	srand(time(0));
	std::array<std::string, 5> defaultName{"", "", "Default Item", "", ""};
	Item defaultItem(defaultName, screenWidth, screenHeight);
	Interface(defaultItem);

	return 0;
}