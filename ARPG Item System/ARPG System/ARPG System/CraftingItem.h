#ifndef CraftingItem_h
#define CraftingItem_h

#include <iostream>
#include "Item.h"

class CraftingItem {
private:
public:
	const std::string itemName = "Default";
	const std::string itemDescription = "";
	CraftingItem() {}
	~CraftingItem() = default;

	virtual void Use(Item *i) {
		
	}
};

class AgonyOrb : public CraftingItem { // Totally randomises an item
private:
public:
	AgonyOrb() {}
	~AgonyOrb() = default;
	void Use(Item *i);
};

class PerfectionOrb : public CraftingItem { // Upgrades an item by one tier
private:
public:
	PerfectionOrb() {}
	~PerfectionOrb() = default;
	void Use(Item *i);
};

#endif