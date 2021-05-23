#ifndef Player_h
#define Player_h

#include <iostream>
#include "Deck.h"

class Player {
private:
	std::string name = "";
public:
	std::vector<Card> hand{}; // Do vector wrapper
	Player(const std::string &pName)
		:name(pName)
	{
	}
	~Player() = default;
};

#endif