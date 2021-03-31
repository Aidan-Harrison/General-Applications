#ifndef Player_h
#define Player_h

#include <vector>
#include "Hero.h"
#include "Item.h"

struct Player {
	enum team {DIRE = 1, RADIANT}; // Pointless!?
	int teamID = 0;
	std::string currentTeam = " ";
	char choice = ' ';
	Hero *currentHero;
	std::vector<Hero> teamMembers;
	Player() = default;
	Player(int team)
	{
	}
	~Player() = default;
};

#endif