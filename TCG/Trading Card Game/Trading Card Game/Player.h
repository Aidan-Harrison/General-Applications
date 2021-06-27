#ifndef Player_h
#define Player_h

#include "Deck.h"

class Player {
private:
	std::string name = "";
public:
	Deck deck; // Should be heap allocated 
	std::array<Card,7> hand; // Change to pointer?

	Player(const std::string &pName)
		:name(pName)
	{
	}

	void DrawCard();
	void DrawHand(sf::RenderWindow& window);
	void Redraw(sf::RenderWindow& window); // Scraps current hand and draws a new one, with one less total

	~Player() {};
};

#endif