#ifndef Map_h
#define Map_h

#include <vector>

#include "Base.h"
#include "Tower.h"
#include "Hero.h"
#include "Item.h"

// Ineffcient, should only create objects when necessary!
//namespace NeutralItems {
	//Item RoyalJelly{"Royal Jelly", 0, "Gives you permenant HP and Mana regen", true, "Apply to another teamate", false};
//}

//std::vector<Item> neutralItems{NeutralItems::RoyalJelly}; // Remove once map(hash table) is solved, shouldn't be in global

// Singleton | Fix!
struct Map {
	short seconds = 0, minutes = 0, tickRate = 1000;
	int m_Test = 0;
	bool m_RoshUp = true, isNight = true; // Remove from nightStalker??
	std::vector<Hero> radiantTeam{}, direTeam{};
	Tower *towers[24]; // Heap allocate
	Base *bases[2];
	Map() = default;
	Map(int test)
		:m_Test(test)
	{
	}
	~Map() = default;
	void MapSetup(); // Run on object creation
	void GetTime();
};

#endif