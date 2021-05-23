#ifndef Deck_h
#define Deck_h

#include <iostream>
#include <array>
#include "Card.h"

class Deck {
private:
	std::string deckName = "";
public:
	Deck(const std::string &name = "Default")
		:deckName(name)
	{
	}
	std::array<Card, 40> deck{};

	std::string GetName() const { return deckName; }
	void DrawCard(); // Check, maybe vector with wrapper?

	~Deck() = default;
};


#endif