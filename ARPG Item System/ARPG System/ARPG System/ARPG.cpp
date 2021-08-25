#include <fstream>
#include <ctime>
#include <cctype>
#include <thread>
#include <string>

#include "SuffixStats.h"
#include "Character.h"
#include "Generator.h"

#include <SFML/Graphics.hpp>

Character c("TestCharacter", 5);
int screenWidth = 800, screenHeight = 600;
sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "ARPG Crafting System");
sf::Event event;

void Interface(Item& i);

std::array<std::string, 5> GenerateName(char t) {
	int choice = 0;
	std::array<std::string, 5> nameTest;
	if (t == 's') {
		choice = rand() % 5;
		if (choice > 4) {
			choice = rand() % SwordPrefixNames::prefixes.size();
			nameTest[0] = SwordPrefixNames::prefixes[choice];
			nameTest[1] = " ";
		}
		choice = rand() % SwordBaseNames::bases.size();
		nameTest[2] = SwordBaseNames::bases[choice];
		nameTest[3] = " ";
	}
	else if (t == 'b') {
		choice = rand() % 5;
		if (choice > 4) {
			choice = rand() % BootsPrefixNames::prefixes.size();
			nameTest[0] = BootsPrefixNames::prefixes[choice];
			nameTest[1] = " ";
		}
		choice = rand() % BootsBaseNames::bases.size();
		nameTest[2] = BootsBaseNames::bases[choice];
		nameTest[3] = " ";
	}
	else if(t == 'r') {
		choice = rand() % 5;
		if (choice > 4) {
			choice = rand() % RingPrefixNames::prefixes.size();
			nameTest[0] = RingPrefixNames::prefixes[choice];
			nameTest[1] = " ";
		}
		choice = rand() % RingBaseNames::bases.size();
		nameTest[2] = RingBaseNames::bases[choice];
		nameTest[3] = " ";
	}
	// Suffix generation
	choice = rand() % 5;
	if (choice > 4) {
		choice = rand() % SuffixNames::nameSuffixes.size();
		nameTest[4] = SuffixNames::nameSuffixes[choice];
	}
	return nameTest;
}

void RollItem() { // Optimise input/confirm section!!??
	system("cls");
	int choice = 0;
	char input = 0;
	choice = rand() % 3;
	if (choice == 0) {
		std::array<std::string, 5> itemName = GenerateName('s');
		Sword *s = new Sword(itemName);
		s->GenerateStats(Suffixes::suffixes);
		Interface(*s); // Check!
		std::cout << "Stash?: Y/N\n";
		std::cin >> input;
		char i = std::tolower(input);
		switch (i) {
			case 'y': c.itemStash->push_back(*s); break;
			case 'n': delete s; RollItem(); break;
		}
	}
	else if (choice == 1) {
		std::array<std::string, 5> itemName = GenerateName('b');
		Boots *b = new Boots(itemName);
		b->GenerateStats(Suffixes::suffixes);
		Interface(*b);
		std::cout << "Stash?: Y/N\n";
		std::cin >> input;
		char i = std::tolower(input);
		switch (i) {
			case 'y': c.itemStash->push_back(*b); break;
			case 'n': delete b; RollItem(); break;
		}
	}
	else if (choice == 2) {
		std::array<std::string, 5> itemName = GenerateName('r');
		Ring *r = new Ring(itemName);
		r->GenerateStats(Suffixes::suffixes);
		Interface(*r);
		std::cout << "Stash?: Y/N\n";
		std::cin >> input;
		char i = std::tolower(input);
		switch (i) {
			case 'y': c.itemStash->push_back(*r); break;
			case 'n': delete r; RollItem(); break;
		}
	}
}

// Do mouse picking when SFML is added
void Craft() {
	int choice = 0;
	Item *curItem;
	c.GetItemStash();
	// Pick item
	std::cin >> choice;
	c.itemStash[choice];
	c.GetCraftingStash(window);
	// Pick crafting materials
	std::cin >> choice;
	c.materialsStash[choice];
}

void Interface(Item &i) { // Add SFML here
	int choice = 0;
	while (window.isOpen()) {
		window.clear();
		while (window.pollEvent(event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
				RollItem();
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
				Craft();
			// Get mouse picking
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				// Check if hitting crafting item
				if (sf::Mouse::getPosition().x == c.materialsStash[0].GetPosX() && sf::Mouse::getPosition().y == c.materialsStash[0].GetPosY()) // +/-
					std::cout << "HIT\n";
				else if (sf::Mouse::getPosition().x == c.materialsStash[1].GetPosX() && sf::Mouse::getPosition().y == c.materialsStash[1].GetPosY())
					std::cout << "HIT2\n";
			}
		}
		c.PrintStats(window);
		i.Draw(window);
		window.display();
	}
}

int main() {
	srand(time(0));
	std::array<std::string, 5> defaultName{"", "", "Default Item", "", ""};
	Item defaultItem(defaultName);
	Interface(defaultItem);

	return 0;
}