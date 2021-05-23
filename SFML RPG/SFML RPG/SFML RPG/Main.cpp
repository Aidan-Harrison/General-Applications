#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"

Player p;

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "RPG");

	while (window.isOpen()) {
		
		p.Move(window);

		window.clear();
		window.draw(p.body);
		p.DrawUI(window);
		window.display();
	}

	return 0;
}