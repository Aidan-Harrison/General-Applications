#include <fstream>
#include <ctime>
#include <cctype>
#include <thread>
#include <string>

#include "Character.h"
#include "Generator.h"

#include <SFML/Graphics.hpp>

Character c("TestCharacter", 5);
short screenWidth = 800, screenHeight = 600;
sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "ARPG Crafting System");
sf::Event event;

void Interface(Item& i);

std::string GenerateName(char t) {
	int choice = 0;
	std::string name = "";
	if (t == 's') {
		choice = rand() % 5;
		if (choice > 3) {
			choice = rand() % SwordPrefixNames::prefixes.size();
			name.append(SwordPrefixNames::prefixes[choice]);
			name.append(" ");
		}
		choice = rand() % SwordBaseNames::bases.size();
		name.append(SwordBaseNames::bases[choice]);
	}
	else if (t == 'b') {
		choice = rand() % 5;
		if (choice > 3) {
			choice = rand() % BootsPrefixNames::prefixes.size();
			name.append(BootsPrefixNames::prefixes[choice]);
			name.append(" ");
		}
		choice = rand() % BootsBaseNames::bases.size();
		name.append(BootsBaseNames::bases[choice]);
	}
	else if(t == 'r') {
		choice = rand() % 5;
		if (choice > 3) {
			choice = rand() % RingPrefixNames::prefixes.size();
			name.append(RingPrefixNames::prefixes[choice]);
			name.append(" ");
		}
		choice = rand() % RingBaseNames::bases.size();
		name.append(RingBaseNames::bases[choice]);
	}
	// Suffix generation
	name.append(" ");
	choice = rand() % 5;
	if (choice > 3) {
		choice = rand() % SuffixNames::suffixes.size();
		name.append(SuffixNames::suffixes[choice]);
	}
	return name;
}

void RollItem() { // Optimise input/confirm section!!??
	system("cls");
	int choice = 0;
	char input = 0;
	choice = rand() % 3;
	if (choice == 0) {
		Sword s(GenerateName('s'));
		// s.PrintItem(window);
		Interface(s);
		std::cout << "Stash?: Y/N\n";
		std::cin >> input;
		std::tolower(input);
		switch (input) {
			case 'y': c.itemStash->push_back(s); break;
			case 'n': RollItem();
		}
	}
	else if (choice == 1) {
		Boots b(GenerateName('s'));
		Interface(b);
		std::cout << "Stash?: Y/N\n";
		std::cin >> input;
		std::tolower(input);
		switch (input) {
			case 'y': c.itemStash->push_back(b); break;
			case 'n': RollItem();
		}
	}
	else if (choice == 2) {
		Ring r(GenerateName('r'));
		// r.PrintItem(window);
		Interface(r);
		std::cout << "Stash?: Y/N\n";
		std::cin >> input;
		std::tolower(input);
		switch (input) {
			case 'y': c.itemStash->push_back(r); break;
			case 'n': RollItem();
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
	c.GetCraftingStash();
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
		}
		c.PrintStats(window);
		i.PrintItem(window);
		window.display();
	}
}

int main() {
	srand(time(0));
	Item defaultItem("Default Item");
	Interface(defaultItem);

	return 0;
}