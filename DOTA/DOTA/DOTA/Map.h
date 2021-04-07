#ifndef Map_h
#define Map_h

#include <vector>

#include "Base.h"
#include "Tower.h"
#include "Hero.h"
#include "Item.h"

// Singleton | Fix!
struct Map {
	short seconds = 0, minutes = 0, tickRate = 1000;
	int m_Test = 0;
	bool m_RoshUp = true, isNight = true; // Remove from nightStalker??
	std::vector<Hero> radiantTeam{}, direTeam{};
	// Tower *towers[24]; // Heap allocate
	Base *bases[2];
	Map() {
		Base aBase{"Ancient", 5000};
		Base dBase{"Dire", 5000};
		bases[0] = &aBase;
		bases[1] = &dBase;
	}
	~Map() = default;
	void MapSetup(); // Run on object creation
	void GetTime();
};

#endif