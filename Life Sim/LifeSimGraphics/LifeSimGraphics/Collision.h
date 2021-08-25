#ifndef Collision_h
#define Collision_h

#include <SFML/Graphics.hpp>

class Collision {
private:
public:
	sf::RectangleShape col;
	bool Check(Collision& otherCol);
	Collision(const float x, const float y, const sf::Vector2f &pos) // Position as well!
	{
		col.setSize(sf::Vector2f(x, y));
		col.setOrigin(col.getSize().x/2, col.getSize().y/2);
		col.setFillColor(sf::Color(105,105,105,85));
		col.setPosition(pos.x, pos.y);
	}

	~Collision() {}
};

#endif
