#ifndef Player_h
#define Player_h

#include <vector>
#include "Hero.h"
#include "Item.h"

struct Player {
	int teamID = 0, creepsKilled = 0;
	short chanceToAttack = 0;
	bool fighting = false;
	std::string currentTeam = " ";
	char choice = ' ';
	Hero *currentHero; // Initialise!
	std::vector<Hero> teamMembers;
	Player() = default;
	Player(int team = 1) // Do initialisation!
	{
	}
	~Player() = default;
};

#endif