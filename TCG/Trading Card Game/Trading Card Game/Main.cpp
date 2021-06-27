#include <iostream>
#include <SFML/Graphics.hpp>

#include "Card.h"
#include "Deck.h"
#include "Board.h"

namespace Parameters {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Trading Card Game");
}

using namespace Parameters;

int main() {
	window.setFramerateLimit(60);

	sf::RectangleShape deckRect;
	deckRect.setSize(sf::Vector2f(1.0f,1.0f));
	deckRect.setPosition(sf::Vector2f(25.0f,25.0f));
	Card testCard;
	Deck testDeck;
	// Board testBoard;

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				// Deck
				for (int i = 0; i < 25; i++) { // Get card/deck size
					if (sf::Mouse::getPosition().x == deckRect.getPosition().x + i || sf::Mouse::getPosition().x == deckRect.getPosition().x - i)
						putchar('a');
					if (sf::Mouse::getPosition().y == deckRect.getPosition().y + i || sf::Mouse::getPosition().y == deckRect.getPosition().y - i)
						putchar('a');
				}
				// Hand


				// Cards


				testCard.SetPos(sf::Mouse::getPosition(window));
				if (sf::Mouse::getPosition(window) == sf::Vector2i(25, 25))
					std::cout << "DRAW!\n";
			}
			else {
				testCard.SetPos(sf::Vector2i(200, 800));
			}
			// Camera movement | Shift EVERYTHING

		}

		window.clear();
		testCard.Draw(window);
		// testBoard.DrawBoard(window);
		window.draw(deckRect);
		window.display();
	}

	return 0;
}