#ifndef Deck_h
#define Deck_h

#include <array>
#include "Card.h"

class Deck {
private:
	std::string deckName = "";
	sf::Vector2i pos;
public:
	std::array<Card, 40> *deck = new std::array<Card, 40>;
	Deck(const std::string &name = "Default Deck")
		:deckName(name)
	{
		pos.x = 50;
		pos.y = 50;
	}

	std::string GetName() const { return deckName; }

	void DrawDeck(sf::RenderWindow &window);
	void ShuffleDeck();

	~Deck() {};
};


#endif