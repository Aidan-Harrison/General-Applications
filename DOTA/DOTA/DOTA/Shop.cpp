#include <iostream>
#include <map>
#include <cctype>
#include "Hero.h"
#include "Item.h"
#include "Player.h"
#include "Map.h"

void Game(Player &p, Map &m);

namespace Shop {
	// Basic ============================================
	Item observerWard{"Observer Ward", 75, "Reveals an area in a given range (Affected by time of day!)", true, "Place Ward", "Places a ward at the target location" };
	Item revalationWard{"Revalation Ward", 75, "Reveals other wards + invisible heroes in a given range (Affected by time of day!)", true, "Place Ward", "Places a ward at the target location"};
	// Boots ============================================
	Item boots{ "Boots",350,"Increases movement speed",false};
	// Main ============================================
	Item mantaStyle{ "Manta Style", 2750, "Allows you to spawn clones", true, "Summon Clones", "Summon two copies of yourself"};
	Item blinkDagger{ "Blink Dagger", 2500, "Allows you to blink to a location", true, "Blink", "Teleports character to the target location"};
}

std::vector<Item> itemList = { // Remove once map is solved
		// Basic
	Shop::observerWard, 
	Shop::revalationWard, // Get colours/Intellisense on namespaces
		// Movement
	Shop::boots,
		// Main
	Shop::mantaStyle,
	Shop::blinkDagger
};

std::map<short,Item> items; // Push items to map, search via key | Avoid pushing in the first place, direct insert into map!!!!!!
void ShopSetup() { // Run initially
	for(short i = 0; i < itemList.size(); i++) {
		items.insert (std::pair<short, Item>(i, itemList[i]) ); // Check!
	}
}


void Search() { // Use map instead
	std::string search;
	std::cout << "Search: "; std::cin >> search; // Only shows items which contain said characters
	for (unsigned int i = 0; i < itemList.size(); i++) {
		if (items[i].m_ItemName == search)
			std::cout << "Item: " << items[i].m_ItemName << '\n'; // Properly remove already printed elements and replace
	}
	// Add purchase
}

void ShopInterface(Player &p) { // Give user choice to back out whenever
	char choice = ' ';
	std::cout << "===SHOP===\n";
	std::cout << "Wards:============\n";
	std::cout << "Movement Items:============\n";
	std::cout << "Extra:\n";
	std::cout << "S) Search  P) Purchase  B) Exit\n";
	std::cin >> choice;
	std::tolower(choice);
	if (choice == 's')
		Search();
	else if (choice == 'p') {
		return;
	}
	else if (choice == 'b') {
		return; // Do exit back to main game
	}
}