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

Character<std::tuple<int,float>> c("TestCharacter", 5);

namespace Main {
	int screenWidth = 1000, screenHeight = 800;
	sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "ARPG Crafting System"); // sf::Style::Fullscreen
	sf::Event event;
	sf::RectangleShape takeItem;
	sf::RectangleShape rollItem;
	sf::RectangleShape searchButton;
	sf::Text rollItemText;
	sf::Text takeItemText;
	sf::Text searchButtonText;

	sf::Texture mouseCursor;
	sf::Sprite cursor;

	std::string searchString = "";
	sf::Text searchText;

	bool printInventory = false;
	bool printStats = false;
	bool isSearching = false;
}

using namespace Main;

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
				i.itemPrevBack.setFillColor(sf::Color(225,225,225,200));
			break;
		case 1: i.rarity = i.MAGIC;  
				i.rarityText.setString("MAGIC");
				i.rarityText.setFillColor(sf::Color(0,0,139,255));
				i.rarityVisual.setFillColor(sf::Color(0,0,139,200));
				i.itemPrevBack.setFillColor(sf::Color(0,0,139,200));
			break;
		case 2: i.rarity = i.RARE;   
				i.rarityText.setString("RARE");
				i.rarityText.setFillColor(sf::Color(255,255,51,255));
				i.rarityVisual.setFillColor(sf::Color(255,255,51,200));
				i.itemPrevBack.setFillColor(sf::Color(225,225,51,200));
			break;
		case 3: i.rarity = i.UNIQUE; 
				i.rarityText.setString("UNIQUE");
				i.rarityText.setFillColor(sf::Color(255,140,0,255));
				i.rarityVisual.setFillColor(sf::Color(255,140,0,200));
				i.itemPrevBack.setFillColor(sf::Color(225,140,0,200));
			break;
		case 4: i.rarity = i.EXALTED;
				i.rarityText.setString("EXALTED");
				i.rarityText.setFillColor(sf::Color(186,85,211,255));
				i.rarityVisual.setFillColor(sf::Color(186,85,211,200));
				i.itemPrevBack.setFillColor(sf::Color(186,85,211,200));
			break;
		case 5: i.rarity = i.BOSS;   
				i.rarityText.setString("BOSS");
				i.rarityText.setFillColor(sf::Color(60, 179, 113,255));
				i.rarityVisual.setFillColor(sf::Color(60, 179, 113,200));
				i.itemPrevBack.setFillColor(sf::Color(60,179,113,200));
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
	else if (i.type == 2) { // BOW
		for (unsigned int j = 0; j < i.prefixModText.size(); j++)
			i.prefixModText[j].setString(BowPrefixes::prefixes[choice = rand() % BowPrefixes::prefixes.size()]);
		for (unsigned int j = 0; j < i.prefixStatText.size(); j++)
			i.prefixStatText[j].setString(std::to_string(choice = rand() % 75));
		while(Compare(i.prefixModText[0], i.prefixModText[1]))
			i.prefixModText[0].setString(BowPrefixes::prefixes[choice = rand() % BowPrefixes::prefixes.size()]);
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
	else if (i.type == 5) { // RINGS
		for (unsigned int j = 0; j < i.prefixModText.size(); j++)
			i.prefixModText[j].setString(RingPrefixes::prefixes[choice = rand() % RingPrefixes::prefixes.size()]);
		for (unsigned int j = 0; j < i.prefixStatText.size(); j++)
			i.prefixStatText[j].setString(std::to_string(choice = rand() % 75));
		while(Compare(i.prefixModText[0], i.prefixModText[1]))
			i.prefixModText[0].setString(RingPrefixes::prefixes[choice = rand() % RingPrefixes::prefixes.size()]);
	}
	else if (i.type == 6) { // Amulet
		for (unsigned int j = 0; j < i.prefixModText.size(); j++)
			i.prefixModText[j].setString(AmuletPrefixes::prefixes[choice = rand() % AmuletPrefixes::prefixes.size()]);
		for (unsigned int j = 0; j < i.prefixStatText.size(); j++)
			i.prefixStatText[j].setString(std::to_string(choice = rand() % 75));
		while (Compare(i.prefixModText[0], i.prefixModText[1]))
			i.prefixModText[0].setString(AmuletPrefixes::prefixes[choice = rand() % AmuletPrefixes::prefixes.size()]);
	}
	else if (i.type == 7) { // Belt
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
// Seperate loops for different tiering ?
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
	else if (t == 'o') {
		choice = rand() % 5;
		if (choice > 3) {
			choice = rand() % BowPrefixNames::prefixes.size();
			nameTest[0] = BowPrefixNames::prefixes[choice];
		}
		choice = rand() % BowBaseNames::bases.size();
		nameTest[2] = BowBaseNames::bases[choice];
	}
	else if (t == 'f') {
		choice = rand() % 5;
		if (choice > 3) {
			choice = rand() % StaffPrefixNames::prefixes.size();
			nameTest[0] = StaffPrefixNames::prefixes[choice];
		}
		choice = rand() % StaffBaseNames::bases.size();
		nameTest[2] = StaffBaseNames::bases[choice];
	}
	else if (t == 'h') {
		choice = rand() % 5;
		if (choice > 3) {
			choice = rand() % HelmetPrefixNames::prefixes.size();
			nameTest[0] = HelmetPrefixNames::prefixes[choice];
		}
		choice = rand() % HelmetBaseNames::bases.size();
		nameTest[2] = HelmetBaseNames::bases[choice];
	}
	else if (t == 'a') {
		choice = rand() % 5;
		if (choice > 3) {
			choice = rand() % AmuletPrefixNames::prefixes.size();
			nameTest[0] = AmuletPrefixNames::prefixes[choice];
		}
		choice = rand() % AmuletBaseNames::bases.size();
		nameTest[2] = AmuletBaseNames::bases[choice];
	}
	// Suffix generation
	choice = rand() % 5;
	if (choice > 3) {
		choice = rand() % SuffixNames::nameSuffixes.size();
		nameTest[4] = SuffixNames::nameSuffixes[choice];
	}
	return nameTest;
}

void RollItem() { // Optimise! 	
	system("cls"); // Remove eventually?
	int choice = 0;
	choice = rand() % 9;
	if (choice == 0) {
		std::array<std::string, 5> itemName = GenerateName('s');
		Sword *s = new Sword(itemName, screenWidth, screenHeight);
		RarityGen(*s, choice);
		s->GenerateStats(SwordThresholds::thresholds, choice);
		PrefixStatGeneration(*s, choice);
		SuffixStatGeneration(*s, choice);
		Interface(*s); // Check!
	}
	else if (choice == 1) {
		std::array<std::string, 5> itemName = GenerateName('b');
		Boots *b = new Boots(itemName, screenWidth, screenHeight);
		RarityGen(*b, choice);
		b->GenerateStats(BootThresholds::thresholds, choice);
		PrefixStatGeneration(*b, choice);
		SuffixStatGeneration(*b, choice);
		Interface(*b);
	}
	else if (choice == 2) {
		std::array<std::string, 5> itemName = GenerateName('r');
		Ring *r = new Ring(itemName, screenWidth, screenHeight);
		RarityGen(*r, choice);
		r->GenerateStats(SwordThresholds::thresholds, choice);
		PrefixStatGeneration(*r, choice);
		SuffixStatGeneration(*r, choice);
		Interface(*r);
	}
	else if (choice == 3) {
		std::array<std::string, 5> itemName = GenerateName('c');
		Chest *c = new Chest(itemName, screenWidth, screenHeight);
		RarityGen(*c, choice);
		c->GenerateStats(SwordThresholds::thresholds, choice);
		PrefixStatGeneration(*c, choice);
		SuffixStatGeneration(*c, choice);
		Interface(*c);
	}
	else if (choice == 4) {
		std::array<std::string, 5> itemName = GenerateName('w');
		Belt *b = new Belt(itemName, screenWidth, screenHeight);
		RarityGen(*b, choice);
		b->GenerateStats(SwordThresholds::thresholds, choice);
		PrefixStatGeneration(*b, choice);
		SuffixStatGeneration(*b, choice);
		Interface(*b);
	}
	else if (choice == 5) {
		std::array<std::string, 5> itemName = GenerateName('o');
		Bow* bo = new Bow(itemName, screenWidth, screenHeight);
		RarityGen(*bo, choice);
		bo->GenerateStats(SwordThresholds::thresholds, choice);
		PrefixStatGeneration(*bo, choice);
		SuffixStatGeneration(*bo, choice);
		Interface(*bo);
	}
	else if (choice == 6) {
		std::array<std::string, 5> itemName = GenerateName('f');
		Staff* st = new Staff(itemName, screenWidth, screenHeight);
		RarityGen(*st, choice);
		st->GenerateStats(SwordThresholds::thresholds, choice);
		PrefixStatGeneration(*st, choice);
		SuffixStatGeneration(*st, choice);
		Interface(*st);
	}
	else if (choice == 7) {
		std::array<std::string, 5> itemName = GenerateName('h');
		Helmet* h = new Helmet(itemName, screenWidth, screenHeight);
		RarityGen(*h, choice);
		h->GenerateStats(SwordThresholds::thresholds, choice);
		PrefixStatGeneration(*h, choice);
		SuffixStatGeneration(*h, choice);
		Interface(*h);
	}
	else if (choice == 8) {
		std::array<std::string, 5> itemName = GenerateName('a');
		Amulet* a = new Amulet(itemName, screenWidth, screenHeight);
		RarityGen(*a, choice);
		a->GenerateStats(SwordThresholds::thresholds, choice);
		PrefixStatGeneration(*a, choice);
		SuffixStatGeneration(*a, choice);
		Interface(*a);
	}
}

void Interface(Item &i) { // Add SFML here
	int choice = 0;
	window.setFramerateLimit(24);
	// window.setMouseCursorVisible(false);

	while (window.isOpen()) {
		window.clear();

		// cursor.setPosition(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::I) && printInventory) // Inventory
				printInventory = false;
			else if(sf::Keyboard::isKeyPressed(sf::Keyboard::I) && !printInventory)
				printInventory = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && printStats) // Character Screen
				printStats = false;
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::C) && !printStats)
				printStats = true;
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) { // Delete previous item if not saved!
				RollItem();
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2)) {
				std::cout << "Agony\n";
				switch (i.type) {
					case 0: c.materialsStash[0].Use(i, SwordThresholds::thresholds, choice); break;
					case 1: c.materialsStash[0].Use(i, SwordThresholds::thresholds, choice); break;
					case 2: c.materialsStash[0].Use(i, SwordThresholds::thresholds, choice); break;
					case 3: c.materialsStash[0].Use(i, BootThresholds::thresholds,  choice); break;
					case 4: c.materialsStash[0].Use(i, SwordThresholds::thresholds, choice); break;
					case 5: c.materialsStash[0].Use(i, SwordThresholds::thresholds, choice); break;
					case 6: c.materialsStash[0].Use(i, SwordThresholds::thresholds, choice); break;
					case 7: c.materialsStash[0].Use(i, SwordThresholds::thresholds, choice); break;
				}
				Interface(i);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num3)) {
				std::cout << "Perfection\n";
				// c.materialsStash[1].Use(i);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num4)) {
				std::cout << "Lament\n";
				// c.materialsStash[2].Use(i);
			}
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) { // Fix!
				for (unsigned int i = 0; i < c.materialsStash.size(); i++) {
					for (unsigned int j = 0; j < c.materialsStash[i].debugTex.getSize().x; j++) {
						if (sf::Mouse::getPosition(window).x == c.materialsStash[i].debugTex.getPosition().x - j || sf::Mouse::getPosition(window).x == c.materialsStash[i].debugTex.getPosition().x + j) {
							//c.materialsStash[i].Use(i, SwordThresholds::thresholds, choice);
							continue;
						}
					}
					for (unsigned int j = 0; j < c.materialsStash[i].debugTex.getSize().y; j++) {
						if (sf::Mouse::getPosition(window).y == c.materialsStash[i].debugTex.getPosition().y - j || sf::Mouse::getPosition(window).y == c.materialsStash[i].debugTex.getPosition().y + j) {
							//c.materialsStash[i].Use(i, SwordThresholds::thresholds, choice);
							continue;
						}
					}
				}
				// Take Item | Prevent multiple inputs!!
				for (unsigned int j = 0; j < takeItem.getSize().x; j++) {
					if (sf::Mouse::getPosition(window).x == takeItem.getPosition().x - j || sf::Mouse::getPosition(window).x == takeItem.getPosition().x + j) {
						c.itemStash.push_back(&i);
						c.itemStashMap.insert(std::pair<int, Item>(c.itemStashMap.size()+1, i));
						c.SetInventory();
						RollItem();
					}
				}
				for (unsigned int j = 0; j < takeItem.getSize().y; j++) {
					if (sf::Mouse::getPosition(window).y == takeItem.getPosition().y - j || sf::Mouse::getPosition(window).y == takeItem.getPosition().y + j) {
						c.itemStash.push_back(&i);
						c.itemStashMap.insert(std::pair<int, Item>(c.itemStashMap.size()+1, i));
						c.SetInventory();
						RollItem();
					}
				}
				// Roll Item
				for (unsigned int i = 0; i < rollItem.getSize().x; i++) {
					if (sf::Mouse::getPosition(window).x == rollItem.getPosition().x - i || sf::Mouse::getPosition(window).x == rollItem.getPosition().x + i) 
						RollItem();
				}
				for (unsigned int i = 0; i < rollItem.getSize().y; i++) {
					if (sf::Mouse::getPosition(window).y == rollItem.getPosition().y - i || sf::Mouse::getPosition(window).y == rollItem.getPosition().y + i)
						RollItem();
				}
				// Search
				for (unsigned int i = 0; i < searchButton.getSize().x; i++) {
					if (sf::Mouse::getPosition(window).x == searchButton.getPosition().x - i || sf::Mouse::getPosition(window).x == searchButton.getPosition().x + i) {
						switch (isSearching) {
							case true: isSearching = false; break;
							case false: isSearching = true; break;
						}
					}
				}
				for (unsigned int i = 0; i < searchButton.getSize().y; i++) {
					if (sf::Mouse::getPosition(window).y == searchButton.getPosition().y - i || sf::Mouse::getPosition(window).y == searchButton.getPosition().y + i) {
						switch (isSearching) {
							case true: isSearching = false; break;
							case false: isSearching = true; break;
						}
					}
				}
			}
			for (unsigned int i = 0; i < c.materialsStash.size(); i++) {
				for (unsigned int j = 0; j < c.materialsStash[i].debugTex.getSize().x; j++) {
					if (sf::Mouse::getPosition(window).x == c.materialsStash[i].debugTex.getPosition().x - j || sf::Mouse::getPosition(window).x == c.materialsStash[i].debugTex.getPosition().x + j) {
						hoverText.setString(c.materialsStash[i].itemName);
						hoverText.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
					}
				}
				for (unsigned int j = 0; j < c.materialsStash[i].debugTex.getSize().y; j++) {
					if (sf::Mouse::getPosition(window).y == c.materialsStash[i].debugTex.getPosition().y - j || sf::Mouse::getPosition(window).y == c.materialsStash[i].debugTex.getPosition().y + j) {
						hoverText.setString(c.materialsStash[i].itemName);
						hoverText.setPosition(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y);
					}
				}
			}
			// Keyboard input
			//switch(event.type) {
				//case sf::Event::Closed(): window.close(); break;
			//}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && isSearching) {
				std::cout << "Not Searching\n";
				isSearching = false;
				break;
			}
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !isSearching) {
				std::cout << "Searching\n";
				isSearching = true;
				break;
			}
			if (isSearching) {
				switch (event.type) {
					case sf::Keyboard::A: 
						searchString += 'a'; 
						searchText.setString(searchString); 
						c.SearchItemStash(searchString);
							break;
					case sf::Keyboard::B:
						searchString += 'b';
						searchText.setString(searchString);
						c.SearchItemStash(searchString);
							break; 
					case sf::Keyboard::C:
						searchString += 'c';
						searchText.setString(searchString);
						c.SearchItemStash(searchString);
							break;
				}
			}
		}

		if (isSearching)
			window.draw(searchText);
		if (printInventory)
			c.PrintItemStash(window);
		if(printStats)
			c.PrintStats(window);
		i.Draw(window);
		c.PrintMatStash(window);
		// window.draw(hoverText);
		window.draw(takeItem);
		window.draw(rollItem);
		window.draw(searchButton);
		window.draw(takeItemText);
		window.draw(rollItemText);
		window.draw(searchButtonText);

		// window.draw(cursor);

		window.display();
	}
}

void Setup() {
	if (!font.loadFromFile("Fonts/Roboto-Bold.ttf"))
		std::cerr << "Failed to load hover text font!\n";
	hoverText.setFont(font);
	hoverText.setOrigin(hoverText.getLocalBounds().width - hoverText.getLocalBounds().width, hoverText.getLocalBounds().height / 2);

	takeItem.setFillColor(sf::Color::Green);
	takeItem.setSize(sf::Vector2f(100.0f, 50.0f));
	takeItem.setOrigin(takeItem.getSize().x / 2, takeItem.getSize().y / 2);
	takeItem.setPosition(screenWidth / 3, screenHeight - 150.0f);

	rollItem.setFillColor(sf::Color::Red);
	rollItem.setSize(sf::Vector2f(100.0f, 50.0f));
	rollItem.setOrigin(takeItem.getSize().x / 2, takeItem.getSize().y / 2);
	rollItem.setPosition(screenWidth / 1.5, screenHeight - 150.0f);

	searchButton.setFillColor(sf::Color::White);
	searchButton.setSize(sf::Vector2f(150.0f, 50.0f));
	searchButton.setOrigin(searchButton.getSize().x/2, searchButton.getSize().y/2);
	searchButton.setPosition(100.0f, 50.0f);

	takeItemText.setFont(font);
	takeItemText.setString("TAKE ITEM");
	takeItemText.setOrigin(takeItemText.getLocalBounds().width / 2, takeItemText.getLocalBounds().height / 2);
	takeItemText.setPosition(takeItem.getPosition().x, takeItem.getPosition().y);

	rollItemText.setFont(font);
	rollItemText.setString("ROLL ITEM");
	rollItemText.setOrigin(rollItemText.getLocalBounds().width / 2, rollItemText.getLocalBounds().height / 2);
	rollItemText.setPosition(rollItem.getPosition().x, rollItem.getPosition().y);

	searchButtonText.setFont(font);
	searchButtonText.setString("SEARCH");
	searchButtonText.setFillColor(sf::Color::Black);
	searchButtonText.setOrigin(searchButtonText.getLocalBounds().width / 2, searchButtonText.getLocalBounds().height / 2);
	searchButtonText.setPosition(searchButton.getPosition().x, searchButton.getPosition().y);

	searchText.setFont(font);
	searchText.setString("TEST");
	searchText.setPosition(searchButton.getPosition().x - searchButton.getLocalBounds().width/2, searchButton.getPosition().y + 50.0f);

	mouseCursor.loadFromFile("Images/Cursor.png");

	cursor.setTexture(mouseCursor);
	cursor.setOrigin(cursor.getLocalBounds().width/2, cursor.getLocalBounds().height/2);

	srand(time(0));
	std::array<std::string, 5> defaultName{ "", "", "Default Item", "", "" };
	Item defaultItem(defaultName, screenWidth, screenHeight);
	Interface(defaultItem);
}

int main() {
	Setup();

	return 0;
}