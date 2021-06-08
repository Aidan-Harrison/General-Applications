#ifndef Item_h
#define Item_h

#include <iostream>
#include <cassert>

// ADD HEROES WITHOUT BREAKING PROGRAM

class Item {
private:
	int m_Cost = 0, m_itemID = 0; // Automatically change ID??? Do so in vector
	const std::string m_ItemName = " ", m_ToolTip = " ", m_ActiveName = " ", m_ActiveTooltip = " ";
	int m_Strength = 0, m_Agility = 0, m_Intelligence = 0;
	int m_Damage = 0;
public:
	enum type {STRENGTH, AGILITY, INTELLIGENCE};
	bool canBeSold = true, m_isActive = false, m_IsNeutral = false;
	int cooldown = 10; // Appiles to both active and passive
	Item() = default;
	Item(const char* name, int cost = 300, const char* toolTip =  " ", bool isActive = false, const char* activeName = " ", const char* activeDesc = " ", bool isNeutral = false)
		:m_ItemName(name), m_Cost(cost), m_ToolTip(toolTip), m_isActive(isActive), m_ActiveName(activeName), m_ActiveTooltip(activeDesc), m_IsNeutral(isNeutral)
	{
		// assert(m_Name != " " && m_Cost != 0); // Check!, both failing
	}
	~Item() = default;
	// Main
	std::string GetName() const { return m_ItemName; }
	int GetCost() const { return m_Cost; }
	int GetID() const { return m_itemID; }
	void SetID(int id) { m_itemID = id; }
	void DeleteItem() { delete this; }
	// General
	int GetStrength()     const { return m_Strength; }
	int GetAgility()      const { return m_Agility; }
	int GetIntelligence() const { return m_Intelligence; }
	int GetDamage()	    const { return m_Damage; }
	virtual void Active() {};
};

// Active items ========================
struct ObserverWard : public Item { // Remove?
	ObserverWard()
		:Item("Observer Ward")
	{
	}
	int m_VisionRange = 1500;
	static int amountOnTeam; // Clamp amount of wards per team
	void Active() {
		// Make jungle and or lane visible (Intergrate vision | Sawp to ray-casting when graphics are added!)
	}
	~ObserverWard() {};
};

struct RevalationWard : public Item {
	RevalationWard()
		:Item("Revalation Ward")
	{
	}
	int m_VisionRange = 1500;
	static int amountOnTeam; // Clamp amount of wards per team
	void Active() {

	}
	~RevalationWard() {};
};

struct Basher : public Item {
	Basher()
		:Item("Basher")
	{
	}
	void Bash(); // ?
	~Basher() {};
};

struct BKB : public Item { // Black King Bar
	BKB()
		:Item("Black King Bar")
	{
	}
	//void Active() {
		//h->m_SpellImune = true;
	//}
	~BKB() {};
};

struct RefresherOrb : public Item {
	RefresherOrb()
		:Item("Refresher Orb")
	{
	}
	void Active() {
		// Refresh cooldowns (Abilities only)
	}
	~RefresherOrb() {};
};

struct ShadowBlade : public Item {
	ShadowBlade()
		:Item("Shadow Blade")
	{
	}
	//void Active() {
		//if(!h->m_Invis)
			//h->m_Invis = true;
	//}
	~ShadowBlade() {};
};

struct Midas : public Item {
	Midas()
		:Item("Midas")
	{
	}
	~Midas() {};
	/*
	void Active(JungleCreep &j) { // Check! | Do printing!
		j.m_Health = 0;
		j.isDead = true;
		h->gold += j.m_Health / 2;
	}
	*/
};

// Neutral Items ========================
struct RoyalJelly : public Item {
	RoyalJelly()
		:Item("Royal Jelly")
	{
		m_IsNeutral = true;
	}
	//void Active() {
		//h->m_HealthRegen += 2.5;
		//h->m_ManaRegen += 1.5;
	//}
	~RoyalJelly() {};
};

struct LifeRing : public Item {
	LifeRing() 
		:Item("Life Ring")
	{
		m_IsNeutral = true;
	}
	//void Active() { // Do cooldown!
		//h->m_Health += 400;
	//}
	~LifeRing() {};
};

#endif