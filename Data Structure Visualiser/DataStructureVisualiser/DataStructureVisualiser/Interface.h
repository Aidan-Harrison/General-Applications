#ifndef Interface_h
#define Interface_h

#include <SFML/Graphics.hpp>

struct Interface {
	sf::RectangleShape rect;

	Interface(const int screenWidth, const int screenHeight) 
	{
		rect.setFillColor(sf::Color(105,105,105,255));
		rect.setSize(sf::Vector2f((float)screenWidth, (float)screenHeight));
		rect.setOrigin(sf::Vector2f((float)screenWidth / 2, (float)screenHeight));
		rect.setPosition(0.0f, 0.0f);
	}

	void Draw(sf::RenderWindow &window);

	~Interface() {}
};

void Interface::Draw(sf::RenderWindow& window) {
	window.draw(rect);
}

#endif
