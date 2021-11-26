#ifndef CraftingItem_h
#define CraftingItem_h

#include <iostream>

// Improve construction
// Value/currency system??
    // If so add to mutations as an option

struct CraftingItem {
    std::string itemName = "";
    
    CraftingItem() {}
    virtual ~CraftingItem() {} // Check!
};

// Corrupts the item, preventing it from being corrupted, but
// applies a unique set of extremely powerful modifiers to the item
struct AgonyOrb : public CraftingItem {
    AgonyOrb(const std::string &name) 
    {
        itemName = name;
    }
    ~AgonyOrb() {}
};

// Rolls a random stat to the highest tier if not already at the highest
struct DivineOrb : public CraftingItem {
    DivineOrb(const std::string &name) 
    {
        itemName = name;
    }
    ~DivineOrb() {}
};

// Randomises everything (Excluding Implicits)
struct LamentGem : public CraftingItem {
    LamentGem(const std::string &name) 
    {
        itemName = name;
    }
    ~LamentGem() {}
};

// Turns an item into a different base of the same type
// e.g. Swords can only turn into other swords
struct MoltenCore : public CraftingItem {
    MoltenCore(const std::string &name) 
    {
        itemName = name;
    }
    ~MoltenCore() {}
};

// Takes an existing stat and duplicates it, overwriting another stat and re-rolling its value
struct Mirror : public CraftingItem {
    Mirror(const std::string &name)
    {
        itemName = name;
    }
    ~Mirror() {}
};

// If common, magic or rare, add an extra item slot
struct ExtensionOrb : public CraftingItem {
    ExtensionOrb(const std::string &name) 
    {
        itemName = name;
    }
    ~ExtensionOrb() {}
};

#endif