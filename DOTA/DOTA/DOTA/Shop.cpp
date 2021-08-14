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

// Do Neutrals in another vector?

std::map<int,Item> items; // Push items to map, search via key | Avoid pushing in the first place, direct insert into map!!!!!!
void ShopSetup() { // Run initially
	for(unsigned int i = 0; i < itemList.size(); i++) {
		items.insert (std::pair<int, Item>(i, itemList[i]) ); // Check!
	}
	// Item ID's
	for(unsigned int i = 0; i < itemList.size(); i++) {
		itemList[i].SetID(i);
	}
}


void Search() { // Use map instead
	std::string search;
	std::cout << "Search: "; std::cin >> search; // Only shows items which contain said characters
	for (unsigned int i = 0; i < itemList.size(); i++) {
		if (items[i].GetName() == search)
			std::cout << "Item: " << items[i].GetName() << '\n'; // Properly remove already printed elements and replace
	}
	// Add purchase
}

void Purchase(Player &p, const int id) {
	// Do hash table ID search, check against player gold and inventory/backpack
	for (unsigned int i = 0; i < itemList.size(); i++) {
		if (id == itemList[i].GetID()) {
			if(p.currentHero->gold < itemList[i].GetCost()) {
				std::cout << "You cannot afford that item!\n";
				ShopInterface(p);
			}
			// Check inventory size
			else {
				std::cout << "You purchased: " << itemList[i].GetName();
			}
		}
	}
	std::cin.get();
	std::cin.get();
	ShopInterface(p);
}

// Convert this to a for loop, modify inventory to allow!!!!!!!!!!!!!!!!!!!!!!!!!! | Scale cost?
void Sell(Player &p) {
	if (p.currentHero->m_Inventory.empty()) { // Check!
		std::cout << "You have nothing to sell, returning...";
		std::this_thread::sleep_for(std::chrono::seconds(3));
		ShopInterface(p);
	}
	int choice = 0;
	std::cout << "Sell from I) Inventory/Backpack  S) Stash\n";
	std::cin >> choice;
	std::cout << "Choose an item to sell!\n";
	if (choice == 'i') {
		p.currentHero->PrintInventory();
		while (1) {
			std::cin >> choice;
			if (choice > 9) {
				std::cout << "You must pick a value between 1-9!\n";
			}
			else if (choice == 1) {
				p.currentHero->m_Inventory[choice]->DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Inventory[choice]->GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 2) {
				p.currentHero->m_Inventory[choice]->DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Inventory[choice]->GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 3) {
				p.currentHero->m_Inventory[choice]->DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Inventory[choice]->GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 4) {
				p.currentHero->m_Inventory[choice]->DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Inventory[choice]->GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 5) {
				p.currentHero->m_Inventory[choice]->DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Inventory[choice]->GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 6) {
				p.currentHero->m_Inventory[choice]->DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Inventory[choice]->GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 7) {
				p.currentHero->m_Inventory[choice]->DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Inventory[choice]->GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 8) {
				p.currentHero->m_Inventory[choice]->DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Inventory[choice]->GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 9) {
				p.currentHero->m_Inventory[choice]->DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Inventory[choice]->GetCost() * p.currentHero->level / 2;
			}
		}
	}
	else if (choice == 2) {
		p.currentHero->PrintStash();
		while (1) {
			std::cin >> choice;
			if (choice > 8) {
				std::cout << "You must pick a value between 1-9!\n";
			}
			else if (choice == 1) {
				p.currentHero->m_Stash[choice].DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Stash[choice].GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 2) {
				p.currentHero->m_Stash[choice].DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Stash[choice].GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 3) {
				p.currentHero->m_Stash[choice].DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Stash[choice].GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 4) {
				p.currentHero->m_Stash[choice].DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Stash[choice].GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 5) {
				p.currentHero->m_Stash[choice].DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Stash[choice].GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 6) {
				p.currentHero->m_Stash[choice].DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Stash[choice].GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 7) {
				p.currentHero->m_Stash[choice].DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Stash[choice].GetCost() * p.currentHero->level / 2;
			}
			else if (choice == 8) {
				p.currentHero->m_Stash[choice].DeleteItem(); // Check!!!
				p.currentHero->gold += p.currentHero->m_Stash[choice].GetCost() * p.currentHero->level / 2;
			}
		}
	}
	ShopInterface(p);
}

void ShopInterface(Player &p) {
	std::cout << "===SHOP==="; // Use loops instead
	p.currentHero->PrintStats();
	std::cout << "\n\nWards:============\n";
		std::cout << Shop::observerWard.GetName();
		std::cout << Shop::revalationWard.GetName();
	std::cout << "Movement Items:============\n";
		std::cout << Shop::boots.GetName();
		std::cout << Shop::phaseBoots.GetName();
	std::cout << "Neutral Items:============\n";
		//std::cout << NeutralItems::RoyalJelly.m_ItemName;
		// std::cout << NeutralItems::PaladinsSword.m_ItemName;
	std::cout << "Extra:\n";
		std::cout << Shop::tomeOfKnowledge.GetName();

	std::cout << "\nS) Search  P) Purchase  X) Sell  B) Exit\n";
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
	else if (p.choice == 's') {
		Sell(p);
	}
	else if (p.choice == 'b') {
		return; // Do exit back to main game
	}
}

