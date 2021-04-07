#ifndef Item_h
#define Item_h

#include <iostream>
#include <cassert>

class Item {
private:
public:
	enum type {STRENGTH, AGILITY, INTELLIGENCE};
	const std::string m_ItemName = " ", m_ToolTip = " ", m_ActiveName = " ", m_ActiveTooltip = " ";
	int m_Cost = 0, m_itemID = 0; // Automatically change ID??? Do so in vector
	bool canBeSold = true, m_isActive = false, m_IsNeutral = false;
	Item() = default;
	Item(const char* name, int cost = 300, const char* toolTip =  " ", bool isActive = false, const char* activeName = " ", const char* activeDesc = " ", bool isNeutral = false)
		:m_ItemName(name), m_Cost(cost), m_ToolTip(toolTip), m_isActive(isActive), m_ActiveName(activeName), m_ActiveTooltip(activeDesc), m_IsNeutral(isNeutral)
	{
		// assert(m_Name != " " && m_Cost != 0); // Check!, both failing
	}
	~Item() = default;
	std::string GetName() const { return m_ItemName; }
	void DeleteItem() { delete this; } // Check!
};

struct ObserverWard : Item {
	int m_VisionRange = 1500;
	static int amountOnTeam; // Set amount of wards per team
};

struct PostHaste : Item { // Do constructor
	bool canTeleport = true;
	float coolDown = 30.0f;
};

class NeutralItem {
private:
public:
};

#endif