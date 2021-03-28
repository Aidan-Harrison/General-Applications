#ifndef Item_h
#define Item_h

#include <iostream>
#include <cassert>

class Item {
private:
public:
	enum type {STRENGTH, AGILITY, INTELLIGENCE};
	const std::string m_ItemName = " ", m_ToolTip = " ";
	int m_Cost = 0;
	bool canBeSold = true;
	Item() = default;
	Item(const char* name, int cost, std::string toolTip)
		:m_ItemName(name), m_Cost(cost), m_ToolTip(toolTip)
	{
		assert(m_ItemName != " " && m_Cost != 0);
	}
	~Item() = default;
	std::string GetName() const { return m_ItemName; }
	void DeleteItem(Item item) { delete &item; } // Check!
};

struct ObserverWard : Item {
	int m_VisionRange = 1500;
	static int amountOnTeam; // Set amount of wards per team
};

struct PostHaste : Item { // Do constructor
	bool canTeleport = true;
	float coolDown = 30.0f;
};

#endif Item_h