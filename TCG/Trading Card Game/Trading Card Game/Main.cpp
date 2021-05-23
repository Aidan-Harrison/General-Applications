#include <iostream>
#include <SFML/Graphics.hpp>

#include "Card.h"
#include "Deck.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Trading Card Game");
	sf::RectangleShape deckRect;
	deckRect.setSize(sf::Vector2f(1.0f,1.0f));
	deckRect.setPosition(sf::Vector2f(25.0f,25.0f));
	Card testCard{};
	Deck testDeck{};

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				testCard.SetPos(sf::Mouse::getPosition(window));
				if (sf::Mouse::getPosition(window) == sf::Vector2i(25, 25))
					std::cout << "DRAW!\n";
			}
			else {
				testCard.SetPos(sf::Vector2i(200, 800));
			}
			// Camera movement
		}

		window.clear();
		testCard.Draw(window);
		window.draw(deckRect);
		window.display();
	}

	return 0;
}