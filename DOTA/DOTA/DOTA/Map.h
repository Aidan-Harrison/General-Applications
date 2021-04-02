#ifndef Map_h
#define Map_h

#include <vector>

#include "Base.h"
#include "Tower.h"
#include "Hero.h"
#include "Item.h"

namespace NeutralItems {
	Item RoyalJelly{"Royal Jelly", 0, "Gives you permenant HP and Mana regen", true, "Apply to another teamate", false};
	std::vector<Item> neutralItems{RoyalJelly};
}

// Singleton
class Map {
private:
	Map();
public:
	short seconds = 0, minutes = 0, tickRate = 0;
	bool m_RoshUp = false, isNight = true; // Remove from nightStalker??
	std::vector<Hero> radiantTeam{}, direTeam{};
	Tower towers[24];
	Base bases[2];
	void GetTime() {
		if(minutes % 5 == 0)
			if(!isNight)
				isNight = true;
			else
				isNight = false;
		switch(isNight) {
			case false: std::cout << "It is currently DAY\n"; break;
			case true: std::cout << "It is currently NIGHT\n"; break;
		} 
	}
	~Map() = default;
	void MapSetup(); // Run on object creation
};

#endif