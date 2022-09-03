#ifndef CraftingItem_h
#define CraftingItem_h

#include <iostream>

// Improve construction
// Value/currency system??
    // If so add to mutations as an option

struct CraftingItem {
    int type;
    std::string itemName = "";

    CraftingItem() {}
    virtual ~CraftingItem() {} // Check!
};

// Corrupts the item, preventing it from being crafted any further but
// applies a unique set of extremely powerful modifiers to the item
struct AgonyOrb : public CraftingItem {
    AgonyOrb() 
    {
        type = 0;
        itemName = "Agony Orb";
    }
    ~AgonyOrb() {}
};

// Rolls a random stat to the highest tier if not already at the highest
struct DivineOrb : public CraftingItem {
    DivineOrb() 
    {
        type = 1;
        itemName = "Divine Orb";
    }
    ~DivineOrb() {}
};

// Randomises everything (Excluding Implicits)
struct LamentGem : public CraftingItem {
    LamentGem() 
    {
        type = 2;
        itemName = "Lament Gem";
    }
    ~LamentGem() {}
};

// Turns an item into a different base of the same type
// e.g. Swords can only turn into other swords
struct MoltenCore : public CraftingItem {
    MoltenCore() 
    {
        type = 3;
        itemName = "Molten Core";
    }
    ~MoltenCore() {}
};

// Takes an existing stat and duplicates it, overwriting another stat and re-rolling its value
// Favouring a higher tier
struct Mirror : public CraftingItem {
    Mirror()
    {
        type = 4;
        itemName = "Mirror";
    }
    ~Mirror() {}
};

// If common, magic or rare, add an extra item slot
struct ExtensionOrb : public CraftingItem {
    ExtensionOrb() 
    {
        type = 5;
        itemName = "Extension Orb";
    }
    ~ExtensionOrb() {}
};

#endif