#include "Interface.h"

void Interface::Update(int sWidth, int sHeight, Animal& a) {
	rect.setSize(sf::Vector2f((float)sWidth / 3, (float)sHeight));
	rect.setOrigin(0.0f, 0.0f);
	rect.setPosition(0.0f, 0.0f);
	rect.setFillColor(sf::Color(105,105,105,255));

	stats[0].setString(a.name);
	stats[1].setString(std::to_string(a.health));

	for (auto i : stats) {
		i.setPosition(rect.getPosition().x + 100.0f, yOffset+=30.0f);
	}
}

void Interface::Draw(sf::RenderWindow& window) {
	window.draw(rect);
	for (auto i : stats)
		window.draw(i);
}