#include <iostream>
#include <map>
#include <cctype>
#include "Hero.h"
#include "Item.h"
#include "Player.h"
#include "Map.h"
// #include "NeutralItems.h"

void Game(Player &p, Map &m);
void ShopInterface(Player &p);

// Only create when purchased!!!!!!!!!!!!!!!
namespace Shop {
	// Basic ============================================
	Item observerWard{"Observer Ward", 75, "Reveals an area in a given range (Affected by time of day!)", true, "Place Ward", "Places a ward at the target location", false};
	Item revalationWard{"Revalation Ward", 75, "Reveals other wards + invisible heroes in a given range (Affected by time of day!)", true, "Place Ward", "Places a ward at the target location", false};
	// Boots ============================================
	Item boots{ "Boots",350,"Increases movement speed",false};
	Item phaseBoots{ "Phase Boots",1500,"Increases movement speed (Active to move faster)",true, "Active boots", "Greatly increases movement speed", false};
	// Main ============================================
	Item mantaStyle{ "Manta Style", 2750, "Allows you to spawn clones", true, "Summon Clones", "Summon two copies of yourself", false};
	Item blinkDagger{ "Blink Dagger", 2500, "Allows you to blink to a location", true, "Blink", "Teleports character to the target location", false};
	// Extra
	Item tomeOfKnowledge{ "Tome of Knowledge", 750, "Grants you and your team XP", true, "Give XP", "Gives yourself and teamates XP", false };
}

std::vector<Item> itemList = { // Remove once map(hash table) is solved | Shouldn't be in global
		// Basic
	Shop::observerWard, 
	Shop::revalationWard, // Get colours/Intellisense on namespaces
		// Movement
	Shop::boots,
	Shop::phaseBoots,
		// Main
	Shop::mantaStyle,
	Shop::blinkDagger,
		// Extra
	Shop::tomeOfKnowledge
};

std::map<short,Item> items; // Push items to map, search via key | Avoid pushing in the first place, direct insert into map!!!!!!
void ShopSetup() { // Run initially
	for(unsigned int i = 0; i < itemList.size(); i++) {
		items.insert (std::pair<short, Item>(i, itemList[i]) ); // Check!
	}
	// Item ID's
	for(unsigned int i = 0; i < itemList.size(); i++) {
		itemList[i].m_itemID = i;
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

void Purchase(Player &p, const int id) {
	// Do hash table ID search, check against player gold and inventory/backpack
	for (unsigned int i = 0; i < itemList.size(); i++) {
		if (id == itemList[i].m_itemID) {
			if(p.currentHero->gold - itemList[i].m_Cost <= 0 || p.currentHero->gold < itemList[i].m_Cost) {
				std::cout << "You cannot afford that item!\n";
				ShopInterface(p);
			}
			// Check inventory size
			else {
				std::cout << "You purchased: " << itemList[i].m_ItemName;
			}
		}
	}
	ShopInterface(p);
}

// Convert this to a for loop, modify inventory to allow!!!!!!!!!!!!!!!!!!!!!!!!!! | Also implement Stash
void Sell(Player &p) {
	short choice = 0;
	std::cout << "Sell from Inventory/Backpack or Stash\n";
	std::cin >> choice;
	std::cout << "Choose an item to sell!\n";
	p.currentHero->PrintInventory();
	std::cin >> choice;
	if(choice > 9) {
		std::cout << "You must pick a value between 1-9!\n"; // Avoid using goto statement
	}
	else if (choice == 1) {
		p.currentHero->m_Inventory[choice].DeleteItem(); // Check!!!
		p.currentHero->gold += p.currentHero->m_Inventory[choice].m_Cost / 2;
	}
	else if (choice == 2) {
		p.currentHero->m_Inventory[choice].DeleteItem(); // Check!!!
		p.currentHero->gold += p.currentHero->m_Inventory[choice].m_Cost / 2;
	}
	else if (choice == 3) {
		p.currentHero->m_Inventory[choice].DeleteItem(); // Check!!!
		p.currentHero->gold += p.currentHero->m_Inventory[choice].m_Cost / 2;
	}
	else if (choice == 4) {
		p.currentHero->m_Inventory[choice].DeleteItem(); // Check!!!
		p.currentHero->gold += p.currentHero->m_Inventory[choice].m_Cost / 2;
	}
	else if (choice == 5) {
		p.currentHero->m_Inventory[choice].DeleteItem(); // Check!!!
		p.currentHero->gold += p.currentHero->m_Inventory[choice].m_Cost / 2;
	}
	else if (choice == 6) {
		p.currentHero->m_Inventory[choice].DeleteItem(); // Check!!!
		p.currentHero->gold += p.currentHero->m_Inventory[choice].m_Cost / 2;
	}
	else if (choice == 7) {
		p.currentHero->m_Backpack[choice].DeleteItem(); // Check!!!
		p.currentHero->gold += p.currentHero->m_Inventory[choice].m_Cost / 2;
	}
	else if (choice == 8) {
		p.currentHero->m_Backpack[choice].DeleteItem(); // Check!!!
		p.currentHero->gold += p.currentHero->m_Inventory[choice].m_Cost / 2;
	}
	else if (choice == 9) {
		p.currentHero->m_Backpack[choice].DeleteItem(); // Check!!!
		p.currentHero->gold += p.currentHero->m_Inventory[choice].m_Cost / 2;
	}
	ShopInterface(p);
}

void ShopInterface(Player &p) { // Give user choice to back out whenever
	std::cout << "===SHOP===\n"; // Use loops instead
	std::cout << "Wards:============\n";
		std::cout << Shop::observerWard.m_ItemName;
		std::cout << Shop::revalationWard.m_ItemName;
	std::cout << "Movement Items:============\n";
		std::cout << Shop::boots.m_ItemName;
		std::cout << Shop::phaseBoots.m_ItemName;
	std::cout << "Neutral Items:============\n";
		//std::cout << NeutralItems::RoyalJelly.m_ItemName;
		// std::cout << NeutralItems::PaladinsSword.m_ItemName;
	std::cout << "Extra:\n";
		std::cout << Shop::tomeOfKnowledge.m_ItemName;

	std::cout << "\nS) Search  P) Purchase  B) Exit\n";
	std::cin >> p.choice;
	std::tolower(p.choice);
	if (p.choice == 's')
		Search();
	else if (p.choice == 'p') {
		int itemID = 0;
		std::cout << "Enter item ID!\n";
		std::cin >> itemID;
		Purchase(p, itemID);
	}
	else if (p.choice == 'b') {
		return; // Do exit back to main game
	}
}